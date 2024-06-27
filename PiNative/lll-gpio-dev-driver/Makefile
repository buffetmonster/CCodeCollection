obj-m += lll-gpio-driver.o

KDIR = /lib/modules/$(shell uname -r)/build

all:
	make -C $(KDIR) M=$(shell pwd) modules
	gcc user-mode-program/blink-led.c -o user-mode-program/blink-led
	gcc user-mode-program/read-message.c -o user-mode-program/read-message

clean:
	make -C $(KDIR) M=$(shell pwd) clean
	rm -f user-mode-program/blink-led
	rm -f user-mode-program/read-message
