#include <iostream>
#include <fstream>
#include "Player.h"
#include "ConstantsPlayer.h"

using namespace std;

int main(){
	FILE *file;
	long movingEmptyOffset = EMPTY_OFFSET;

	file = fopen("D:\\OwnCloud\\Team95\\rom-edit.md", "a+b");
	
	Player player1(file, 0x00042410);

	
	return 0;
}