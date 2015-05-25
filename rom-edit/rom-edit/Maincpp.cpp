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
	player1.SetName("Brendan Murphy");
	cout << player1.GetName() << endl;
	
	fclose(romRead);
	fclose(romWrite);
	return 0;
}