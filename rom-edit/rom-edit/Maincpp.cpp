#include <iostream>
#include <fstream>
#include "Player.h"
#include "Helpers.h"
#include "ConstantsPlayer.h"

using namespace std;

int main(){
	FILE *tempRead;
	FILE* romRead;
	FILE* romWrite;
	int movingEmptyOffset = EMPTY_OFFSET;

	tempRead = fopen("D:\\OwnCloud\\Team95\\test.md", "rb");
	romWrite = fopen("D:\\OwnCloud\\Team95\\rom-edit.md", "wb");

	if (!tempRead || !romWrite){
		cout << "File could not be opened" << endl;
		return 0;
	}

	CopyFile(tempRead, romWrite);

	fclose(tempRead);

	romRead = fopen("D:\\OwnCloud\\Team95\\rom-edit.md", "rb");

	Player player1(romRead, romWrite, 0x00042410);
	player1.SetAttribute(PLAYER_NAME, "Brendan Murphy");
	cout << player1.GetName() << endl;
	/*player1.SetAttribute(PLAYER_NUMBER, 32);
	player1.SetAttribute(PLAYER_POSITION, 4);
	player1.SetAttribute(PLAYER_HEIGHT, 90);
	player1.SetAttribute(PLAYER_WEIGHT, 150);
	player1.SetAttribute(PLAYER_EXP, 10);
	player1.SetAttribute(PLAYER_UNIVERSITY, 2);
	player1.SetAttribute(PLAYER_SKINCOLOR, 3);
	player1.SetAttribute(PLAYER_HAIR, 0x24);
	player1.SetAttribute(PLAYER_S_GAMES, 0x1111);*/
	
	fclose(romRead);
	fclose(romWrite);
	return 0;
}