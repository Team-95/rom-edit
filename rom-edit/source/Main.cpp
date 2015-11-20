#include <iostream>
#include <fstream>
#include "Player.h"
#include "Team.h"
#include "Helpers.h"
#include "ConstantsPlayer.h"
#include "ConstantsTeam.h"

using namespace std;

int main(){
	FILE *tempRead;
	FILE* romRead;
	FILE* romWrite;
	int movingEmptyOffset = EMPTY_OFFSET;
	Team teams[27];

	tempRead = fopen("D:\\OwnCloud\\Team95\\test.md", "rb");
	romWrite = fopen("D:\\OwnCloud\\Team95\\rom-edit.md", "wb");

	if (!tempRead || !romWrite)
	{
		cout << "File could not be opened" << endl;
		return 0;
	}
	CopyFile(tempRead, romWrite);

	fclose(tempRead);

	romRead = fopen("D:\\OwnCloud\\Team95\\rom-edit.md", "rb");

	teams[0] = Team(romRead, romWrite, T_GOLDENSTATE, M_GOLDENSTATE);
	for (int i = 0; i < 16; i++)
	{
		unsigned int playerOffset;
		unsigned char * bytes = ReadRom(romRead, T_GOLDENSTATE + (4 * i), 4);
		playerOffset = BytesToInt(bytes);
		teams[0].SetPlayer(i, new Player(romRead, romWrite, playerOffset));
	}
	for (int i = 0; i < 16; i++)
	{
		cout << teams[0].GetPlayer(i)->GetName() << endl;
	}
	fclose(romRead);
	fclose(romWrite);
	int x;
	cin >> x;
	return 0;
}