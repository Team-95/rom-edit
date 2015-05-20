#include "Player.h"

Player::Player(FILE *file, long &off){
	playerOffset = off;
	rom = file;
	off += PLAYER_SIZE;	
}

Player::Player(FILE *file, long off){
	

	offset = off;
	rom = file;

	GetValueFromRom(experience, PLAYER_EXP);
	GetValueFromRom(university, PLAYER_UNIVERSITY);
	GetValueFromRom(skinColor, PLAYER_SKINCOLOR);
	GetValueFromRom(hair, PLAYER_HAIR);

	// Get Season stats from rom and store in variables
	GetValueFromRom(number, PLAYER_NUMBER);
	GetValueFromRom(position, PLAYER_POSITION);
	GetValueFromRom(height, PLAYER_HEIGHT);
	GetValueFromRom(weight, PLAYER_WEIGHT);

	GetValueFromRom(sGames, PLAYER_SEASON_GAMES); // works
	GetValueFromRom(sMinutes, PLAYER_SEASON_MINUTES);
	GetValueFromRom(sMadeGoals, PLAYER_SEASON_MADEGOALS); // works
	GetValueFromRom(sAttemptedGoals, PLAYER_SEASON_ATTEMPTEDGOALS);
	GetValueFromRom(sMadeThrees, PLAYER_SEASON_MADETHREES);
	GetValueFromRom(sAttemptedThrees, PLAYER_SEASON_ATTEMPTEDTHREES);
	GetValueFromRom(sMadeFreeThrows, PLAYER_SEASON_MADEFREETHROWS);
	GetValueFromRom(sAttemptedFreeThrows, PLAYER_SEASON_ATTEMPTEDFREETHROWS);
	GetValueFromRom(sOffRebounds, PLAYER_SEASON_OFFREBOUNDS);
	GetValueFromRom(sRebounds, PLAYER_SEASON_REBOUNDS);
	GetValueFromRom(sAssists, PLAYER_SEASON_ASSISTS);
	GetValueFromRom(sSteals, PLAYER_SEASON_STEALS);
	GetValueFromRom(sTurnovers, PLAYER_SEASON_TURNOVERS);
	GetValueFromRom(sBlocks, PLAYER_SEASON_BLOCKS);
	GetValueFromRom(sPoints, PLAYER_SEASON_POINTS);
	GetValueFromRom(sFouledOut, PLAYER_SEASON_FOULEDOUT);
	GetValueFromRom(sFouls, PLAYER_SEASON_FOULS);

	// Get rating stats and store in file
	GetValueFromRom(rGoals, PLAYER_RATING_GOALS);
	GetValueFromRom(rThrees, PLAYER_RATING_THREES);
	GetValueFromRom(rFreeThrows, PLAYER_RATING_FREETHROW);
	GetValueFromRom(rDunking, PLAYER_RATING_DUNKING);
	GetValueFromRom(rStealing, PLAYER_RATING_STEALING);
	GetValueFromRom(rBlocks, PLAYER_RATING_BLOCKS);
	GetValueFromRom(rOffRebounding, PLAYER_RATING_OFFREBOUNDING);
	GetValueFromRom(rDefRebounding, PLAYER_RATING_DEFREBOUNDING);
	GetValueFromRom(rPassing, PLAYER_RATING_PASSING);
	GetValueFromRom(rOffAwareness, PLAYER_RATING_OFFAWARENESS);
	GetValueFromRom(rDefAwareness, PLAYER_RATING_DEFAWARENESS);
	GetValueFromRom(rSpeed, PLAYER_RATING_SPEED);
	GetValueFromRom(rQuickness, PLAYER_RATING_QUICKNESS);
	GetValueFromRom(rJumping, PLAYER_RATING_JUMPING);
	GetValueFromRom(rDribling, PLAYER_RATING_DRIBLING);
	GetValueFromRom(rStrength, PLAYER_RATING_STRENGTH);
	
}

unsigned long Player::GetOffset(){ return playerOffset; }

void Player::GetValueFromRom(unsigned char &val, unsigned long valueOffset, bool output){
	unsigned char* byte = ReadFromRom(rom, playerOffset + valueOffset, 1);
	val = byte[0];
	if (output) cout << int(val) << endl;
	delete byte;
}

void Player::GetValueFromRom(char16_t &val, unsigned long valueOffset, bool output){
	unsigned char* byte = ReadFromRom(rom, playerOffset + valueOffset, 2);
	unsigned short byte1 = byte[0];
	unsigned short byte2 = byte[1];

	val = (byte1 << 8)| byte2;
	if (output) cout << int(val) << endl;
	delete byte;
}

void Player::GetValueFromRom(unsigned char arr[30], unsigned long off, bool output){
	//arr = ReadFromRom(off, 2);
	//val = (char16_t(byte[0]) << 8) + byte[1];
	//if (output) cout << int(val) << endl;
	//delete byte;
}
