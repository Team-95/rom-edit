#include <stdio.h>
using namespace std;

unsigned char* ReadFromRom(FILE *rom, unsigned long offset, char amountOfBytes){
	unsigned char * bytes = new unsigned char[10]; 
	fseek(rom, offset, SEEK_SET);
	for (int i = 0; i < amountOfBytes; i++){
		bytes[i] = fgetc(rom);
		char test = bytes[i];
	}
	unsigned char test1 = bytes[0];
	unsigned char test2 = bytes[1];

	return bytes;
}