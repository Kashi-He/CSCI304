#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to reverse a word and keep non-alphabetic characters in their original position
void reverseWord(char *word, int start, int end) {
    while (start < end) {
        if (isalpha(word[start]) && isalpha(word[end])) {
            // Swap alphabetic characters in uppercase
            char temp = toupper(word[start]);
            word[start] = toupper(word[end]);
            word[end] = temp;
            start++;
            end--;
        } else if (!isalpha(word[start])) {
            // Move to the next non-alphabetic character
            start++;
        } else if (!isalpha(word[end])) {
            // Move to the previous non-alphabetic character
            end--;
        }
    }
}

// Function to encode the message
void encodeMessage(char *message) {
    int length = strlen(message);
    int start = 0;

    for (int i = 0; i <= length; i++) {
        if (!isalpha(message[i]) || i == length) {
            // Found a non-alphabetic character or reached the end of the message
            reverseWord(message, start, i - 1);
            start = i + 1;
        }
    }

    // Replace underscores with spaces and convert all  characters to uppercase
    for (int i = 0; i < length; i++) {
        if (message[i] == '_') {
            message[i] = ' ';
        } else if (isalpha(message[i])) {
            message[i] = toupper(message[i]);
        }
    }
}

int main() {
    FILE *fin, *fout;
    fin = fopen("lab1p3in", "r");
    if (!fin) {
        printf("Input file does not exist.\n");
        return 0;
    }

    fout = fopen("lab1p3out", "w");
    if (!fout) {
        printf("Output file does not exist.\n");
        return 0;
    }

    char temp[100];

    while (fgets(temp, 100, fin) != NULL) {
        encodeMessage(temp);
        fprintf(fout, "%s", temp);
    }

    fclose(fin);
    fclose(fout);
    return 1;
}
