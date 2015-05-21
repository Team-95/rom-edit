#pragma once

#include <stdio.h>
#include <iostream>
using namespace std;

// Return array of bytes read in from rom
unsigned char* ReadRom(FILE *rom, unsigned int offset, int amountOfBytes = 1);

// Writes array of bytes to rom
void WriteRom(FILE *rom, unsigned int offset, unsigned char* values, int amountOfBytes );

void BytesToChar(unsigned char &value, unsigned char* arr);
void BytesToShort(unsigned short &value, unsigned char* arr);