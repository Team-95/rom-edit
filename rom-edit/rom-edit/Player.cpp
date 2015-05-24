#include "Player.h"
#include "Helpers.h"

Player::Player(FILE *romR, FILE* romW, int &off){ // New Player
	playerOffset = off;
	romRead = romR;
	romWrite = romW;
	off += PLAYER_SIZE;	

	university = 1;
	experience = skinColor = hair = number = position = 0;
	height = 67;
	weight = 80;
	sGames = sMinutes = sMadeGoals = sAttemptedGoals = sMadeThrees = sAttemptedThrees = sMadeFreeThrows = sAttemptedFreeThrows = 0;
	sOffRebounds = sRebounds = sAssists = sSteals = sTurnovers = sBlocks = sPoints = sFouledOut = sFouls = 0;
	rGoals = rThrees = rFreeThrows = rDunking = rStealing = rBlocks = rOffRebounding = rDefRebounding = rPassing = 75;
	rOffAwareness = rDefAwareness = rSpeed = rQuickness = rJumping = rDribling = rStrength = 75;
}

Player::Player(FILE *romR, FILE* romW, int off){

	playerOffset = off;
	romRead = romR;
	romWrite = romW;

	nameSize = 0;

	// Get the length of the name
	fseek(romR, playerOffset + PLAYER_NAME, SEEK_SET);
	int zeroCount = 0;
	int ch;

	do{
		nameSize++;
		ch = fgetc(romRead);
		if (ch == 0)
			zeroCount++;
	} while (zeroCount < 2);
	nameSize--;

	// Set name to what is on the ROM
	name = ReadRom(romRead, playerOffset + PLAYER_NAME, nameSize);
	// Set values after name to 0
	for (int i = nameSize; i < 30; i++){
		name[i] = 0;
	}

	experience = BytesToChar(ReadRom(romRead, playerOffset + PLAYER_EXP));
	university = BytesToChar(ReadRom(romRead, playerOffset + PLAYER_UNIVERSITY));
	skinColor = BytesToChar(ReadRom(romRead, playerOffset + PLAYER_SKINCOLOR));
	hair = BytesToChar( ReadRom(romRead, playerOffset + PLAYER_HAIR));

	// Get Season stats fromRead romRead and store in variables
	number = BytesToChar(ReadRom(romRead, playerOffset + PLAYER_NUMBER));
	position = BytesToChar(ReadRom(romRead, playerOffset + PLAYER_POSITION));
	height = BytesToChar(ReadRom(romRead, playerOffset + PLAYER_HEIGHT));
	weight = BytesToChar(ReadRom(romRead, playerOffset + PLAYER_WEIGHT));

	sGames = BytesToShort(ReadRom(romRead, playerOffset + PLAYER_S_GAMES)); 
	sMinutes = BytesToShort(ReadRom(romRead, playerOffset + PLAYER_S_MINUTES));
	sMadeGoals = BytesToShort(ReadRom(romRead, playerOffset + PLAYER_S_MADEGOALS)); 
	sAttemptedGoals = BytesToShort(ReadRom(romRead, playerOffset + PLAYER_S_ATTEMPTEDGOALS));
	sMadeThrees = BytesToShort(ReadRom(romRead, playerOffset + PLAYER_S_MADETHREES));
	sAttemptedThrees = BytesToShort(ReadRom(romRead, playerOffset + PLAYER_S_ATTEMPTEDTHREES));
	sMadeFreeThrows = BytesToShort(ReadRom(romRead, playerOffset + PLAYER_S_MADEFREETHROWS));
	sAttemptedFreeThrows = BytesToShort(ReadRom(romRead, playerOffset + PLAYER_S_ATTEMPTEDFREETHROWS));
	sOffRebounds = BytesToShort(ReadRom(romRead, playerOffset + PLAYER_S_OFFREBOUNDS));
	sRebounds = BytesToShort(ReadRom(romRead, playerOffset + PLAYER_S_REBOUNDS));
	sAssists = BytesToShort(ReadRom(romRead, playerOffset + PLAYER_S_ASSISTS));
	sSteals = BytesToShort(ReadRom(romRead, playerOffset + PLAYER_S_STEALS));
	sTurnovers = BytesToShort(ReadRom(romRead, playerOffset + PLAYER_S_TURNOVERS));
	sBlocks = BytesToShort(ReadRom(romRead, playerOffset + PLAYER_S_BLOCKS));
	sPoints = BytesToShort(ReadRom(romRead, playerOffset + PLAYER_S_POINTS));
	sFouledOut = BytesToShort(ReadRom(romRead, playerOffset + PLAYER_S_FOULEDOUT));
	sFouls = BytesToShort(ReadRom(romRead, playerOffset + PLAYER_S_FOULS));

	// Get rating stats and store in file
	rGoals = BytesToChar(ReadRom(romRead, playerOffset + PLAYER_R_GOALS));
	rThrees = BytesToChar(ReadRom(romRead, playerOffset + PLAYER_R_THREES));
	rFreeThrows = BytesToChar(ReadRom(romRead, playerOffset + PLAYER_R_FREETHROW));
	rDunking = BytesToChar(ReadRom(romRead, playerOffset + PLAYER_R_DUNKING));
	rStealing = BytesToChar(ReadRom(romRead, playerOffset + PLAYER_R_STEALING));
	rBlocks = BytesToChar(ReadRom(romRead, playerOffset + PLAYER_R_BLOCKS));
	rOffRebounding = BytesToChar(ReadRom(romRead, playerOffset + PLAYER_R_OFFREBOUNDING));
	rDefRebounding = BytesToChar(ReadRom(romRead, playerOffset + PLAYER_R_DEFREBOUNDING));
	rPassing = BytesToChar(ReadRom(romRead, playerOffset + PLAYER_R_PASSING));
	rOffAwareness = BytesToChar(ReadRom(romRead, playerOffset + PLAYER_R_OFFAWARENESS));
	rDefAwareness = BytesToChar(ReadRom(romRead, playerOffset + PLAYER_R_DEFAWARENESS));
	rSpeed= BytesToChar(ReadRom(romRead, playerOffset + PLAYER_R_SPEED));
	rQuickness = BytesToChar(ReadRom(romRead, playerOffset + PLAYER_R_QUICKNESS));
	rJumping = BytesToChar(ReadRom(romRead, playerOffset + PLAYER_R_JUMPING));
	rDribling = BytesToChar(ReadRom(romRead, playerOffset + PLAYER_R_DRIBLING));
	rStrength = BytesToChar(ReadRom(romRead, playerOffset + PLAYER_R_STRENGTH));
	
	
}

