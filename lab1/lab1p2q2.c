#include <stdio.h>

// Function to sum two integers
void sum_two_ints() {
  // Declare two integer variables
  int first_int;
  int second_int;

  printf("Give two integers: ");// Prompt the user for two integers
  scanf("%d %d", &first_int, &second_int);// Read the two integers
  printf("You entered %d and %d, their sum is: %d\n", first_int, second_int, (first_int + second_int));// Print the sum of the two integers
}

// Function to multiply two floats
void product_two_floats() {
  // Declare two float variables
  float first_float;
  float second_float;

  printf("Give two floats: ");// Prompt the user for two floats
  scanf("%f %f", &first_float, &second_float);// Read the two floats
  printf("You entered %f and %f, their product is: %f\n", first_float, second_float, (first_float * second_float));// Print the product of the two floats
}

// Function to print a word twice
void print_word_twice() {
  // Declare a char array
  char word[100];

  
  printf("Give a word: ");// Prompt the user for a word
  scanf("%s", word);// Read the word
  printf("%s %s\n", word, word);// Print the word twice
}

int main() {
  // Call the three functions
  sum_two_ints();
  product_two_floats();
  print_word_twice();
}
