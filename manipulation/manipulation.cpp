#include <stdio.h>
#include <cstring>

//Reversing a String: (This tests understanding of string manipulation and loops)
//Finding the Largest Number: (This tests basic conditional statements and loops)
//Checking for Prime Numbers: (This tests understanding of loops and divisibility rules)
//Swapping Two Variables: (This tests pointers or bitwise operations)
//Fibonacci Series: (This tests iterative approaches)

void sequence() {
  int i, j;
    // Loop for the number of rows (outer loop)
    for (i = 1; i <= 5; i++) {
        // Loop to print digits in each row (inner loop)
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");  // Move to the next line after each row
    }

    // Loop for the number of rows (outer loop)
    for (i = 5; i >= 0; i--) {
        // Loop to print digits in each row (inner loop)
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");  // Move to the next line after each row
    }
}

void reverse() {
  char str[]="Danny Boy";
  int len = strlen(str);
  int start = 0;
  int end = len - 1;

  printf("Original string: %s\n\n", str);
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
    printf("Reversing string: %s\n", str);
  }
  printf("\nReversed string: %s\n", str);
}

void largestNumber() {
  int largest=0;
  int Numbers[]={1,7,4};
  printf("\nNumbers:");
  for (int i = 0; i < 3; i++) {
    int current = Numbers[i];
    printf("%d ", current);  // Print current element with a space
  }
  for (int i = 0; i < 3; i++) {
      int current;
      //printf("Enter number %d: ", i);
      //scanf("%d", &current);
      current = Numbers[i];
      if (current > largest) {
          largest = current;
      }
  }  
  printf("The largest number is: %d\n", largest);
}

void isPrime() {
  int numbers[] = {1, 3, 7, 11, 21, 83};
  int size = sizeof(numbers) / sizeof(numbers[0]);
  int NoBreak;
  printf("\nPrime Numbers\n");
  for (int i = 0; i < size; i++) {
    int number = numbers[i];
    NoBreak=0;
    // Handle edge cases (0, 1, negative numbers)
    if (number <= 1) {
      printf("%d is not a prime number: (needs to have 2 factors, this must be 1)\n", number);
      continue; // Move to the next number in the array
    }

    // Efficiently check divisibility up to the square root of the number
    for (int j = 2; j * j <= number; j++) {
      if (number % j == 0) {
        printf("%d is not a prime number (divisible by something other than 1 and %d):", number, number);
        printf("in this case also %d (maybe other value too)\n", j);
        NoBreak = 1;
        break; // Exit the inner loop if not prime
      }
    }

    // If the inner loop completes without a break (no divisors found), it's prime
    if (!NoBreak) { // Use a flag or check for no break
      printf("%d is a prime number (divisible by 1 and %d only).\n", number, number);
    }
  }

  return; // Add semicolon after return
}

void Swap(){
  int num1=6, num2=8;

  printf("\nBefore swapping:\n");
  printf("num1 = %d\n", num1);
  printf("num2 = %d\n", num2);

  // Swap using XOR operation
  num1 = num1 ^ num2;
  num2 = num1 ^ num2;
  num1 = num1 ^ num2;

  printf("\nAfter XOR swapping:\n");
  printf("num1 = %d\n", num1);
  printf("num2 = %d\n", num2);

  // Swap Using Addition and Subtraction
  num1 = num1 + num2; // num1 becomes num1 + num2
  num2 = num1 - num2; // num2 becomes (num1 + num2) - num2 (which is num1)
  num1 = num1 - num2; // num1 becomes (num1 + num2) - (num1 - num2) (which is num2)

  printf("\nAfter Addition and Subtraction swapping:\n");
  printf("num1 = %d\n", num1);
  printf("num2 = %d\n", num2);
}

// Function for iterative approach
void fibonacci_iterative() {
  unsigned int a = 0, b = 1, c;
  unsigned int limit = 10; //it's enough
  printf("\nFibonacci Series: ");
  for (unsigned int i = 0; i < limit; i++) {
    printf("%d ", a);
    c = a + b;
    a = b;
    b = c;
  }
}

int main() {
  sequence();
  reverse();
  largestNumber();
  isPrime();
  Swap();
  fibonacci_iterative();
  return 0;
}

