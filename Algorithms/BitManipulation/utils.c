#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* toBinary(int value) {
    // Determine the number of bits needed to represent the integer
    int numBits = (sizeof(int) * 8);

    // Allocate memory to store the binary representation as a string
    char* binaryStr = (char*)malloc(numBits + (numBits / 8) + 3); // +3 for '0b' prefix, spaces, and the null-terminator

    // Check if memory allocation was successful
    if (binaryStr == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    // Add '0b' prefix
    strcpy(binaryStr, "0b");

    // Convert the integer to binary representation
    int mask = 1 << (numBits - 1);
    int bitCount = 0;
    int index = 2;
    for (int i = 0; i < numBits; i++) {
        binaryStr[index++] = (value & mask) ? '1' : '0';
        value <<= 1;
        bitCount++;
        // Add a space after every 8 characters
        if (bitCount == 8 && i < numBits - 1) {
            binaryStr[index++] = ' ';
            bitCount = 0;
        }
    }

    // Null-terminate the string
    binaryStr[index] = '\0';

    return binaryStr;
}
