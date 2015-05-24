#pragma once

#include <stdio.h>
#include <iostream>
using namespace std;

// Return array of bytes read in from rom
unsigned char* ReadRom(FILE *rom, unsigned int offset, int amountOfBytes = 1);

// Writes array of bytes to rom
void WriteRom(FILE *rom, unsigned int offset, unsigned char* values, int amountOfBytes = 1);

// Converts byte array to a char, only neccasary for memory deletion
unsigned char BytesToChar(unsigned char* arr);

// Converts byte array to short
unsigned short BytesToShort(unsigned char* arr);

// Converts short to byte array
unsigned char* ShortToBytes(unsigned short val);

// Copies source rom to a new rom that can be read and written to
void CopyFile(FILE* source, FILE* dest);