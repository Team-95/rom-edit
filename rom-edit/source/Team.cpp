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

	tsBackgroundColor = BytesToChar(ReadRom(romRead, tOffset + TEAM_TS_BACKGROUND_COLOR));
	tsBannerColor = BytesToChar(ReadRom(romRead, tOffset + TEAM_TS_BANNER_COLOR));
	tsTextColor = BytesToChar(ReadRom(romRead, tOffset + TEAM_TS_TEXT_COLOR));
}

//Team::Team(FILE* romR, FILE* romW, unsigned int &teamAddress, unsigned int menuAddress){}

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
	case TEAM_TS_BACKGROUND_COLOR:
		return tsBackgroundColor;
	case TEAM_TS_BANNER_COLOR:
		return tsBannerColor;
	case TEAM_TS_TEXT_COLOR:
		return tsTextColor;
	}
	return 0;
}

void Team::SetAttribute(unsigned int attribute, unsigned char value)
{
	switch (attribute){
	case TEAM_SCORING:
		scoring = value;
		break;
	case TEAM_REBOUNDS:
		rebounds = value;
		break;
	case TEAM_BALLCONTROL:
		ballControl = value;
		break;
	case TEAM_DEFENSE:
		defense = value;
		break;
	case TEAM_OVERALL:
		overall = value;
		break;
	case TEAM_TS_BACKGROUND_COLOR:
		tsBackgroundColor = value;
		break;
	case TEAM_TS_BANNER_COLOR:
		tsBannerColor = value;
		break;
	case TEAM_TS_TEXT_COLOR:
		tsTextColor = value;
		break;
	}
	WriteRom(romWrite, tOffset + attribute, &value);
}

void Team::SetPlayer(int index, Player * player)
{
	players[index] = player;
	//WriteRom(romWrite, tOffset + (4 * index), IntToBytes(player->GetOffset()), 4);
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