#include <stdio.h>
#include <stdlib.h>

// Function to print a string
void string_output() {
  printf("One half is 50%%\n");
}

// Function to print the difference between two integers
void int_difference (int x, int y) {
  printf("The difference between %d and %d is %d\n", x, y, (x-y));
}

// Function to print the quotient of two floats
void divide_floats(float x, float y) {
  printf("%.6f / %.6f is %.6f\n", x, y, (x / y));
}

int main (void) {
  string_output();
  int_difference(10,3);
  divide_floats(1.0,3.0);
}
