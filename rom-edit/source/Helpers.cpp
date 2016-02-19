#include "Helpers.h"
#include "ConstantsTeam.h"
#include <string>

unsigned char* ReadRom(FILE *rom, unsigned int offset, int amountOfBytes) 
{
	unsigned char * bytes = new unsigned char[30];
	fseek(rom, offset, SEEK_SET);
	for (int i = 0; i < amountOfBytes; i++)
	{
		bytes[i] = fgetc(rom);
	}

	return bytes;
}

void WriteRom(FILE *rom, unsigned int offset, unsigned char* values, int amountOfBytes )
{
	fseek(rom, offset, SEEK_SET);
	for (int i = 0; i < amountOfBytes; i++){
		fputc(values[i], rom);
	}
}

unsigned char BytesToChar (unsigned char* arr)
{
	unsigned char temp = arr[0];
	delete arr;				// was created by ReadFromRom
	return temp;
}

unsigned short BytesToShort(unsigned char* arr)
{
	unsigned short byte1 = arr[0];
	unsigned short byte2 = arr[1];
	
	delete arr;
	return (byte1 << 8) | byte2;
}

unsigned int BytesToInt(unsigned char* arr)
{
	unsigned int byte1 = arr[0];
	unsigned int byte2 = arr[1];
	unsigned int byte3 = arr[2];
	unsigned int byte4 = arr[3];

	delete arr;
	return (byte1 << 24) | (byte2 << 16) | (byte3 << 8) | (byte4);
}

unsigned char* ShortToBytes(unsigned short val)
{
	unsigned char * bytes = new unsigned char[2];
	bytes[0] = val >> 8;
	bytes[1] = val & 0x00ff;
	return bytes;
}

unsigned char* IntToBytes(unsigned int val)
{
	unsigned char * bytes = new unsigned char[4];
	bytes[0] = val >> 24;
	bytes[1] = val >> 16;
	bytes[2] = val >> 8;
	bytes[3] = val & 0x000000ff;
		
	return bytes;
}

unsigned char StringToChar(string s)
{
	int value = atoi(s.c_str());
	return value;
}

unsigned short StringToShort(string s)
{
	int value = atoi(s.c_str());
	return value;
}

void CopyFile(FILE* source, FILE* dest)
{
	int ch;
	while ((ch = fgetc(source)) != EOF)
		fputc(ch, dest);
}

void TeamOffsetsFromAbbreviation(string cellVal, unsigned int &teamOffset, unsigned int &menuOffset)
{
	if (cellVal == "HOU")
	{
		teamOffset = T_HOUSTON;
		menuOffset = M_HOUSTON;
	}
	else if (cellVal == "ATL")
	{
		teamOffset = T_ATLANTA;
		menuOffset = M_ATLANTA;
	}
	else if (cellVal == "BOS")
	{
		teamOffset = T_BOSTON;
		menuOffset = M_BOSTON;
	}
	else if (cellVal == "BRK")
	{
		teamOffset = T_NEWJERSEY;
		menuOffset = M_NEWJERSEY;
	}
	else if (cellVal == "CHI")
	{
		teamOffset = T_CHICAGO;
		menuOffset = M_CHICAGO;
	}
	else if (cellVal == "CHO")
	{
		teamOffset = T_CHARLOTTE;
		menuOffset = M_CHARLOTTE;
	}
	else if (cellVal == "CLE")
	{
		teamOffset = T_CLEVELAND;
		menuOffset = M_CLEVELAND;
	}
	else if (cellVal == "DAL")
	{
		teamOffset = T_DALLAS;
		menuOffset = M_DALLAS;
	}
	else if (cellVal == "DEN")
	{
		teamOffset = T_DENVER;
		menuOffset = M_DENVER;
	}
	else if (cellVal == "DET")
	{
		teamOffset = T_DETROIT;
		menuOffset = M_DETROIT;
	}
	else if (cellVal == "GSW")
	{
		teamOffset = T_GOLDENSTATE;
		menuOffset = M_GOLDENSTATE;
	}
	else if (cellVal == "IND")
	{
		teamOffset = T_INDIANA;
		menuOffset = M_INDIANA;
	}
	else if (cellVal == "LAC")
	{
		teamOffset = T_LAC;
		menuOffset = M_LAC;
	}
	else if (cellVal == "LAL")
	{
		teamOffset = T_LAL;
		menuOffset = M_LAL;
	}
	else if (cellVal == "MEM")
	{
		teamOffset = T_STARSWEST;
		menuOffset = M_STARSWEST;
	}
	else if (cellVal == "MIA")
	{
		teamOffset = T_MIAMI;
		menuOffset = M_MIAMI;
	}
	else if (cellVal == "MIL")
	{
		teamOffset = T_MILWAUKEE;
		menuOffset = M_MILWAUKEE;
	}
	else if (cellVal == "MIN")
	{
		teamOffset = T_MINNESOTA;
		menuOffset = M_MINNESOTA;
	}
	else if (cellVal == "NOP")
	{
		//teamOffset = T_STARSEAST;
		//menuOffset = M_STARSEAST;
	}
	else if (cellVal == "NYK")
	{
		teamOffset = T_NEWYORK;
		menuOffset = M_NEWYORK;
	}
	else if (cellVal == "OKC")
	{
		teamOffset = T_SEATTLE;
		menuOffset = M_SEATTLE;
	}
	else if (cellVal == "ORL")
	{
		teamOffset = T_ORLANDO;
		menuOffset = M_ORLANDO;
	}
	else if (cellVal == "PHI")
	{
		teamOffset = T_PHILADELPHIA;
		menuOffset = M_PHILADELPHIA;
	}
	else if (cellVal == "PHO")
	{
		teamOffset = T_PHOENIX;
		menuOffset = M_PHOENIX;
	}
	else if (cellVal == "POR")
	{
		teamOffset = T_PORTLAND;
		menuOffset = M_PORTLAND;
	}
	else if (cellVal == "SAC")
	{
		teamOffset = T_SACRAMENTO;
		menuOffset = M_SACRAMENTO;
	}
	else if (cellVal == "SAS")
	{
		teamOffset = T_SANANTONIO;
		menuOffset = M_SANANTONIO;
	}
	else if (cellVal == "TOR")
	{
		teamOffset = T_STARSEAST;
		menuOffset = M_STARSEAST;
	}
	else if (cellVal == "UTA")
	{
		teamOffset = T_UTAH;
		menuOffset = M_UTAH;
	}
	else if (cellVal == "WAS")
	{
		teamOffset = T_WASHINGTON;
		menuOffset = M_WASHINGTON;
	}
}