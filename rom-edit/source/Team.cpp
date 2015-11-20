#include "Team.h"

Team::Team(){}

Team::Team(FILE* romR, FILE* romW, unsigned int teamAddress, unsigned int menuAddress)
{
	romRead = romR;
	romWrite = romW;
	tOffset = teamAddress;
	mOffset = menuAddress;

	scoring = BytesToChar(ReadRom(romRead, tOffset + TEAM_SCORING));
	rebounds = BytesToChar(ReadRom(romRead, tOffset + TEAM_REBOUNDS));
	ballControl = BytesToChar(ReadRom(romRead, tOffset + TEAM_BALLCONTROL));
	defense = BytesToChar(ReadRom(romRead, tOffset + TEAM_DEFENSE));
	overall = BytesToChar(ReadRom(romRead, tOffset + TEAM_OVERALL));

	tsColor1 = BytesToChar(ReadRom(romRead, tOffset + TEAM_TS_COLOR1));
	tsColor2 = BytesToChar(ReadRom(romRead, tOffset + TEAM_TS_COLOR2));
	tsColor3 = BytesToChar(ReadRom(romRead, tOffset + TEAM_TS_COLOR3));
}

Team::Team(FILE* romR, FILE* romW, unsigned int &teamAddress, unsigned int menuAddress){}

unsigned int Team::GetMenuAddress(){ return mOffset; }
unsigned int Team::GetTeamAddress(){ return tOffset; }

unsigned short Team::GetAttribute(unsigned int attribute)
{
	switch (attribute){
	case TEAM_SCORING:
		return scoring;
	case TEAM_REBOUNDS:
		return rebounds;
	case TEAM_BALLCONTROL:
		return ballControl;
	case TEAM_DEFENSE:
		return defense;
	case TEAM_OVERALL:
		return overall;
	case TEAM_TS_COLOR1:
		return tsColor1;
	case TEAM_TS_COLOR2:
		return tsColor2;
	case TEAM_TS_COLOR3:
		return tsColor3;
	}
	return 0;
}

void Team::SetAttribute(unsigned int attribute, unsigned char value)
{
	switch (attribute){
	case TEAM_SCORING:
		scoring = value;
	case TEAM_REBOUNDS:
		rebounds = value;
	case TEAM_BALLCONTROL:
		ballControl = value;
	case TEAM_DEFENSE:
		defense = value;
	case TEAM_OVERALL:
		overall = value;
	case TEAM_TS_COLOR1:
		tsColor1 = value;
	case TEAM_TS_COLOR2:
		tsColor2 = value;
	case TEAM_TS_COLOR3:
		tsColor3 = value;
	}
	WriteRom(romWrite, tOffset + attribute, &value);
}

void Team::SetPlayer(int index, Player * player)
{
	players[index] = player;
}

Player* Team::GetPlayer(int index)
{
	return players[index];
}
 
//void Team::SetMenuAddress(unsigned int off){
//	mOffset = off;
//
//	// Write the team address to the menu location
//	WriteRom(romWrite, mOffset, IntToBytes(tOffset), 4);
//}
//void Team::SetTeamAddress(unsigned int off){
//	tOffset = off;
//
//	// Write the team address to the menu location
//	WriteRom(romWrite, mOffset, IntToBytes(tOffset), 4);
//}