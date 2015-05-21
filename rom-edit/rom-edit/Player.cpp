#include "Player.h"
#include "Helpers.h"

Player::Player(FILE *file, int &off){ // New Player
	playerOffset = off;
	rom = file;
	off += PLAYER_SIZE;	

	university = 1;
	experience = skinColor = hair = number = position = 0;
	height = 67;
	weight = 80;
	sGames = sMinutes = sMadeGoals = sAttemptedGoals = sMadeThrees = sAttemptedThrees = sMadeFreeThrows = sAttemptedFreeThrows = 0;
	sOffRebounds = sRebounds = sAssists = sSteals = sTurnovers = sBlocks = sPoints = sFouledOut = sFouls = 0;
	rGoals = rThrees = rFreeThrows = rDunking = rStealing = rBlocks = rOffRebounding = rDefRebounding = rPassing = 0;
	rOffAwareness = rDefAwareness = rSpeed = rQuickness = rJumping = rDribling = rStrength = 0;
}

Player::Player(FILE *file, int off){
	

	playerOffset = off;
	rom = file;

	BytesToChar(experience, ReadRom(rom, playerOffset + PLAYER_EXP));
	BytesToChar(university, ReadRom(rom, playerOffset + PLAYER_UNIVERSITY));
	BytesToChar(skinColor, ReadRom(rom, playerOffset + PLAYER_SKINCOLOR));
	BytesToChar(hair, ReadRom(rom, playerOffset + PLAYER_HAIR));

	// Get Season stats from rom and store in variables
	BytesToChar(number, ReadRom(rom, playerOffset + PLAYER_NUMBER));
	BytesToChar(position, ReadRom(rom, playerOffset + PLAYER_POSITION));
	BytesToChar(height, ReadRom(rom, playerOffset + PLAYER_HEIGHT));
	BytesToChar(weight, ReadRom(rom, playerOffset + PLAYER_WEIGHT));

	BytesToShort(sGames, ReadRom(rom, playerOffset + PLAYER_S_GAMES)); 
	BytesToShort(sMinutes, ReadRom(rom, playerOffset + PLAYER_S_MINUTES));
	BytesToShort(sMadeGoals, ReadRom(rom, playerOffset + PLAYER_S_MADEGOALS)); 
	BytesToShort(sAttemptedGoals, ReadRom(rom, playerOffset + PLAYER_S_ATTEMPTEDGOALS));
	BytesToShort(sMadeThrees, ReadRom(rom, playerOffset + PLAYER_S_MADETHREES));
	BytesToShort(sAttemptedThrees, ReadRom(rom, playerOffset + PLAYER_S_ATTEMPTEDTHREES));
	BytesToShort(sMadeFreeThrows, ReadRom(rom, playerOffset + PLAYER_S_MADEFREETHROWS));
	BytesToShort(sAttemptedFreeThrows, ReadRom(rom, playerOffset + PLAYER_S_ATTEMPTEDFREETHROWS));
	BytesToShort(sOffRebounds, ReadRom(rom, playerOffset + PLAYER_S_OFFREBOUNDS));
	BytesToShort(sRebounds, ReadRom(rom, playerOffset + PLAYER_S_REBOUNDS));
	BytesToShort(sAssists, ReadRom(rom, playerOffset + PLAYER_S_ASSISTS));
	BytesToShort(sSteals, ReadRom(rom, playerOffset + PLAYER_S_STEALS));
	BytesToShort(sTurnovers, ReadRom(rom, playerOffset + PLAYER_S_TURNOVERS));
	BytesToShort(sBlocks, ReadRom(rom, playerOffset + PLAYER_S_BLOCKS));
	BytesToShort(sPoints, ReadRom(rom, playerOffset + PLAYER_S_POINTS));
	BytesToShort(sFouledOut, ReadRom(rom, playerOffset + PLAYER_S_FOULEDOUT));
	BytesToShort(sFouls, ReadRom(rom, playerOffset + PLAYER_S_FOULS));

	// Get rating stats and store in file
	BytesToChar(rGoals, ReadRom(rom, playerOffset + PLAYER_R_GOALS));
	BytesToChar(rThrees, ReadRom(rom, playerOffset + PLAYER_R_THREES));
	BytesToChar(rFreeThrows, ReadRom(rom, playerOffset + PLAYER_R_FREETHROW));
	BytesToChar(rDunking, ReadRom(rom, playerOffset + PLAYER_R_DUNKING));
	BytesToChar(rStealing, ReadRom(rom, playerOffset + PLAYER_R_STEALING));
	BytesToChar(rBlocks, ReadRom(rom, playerOffset + PLAYER_R_BLOCKS));
	BytesToChar(rOffRebounding, ReadRom(rom, playerOffset + PLAYER_R_OFFREBOUNDING));
	BytesToChar(rDefRebounding, ReadRom(rom, playerOffset + PLAYER_R_DEFREBOUNDING));
	BytesToChar(rPassing, ReadRom(rom, playerOffset + PLAYER_R_PASSING));
	BytesToChar(rOffAwareness, ReadRom(rom, playerOffset + PLAYER_R_OFFAWARENESS));
	BytesToChar(rDefAwareness, ReadRom(rom, playerOffset + PLAYER_R_DEFAWARENESS));
	BytesToChar(rSpeed, ReadRom(rom, playerOffset + PLAYER_R_SPEED));
	BytesToChar(rQuickness, ReadRom(rom, playerOffset + PLAYER_R_QUICKNESS));
	BytesToChar(rJumping, ReadRom(rom, playerOffset + PLAYER_R_JUMPING));
	BytesToChar(rDribling, ReadRom(rom, playerOffset + PLAYER_R_DRIBLING));
	BytesToChar(rStrength, ReadRom(rom, playerOffset + PLAYER_R_STRENGTH));
	
	
}

unsigned int Player::GetOffset(){ return playerOffset; }