Player::~Player(){
	delete name;
}

unsigned int Player::GetOffset(){ return playerOffset; }

void Player::SetAttribute(unsigned int attribute, unsigned short value, bool adjust){
	unsigned char * temp;
	unsigned char charVal = value;

	// Single byte values
	if (attribute < 0x8 || (attribute > 0x28 && attribute < 0x3B)){
		switch (attribute){
		case PLAYER_NUMBER:
			number = charVal;
			break;
		case PLAYER_POSITION:
			position = charVal;
			break;
		case PLAYER_HEIGHT:
			if (adjust)
				charVal -= 5;
			height = charVal;
			break;
		case PLAYER_WEIGHT:
			if (adjust)
				weight -= 100;
			weight = charVal;
			break;
		case PLAYER_EXP:
			experience = charVal;
			break;
		case PLAYER_UNIVERSITY:
			university = charVal;
			break;
		case PLAYER_SKINCOLOR:
			skinColor = charVal;
			break;
		case PLAYER_HAIR:
			hair = charVal;
			break;
		case PLAYER_R_GOALS:
			rGoals = charVal;
			break;
		case PLAYER_R_THREES:
			rThrees = charVal;
			break;
		case PLAYER_R_FREETHROW:
			rFreeThrows = charVal;
			break;
		case PLAYER_R_DUNKING:
			rDunking = charVal;
			break;
		case PLAYER_R_STEALING:
			rStealing = charVal;
			break;
		case PLAYER_R_BLOCKS:
			rBlocks = charVal;
			break;
		case PLAYER_R_OFFREBOUNDING:
			rOffRebounding = charVal;
			break;
		case PLAYER_R_DEFREBOUNDING:
			rDefRebounding = charVal;
			break;
		case PLAYER_R_PASSING:
			rPassing = charVal;
			break;
		case PLAYER_R_OFFAWARENESS:
			rOffAwareness = charVal;
			break;
		case PLAYER_R_SPEED:
			rSpeed = charVal;
			break;
		case PLAYER_R_QUICKNESS:
			rQuickness = charVal;
			break;
		case PLAYER_R_JUMPING:
			rJumping = charVal;
			break;
		case PLAYER_R_DRIBLING:
			rDribling = charVal;
			break;
		case PLAYER_R_STRENGTH:
			rStrength = charVal;
			break;
		}
		WriteRom(romWrite, playerOffset + attribute, &charVal);
	}
	else if (attribute > 0x7 && attribute < 0x2A){ // Multi byte values
		switch (attribute){
		case PLAYER_S_GAMES:
			sGames = value;			
			break;
		case PLAYER_S_MINUTES:
			sMinutes = value;
			break;
		case PLAYER_S_MADEGOALS:
			sMadeGoals = value;
			break;
		case PLAYER_S_ATTEMPTEDGOALS:
			sAttemptedGoals = value;
			break;
		case PLAYER_S_MADETHREES:
			sMadeThrees = value;
			break;
		case PLAYER_S_ATTEMPTEDTHREES:
			sAttemptedThrees = value;
			break;
		case PLAYER_S_MADEFREETHROWS:
			sMadeFreeThrows = value;
			break;
		case PLAYER_S_ATTEMPTEDFREETHROWS:
			sAttemptedFreeThrows = value;
			break;
		case PLAYER_S_OFFREBOUNDS:
			sOffRebounds = value;
			break;
		case PLAYER_S_REBOUNDS:
			sRebounds = value;
			break;
		case PLAYER_S_ASSISTS:
			sAssists = value;
			break;
		case PLAYER_S_STEALS:
			sSteals = value;
			break;
		case PLAYER_S_TURNOVERS:
			sTurnovers = value;
			break;
		case PLAYER_S_BLOCKS:
			sBlocks = value;
			break;
		case PLAYER_S_POINTS:
			sPoints = value;
			break;
		case PLAYER_S_FOULEDOUT:
			sFouledOut = value;
			break;
		case PLAYER_S_FOULS:
			sFouls = value;
			break;
		}

		temp = ShortToBytes(value);
		WriteRom(romWrite, playerOffset + attribute, temp, 2);
		delete temp;
	}
}
void Player::SetAttribute(unsigned int attribute, char nam[]){

	// Set name to all zeros
	for (int i = 0; i < 30; i++)
		name[i] = 0;

	char firstName[30];
	char lastName[30];

	for (int j = 0; j < 30; j++){
		firstName[j] = '\0';
		lastName[j] = '\0';
	}

	int i = 0;
	for (; i < nameSize / 2; i++){
		if (nam[i] == ' ')
			break;
		firstName[i] = nam[i];
	}
	i++;
	int k = i;
	for (i; i < nameSize; i++){
		if (nam[i] == ' ')
			break;
		lastName[i-k] = nam[i];
	}

	i = 0;
	k = 0;

	for (;; i++){
		if (lastName[i] == '\0')
			break;
		name[i] = lastName[i];
	}

	name[i] = 0;
	i++;
	k = i;
	for (;;i++){
		if (firstName[i - k] == '\0')
			break;
		name[i] = firstName[i - k];
	}

	WriteRom(romWrite, playerOffset + attribute, name, nameSize);
}

