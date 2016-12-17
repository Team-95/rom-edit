#include "ConstantsTeam.h"
#include "ConstantsPlayer.h"
#include "Helpers.h"
#include "Player.h"

using namespace std;

class Team{
public:
	Team();
	// For existing teams
	Team(FILE* romR, FILE* romW, unsigned int teamAddress, unsigned int menuAddress);
	// For new team in ROM
	//Team(FILE* romR, FILE* romW, unsigned int &teamAddress, unsigned int menuAddress);

	unsigned int GetMenuAddress();
	unsigned int GetTeamAddress();

	//void SetMenuAddress(unsigned int off);
	//void SetTeamAddress(unsigned int off);

	Player* GetPlayer(int index);
	void SetPlayer(int index, Player * player);

	void SetAttribute(unsigned int attribute, unsigned char value);
	unsigned short GetAttribute(unsigned int attribute);

private:
	FILE * romRead;
	FILE * romWrite;

	unsigned int mOffset;
	unsigned int tOffset;

	Player* players[16];

	unsigned char scoring;
	unsigned char rebounds;
	unsigned char ballControl;
	unsigned char defense;
	unsigned char overall;

	unsigned char tsBackgroundColor;
	unsigned char tsBannerColor;
	unsigned char tsTextColor;

	unsigned char * courtName;
	unsigned char * location;
	unsigned char * teamName;

};