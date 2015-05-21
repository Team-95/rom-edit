#include "Helpers.h"

unsigned char* ReadRom(FILE *rom, unsigned int offset, int amountOfBytes) {
	unsigned char * bytes = new unsigned char[10];
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

void BytesToChar (unsigned char &toAssign, unsigned char* arr){

	toAssign = arr[0];
	cout << int(toAssign) << endl;
	delete arr;				// was created by ReadFromRom
}

void BytesToShort(unsigned short &value, unsigned char* arr){
	unsigned short byte1 = arr[0];
	unsigned short byte2 = arr[1];
	
	value = (byte1 << 8) | byte2;
}

