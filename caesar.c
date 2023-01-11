#include <stdio.h>

#define SMALL_ALPHABET_START 65
#define SMALL_ALPHABET_END 90
#define BIG_ALPHABET_START 97
#define BIG_ALPHABET_END 122

/// Shift a letter using ASCII table
/// @param c is the letter to shift
/// @param start is the start of an alphabet
/// @param end is the end of an alphabet
/// @param shiftAmount is the value by which the letter will be shifted
void shift(int start, int end, int shiftAmount, char c){
    if(c >= start && c <= end){
        if(c > (end - shiftAmount)){  // If it crosses 'z' it has to start shifting from 'a'
            c = start + (c - (end - shiftAmount) - 1);
        }
        else{
            c += shiftAmount;  // If it doesn't cross 'z' the letters get shifted by 'shiftAmount'
        }
    }
    printf("%c", c);  // Prints every letter immediately
}

int main() {
    int shiftAmount = 5;
    char c;

    printf("Type a sentence:\n");

    while((c = fgetc(stdin)) != '\n'){  // Reads the input char by char
        if(c >= SMALL_ALPHABET_START && c <= SMALL_ALPHABET_END){  // Shifts the letter in the small alphabet
            shift(SMALL_ALPHABET_START, SMALL_ALPHABET_END, shiftAmount, c);
        }
        else if(c >= BIG_ALPHABET_START && c <= BIG_ALPHABET_END){  // Shifts the letter in the big alphabet
            shift(BIG_ALPHABET_START, BIG_ALPHABET_END, shiftAmount, c);
        }
        else{
            printf("%c", c);  // In case of a space, an apostrophe or any other character it prints it out
        }
    }
    return 0;
}
