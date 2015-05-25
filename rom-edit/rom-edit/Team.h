#include "ConstantsTeam.h"
#include "Player.h"

using namespace std;

class Team{
public:
	Team(unsigned int teamAddress, unsigned int menuAddress);
	unsigned int GetMenuAddress();
	unsigned int GetTeamAddress();
	void SetMenuAddress(unsigned int off);
	void SetTeamAddress(unsigned int off);
	Player* GetPlayer(int index);
private:
	unsigned int mAddress;
	unsigned int tAddress;
	Player players[16];
};