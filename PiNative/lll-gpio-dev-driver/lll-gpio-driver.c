#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/cdev.h>
#include <linux/device.h>

#define DEVICE_NAME "lll-gpio"
#define CLASS_NAME "lll"
#define LLL_MAX_USER_SIZE 1024

#define BCM2837_GPIO_ADDRESS 0x3F200000
#define BCM2711_GPIO_ADDRESS 0xfe200000

#define IOCTL_SET_PIN _IOW('a', 1, int32_t*)
#define IOCTL_SET_VALUE _IOW('a', 2, int32_t*)

static dev_t dev_num;
static struct cdev lll_cdev;
static struct class *lll_class = NULL;
static struct device *lll_device = NULL;

static unsigned int *gpio_registers = NULL;
static int32_t pin = 0;
static int32_t value = 0;

static void gpio_pin_on(unsigned int pin)
{
    unsigned int fsel_index = pin / 10;
    unsigned int fsel_bitpos = pin % 10;
    unsigned int *gpio_fsel = gpio_registers + fsel_index;
    unsigned int *gpio_on_register = (unsigned int*)((char*)gpio_registers + 0x1c);

    *gpio_fsel &= ~(7 << (fsel_bitpos * 3));
    *gpio_fsel |= (1 << (fsel_bitpos * 3));
    *gpio_on_register |= (1 << pin);

    return;
}

static void gpio_pin_off(unsigned int pin)
{
    unsigned int *gpio_off_register = (unsigned int*)((char*)gpio_registers + 0x28);
    *gpio_off_register |= (1 << pin);
    return;
}

static long lll_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    switch (cmd) {
        case IOCTL_SET_PIN:
            if (copy_from_user(&pin, (int32_t*)arg, sizeof(pin))) {
                printk("Failed to copy pin from user\n");
                return -EFAULT;
            }
            if (pin > 21 || pin < 0) {
                printk("Invalid pin number submitted\n");
                return -EINVAL;
            }
            printk("You configured pin %d\n", pin);
            break;
        case IOCTL_SET_VALUE:
            if (copy_from_user(&value, (int32_t*)arg, sizeof(value))) {
                printk("Failed to copy value from user\n");
                return -EFAULT;
            }
            if (value != 0 && value != 1) {
                printk("Invalid on/off value\n");
                return -EINVAL;
            }
            if (value == 1) {
                gpio_pin_on(pin);
                printk("You set gpio_pin_on: pin %d, value %d\n", pin, value);
            } else if (value == 0) {
                gpio_pin_off(pin);
                printk("You set gpio_pin_off: pin %d, value %d\n", pin, value);
            }
            break;
        default:
            return -EINVAL;
    }
    return 0;
}

static int lll_open(struct inode *inode, struct file *file)
{
    return 0;
}

static int lll_release(struct inode *inode, struct file *file)
{
    return 0;
}

static const struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = lll_open,
    .release = lll_release,
    .unlocked_ioctl = lll_ioctl,
};

static int __init gpio_driver_init(void)
{
    printk("Welcome to my driver!\n");

    gpio_registers = (int*)ioremap(BCM2837_GPIO_ADDRESS, PAGE_SIZE);
    if (gpio_registers == NULL) {
        printk("Failed to map GPIO memory to driver\n");
        return -1;
    }

    printk("Successfully mapped in GPIO memory\n");

    if (alloc_chrdev_region(&dev_num, 0, 1, DEVICE_NAME) < 0) {
        printk("Failed to allocate a major number\n");
        iounmap(gpio_registers);
        return -1;
    }

    cdev_init(&lll_cdev, &fops);
    if (cdev_add(&lll_cdev, dev_num, 1) < 0) {
        printk("Failed to add the device to the system\n");
        unregister_chrdev_region(dev_num, 1);
        iounmap(gpio_registers);
        return -1;
    }

    lll_class = class_create(CLASS_NAME);
    if (IS_ERR(lll_class)) {
        printk("Failed to create the device class\n");
        cdev_del(&lll_cdev);
        unregister_chrdev_region(dev_num, 1);
        iounmap(gpio_registers);
        return PTR_ERR(lll_class);
    }

    lll_device = device_create(lll_class, NULL, dev_num, NULL, DEVICE_NAME);
    if (IS_ERR(lll_device)) {
        printk("Failed to create the device\n");
        class_destroy(lll_class);
        cdev_del(&lll_cdev);
        unregister_chrdev_region(dev_num, 1);
        iounmap(gpio_registers);
        return PTR_ERR(lll_device);
    }

    return 0;
}

static void __exit gpio_driver_exit(void)
{
    printk("Leaving my driver!\n");
    iounmap(gpio_registers);
    device_destroy(lll_class, dev_num);
    class_unregister(lll_class);
    class_destroy(lll_class);
    cdev_del(&lll_cdev);
    unregister_chrdev_region(dev_num, 1);
    return;
}

module_init(gpio_driver_init);
module_exit(gpio_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Low Level Learning");
MODULE_DESCRIPTION("Test of writing drivers for RASPI");
MODULE_VERSION("1.0");
