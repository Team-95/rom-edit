#include "Helpers.h"

unsigned char* ReadRom(FILE *rom, unsigned int offset, int amountOfBytes) {
	unsigned char * bytes = new unsigned char[30];
	fseek(rom, offset, SEEK_SET);
	for (int i = 0; i < amountOfBytes; i++){
		bytes[i] = fgetc(rom);
	}

	return bytes;
}

void WriteRom(FILE *rom, unsigned int offset, unsigned char* values, int amountOfBytes ){
	fseek(rom, offset, SEEK_SET);
	for (int i = 0; i < amountOfBytes; i++){
		fputc(values[i], rom);
	}
}

unsigned char BytesToChar (unsigned char* arr){

	return arr[0];
	delete arr;				// was created by ReadFromRom
}

unsigned short BytesToShort(unsigned char* arr){
	unsigned short byte1 = arr[0];
	unsigned short byte2 = arr[1];
	
	return (byte1 << 8) | byte2;
	delete arr;
}

unsigned char* ShortToBytes(unsigned short val){
	unsigned char * bytes = new unsigned char[2];
	bytes[0] = val >> 8;
	bytes[1] = val & 0x00ff;
	return bytes;
}

void CopyFile(FILE* source, FILE* dest){
	int ch;
	while ((ch = fgetc(source)) != EOF)
		fputc(ch, dest);
}