unsigned short Player::GetAttribute(unsigned int attribute){
		switch (attribute){
		case PLAYER_NUMBER:
			return number;
		case PLAYER_POSITION:
			return position;
		case PLAYER_HEIGHT:
			return height;
		case PLAYER_WEIGHT:
			return weight;
		case PLAYER_EXP:
			return experience;
		case PLAYER_UNIVERSITY:
			return university;
		case PLAYER_SKINCOLOR:
			return skinColor;
		case PLAYER_HAIR:
			return hair;
		case PLAYER_R_GOALS:
			return rGoals;
		case PLAYER_R_THREES:
			return rThrees;
		case PLAYER_R_FREETHROW:
			return rFreeThrows;
		case PLAYER_R_DUNKING:
			return rDunking;
		case PLAYER_R_STEALING:
			return rStealing;
		case PLAYER_R_BLOCKS:
			return rBlocks;
		case PLAYER_R_OFFREBOUNDING:
			return rOffRebounding;
		case PLAYER_R_DEFREBOUNDING:
			return rDefRebounding;
		case PLAYER_R_PASSING:
			return rPassing;
		case PLAYER_R_OFFAWARENESS:
			return rOffAwareness;
		case PLAYER_R_SPEED:
			return rSpeed;
		case PLAYER_R_QUICKNESS:
			return rQuickness;
		case PLAYER_R_JUMPING:
			return rJumping;
		case PLAYER_R_DRIBLING:
			return rDribling;
		case PLAYER_R_STRENGTH:
			return rStrength;
		case PLAYER_S_GAMES:
			return sGames;
		case PLAYER_S_MINUTES:
			return sMinutes;
		case PLAYER_S_MADEGOALS:
			return sMadeGoals;
		case PLAYER_S_ATTEMPTEDGOALS:
			return sAttemptedGoals;
		case PLAYER_S_MADETHREES:
			return sMadeThrees;
		case PLAYER_S_ATTEMPTEDTHREES:
			return sAttemptedThrees;
		case PLAYER_S_MADEFREETHROWS:
			return sMadeFreeThrows;
		case PLAYER_S_ATTEMPTEDFREETHROWS:
			return sAttemptedFreeThrows;
		case PLAYER_S_OFFREBOUNDS:
			return sOffRebounds;
		case PLAYER_S_REBOUNDS:
			return sRebounds;
		case PLAYER_S_ASSISTS:
			return sAssists;
		case PLAYER_S_STEALS:
			return sSteals;
		case PLAYER_S_TURNOVERS:
			return sTurnovers;
		case PLAYER_S_BLOCKS:
			return sBlocks;
		case PLAYER_S_POINTS:
			return sPoints;
		case PLAYER_S_FOULEDOUT:
			return sFouledOut;
		case PLAYER_S_FOULS:
			return sFouls;
	}
		return 0;
}
string Player::GetName(){
	char reName[30];
	int middlePos = 0;
	
	for (int i = 0; i < 30; i++){

	}

	string returnVal((char*)name);
	return returnVal;
}