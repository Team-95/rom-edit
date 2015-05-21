#include <iostream>
#include <fstream>
#include <string>
#include "ConstantsPlayer.h"

using namespace std;

class Player{

public:
	// Each player will take up 93 bytes on the ROM
	// 69 before name, 21 for name, 3 for closing 00s
	Player(FILE *rom, int &off);	// For new players
	Player(FILE *rom, int off);	// For existing players

	void WriteFromCSV(string vals[40]);


private:
	FILE *rom;
	unsigned int playerOffset;

	unsigned int GetOffset();

	// Fields about player
	unsigned char number;
	unsigned char position;
	unsigned char height;
	unsigned char weight;
	unsigned char experience;
	unsigned char university;
	unsigned char skinColor;
	unsigned char hair;

	unsigned short sGames;
	unsigned short sMinutes;
	unsigned short sMadeGoals;
	unsigned short sAttemptedGoals;
	unsigned short sMadeThrees;
	unsigned short sAttemptedThrees;
	unsigned short sMadeFreeThrows;
	unsigned short sAttemptedFreeThrows;
	unsigned short sOffRebounds;
	unsigned short sRebounds;
	unsigned short sAssists;
	unsigned short sSteals;
	unsigned short sTurnovers;
	unsigned short sBlocks;
	unsigned short sPoints;
	unsigned short sFouledOut;
	unsigned short sFouls;
	
	unsigned char rGoals;
	unsigned char rThrees;
	unsigned char rFreeThrows;
	unsigned char rDunking;
	unsigned char rStealing;
	unsigned char rBlocks;
	unsigned char rOffRebounding;
	unsigned char rDefRebounding;
	unsigned char rPassing;
	unsigned char rOffAwareness;
	unsigned char rDefAwareness;
	unsigned char rSpeed;
	unsigned char rQuickness;
	unsigned char rJumping;
	unsigned char rDribling;
	unsigned char rStrength;

	unsigned char name[30];

};