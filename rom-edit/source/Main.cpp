#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Player.h"
#include "Team.h"
#include "Helpers.h"
#include "ConstantsPlayer.h"
#include "ConstantsTeam.h"

using namespace std;

int main()
{
	FILE *tempRead;
	FILE* romRead;
	FILE* romWrite;
	int movingEmptyOffset = EMPTY_OFFSET;
	Team teams[27];

	tempRead = fopen("D:\\OwnCloud\\Team95\\test.md", "rb");
	romWrite = fopen("D:\\OwnCloud\\Team95\\rom-edit.md", "wb");

	if (!tempRead || !romWrite)
	{
		cout << "File could not be opened" << endl;
		return 1;
	}
	CopyFile(tempRead, romWrite);

	fclose(tempRead);

	romRead = fopen("D:\\OwnCloud\\Team95\\rom-edit.md", "rb");

	ifstream playerStats("D:\\Projects\\2014-15 Player and Team Stats\\2014-15.csv");
	string line;

	string curTeamAb = "";
	Team* curTeam;
	int playerIndex = 0;
	unsigned int emptyOffset = EMPTY_OFFSET;

	while (getline(playerStats, line))
	{
		stringstream lineStream(line);
		string cell;

		getline(lineStream, cell, ',');

		if (cell != curTeamAb && cell != "NOP")
		{
			curTeamAb = cell;

			unsigned int tOff;
			unsigned int mOff;

			TeamOffsetsFromAbbreviation(cell, tOff, mOff);

			curTeam = new Team(romRead, romWrite, tOff, mOff);
			playerIndex = 0;
		}

		if (playerIndex < 12)
		{
			//curTeam->SetPlayer(playerIndex, new Player(romRead, romWrite, emptyOffset, true));

			unsigned int playerOffset;
			unsigned char *bytes = ReadRom(romRead, curTeam->GetTeamAddress() + (4 * playerIndex), 4);
			playerOffset = BytesToInt(bytes);
			curTeam->SetPlayer(playerIndex, new Player(romRead, romWrite, playerOffset));

			int cellNumber = 0;
			while (getline(lineStream, cell, ','))
			{
				Player* curPlayer = curTeam->GetPlayer(playerIndex);
				switch (cellNumber)
				{
				case 1:
					curPlayer->SetName(cell.c_str());
					break;
				case 2: 
					unsigned char val;
					if (cell == "C") { val = 0; }
					else if (cell == "PF") { val = 1; }
					else if (cell == "SF") { val = 2; }
					else if (cell == "PG") { val = 3; }
					else if (cell == "SG") { val = 4; }

					curPlayer->SetAttribute(PLAYER_POSITION, val);
					break;
				case 3:
					curPlayer->SetAttribute(PLAYER_NUMBER, StringToChar(cell)); 
					break;
				case 4:
					curPlayer->SetAttribute(PLAYER_HEIGHT, StringToChar(cell));
					break;
				case 5:
					curPlayer->SetAttribute(PLAYER_WEIGHT, StringToChar(cell), true);
					break;
				case 6:// College, need a helper function
					   //curPlayer->SetAttribute(PLAYER_NUMBER, StringToChar(cell));
					break;
				case 7:
					curPlayer->SetAttribute(PLAYER_S_GAMES, StringToShort(cell));
					break;
				case 8:
					curPlayer->SetAttribute(PLAYER_S_MINUTES, StringToShort(cell)); 
					break;
				case 9:
					curPlayer->SetAttribute(PLAYER_S_MADEGOALS, StringToShort(cell));
					break;
				case 10:
					curPlayer->SetAttribute(PLAYER_S_ATTEMPTEDGOALS, StringToShort(cell));
					break;
				case 11:
					curPlayer->SetAttribute(PLAYER_S_MADETHREES, StringToShort(cell));
					break;
				case 12:
					curPlayer->SetAttribute(PLAYER_S_ATTEMPTEDTHREES, StringToShort(cell));
					break;
				case 13:
					curPlayer->SetAttribute(PLAYER_S_MADEFREETHROWS, StringToShort(cell));
					break;
				case 14:
					curPlayer->SetAttribute(PLAYER_S_ATTEMPTEDFREETHROWS, StringToShort(cell));
					break;
				case 15:
					curPlayer->SetAttribute(PLAYER_S_OFFREBOUNDS, StringToShort(cell));
					break;
				case 16:
					curPlayer->SetAttribute(PLAYER_S_REBOUNDS, StringToShort(cell));
					break;
				case 17:
					curPlayer->SetAttribute(PLAYER_S_ASSISTS, StringToShort(cell));
					break;
				case 18:
					curPlayer->SetAttribute(PLAYER_S_STEALS, StringToShort(cell));
					break;
				case 19:
					curPlayer->SetAttribute(PLAYER_S_BLOCKS, StringToShort(cell));
					break;
				case 20:
					curPlayer->SetAttribute(PLAYER_S_TURNOVERS, StringToShort(cell));
					break;
				case 21:
					curPlayer->SetAttribute(PLAYER_S_FOULS, StringToShort(cell));
					break;
				case 22:
					curPlayer->SetAttribute(PLAYER_S_POINTS, StringToShort(cell));
					break;
				case 23:
					curPlayer->SetAttribute(PLAYER_R_GOALS, StringToChar(cell));
					break;
				case 24:
					curPlayer->SetAttribute(PLAYER_R_THREES, StringToChar(cell));
					break;
				case 25:
					curPlayer->SetAttribute(PLAYER_R_FREETHROW, StringToChar(cell));
					break;
				case 26:
					curPlayer->SetAttribute(PLAYER_R_DUNKING, StringToChar(cell));
					break;
				case 27:
					curPlayer->SetAttribute(PLAYER_R_STEALING, StringToChar(cell));
					break;
				case 28:
					curPlayer->SetAttribute(PLAYER_R_BLOCKS, StringToChar(cell));
					break;
				case 29:
					curPlayer->SetAttribute(PLAYER_R_OFFREBOUNDING, StringToChar(cell));
					break;
				case 30:
					curPlayer->SetAttribute(PLAYER_R_DEFREBOUNDING, StringToChar(cell));
					break;
				case 31:
					curPlayer->SetAttribute(PLAYER_R_PASSING, StringToChar(cell));
					break;
				case 32:
					curPlayer->SetAttribute(PLAYER_R_OFFAWARENESS, StringToChar(cell));
					break;
				case 33:
					curPlayer->SetAttribute(PLAYER_R_DEFAWARENESS, StringToChar(cell));
					break;
				case 34:
					curPlayer->SetAttribute(PLAYER_R_SPEED, StringToChar(cell));
					break;
				case 35:
					curPlayer->SetAttribute(PLAYER_R_QUICKNESS, StringToChar(cell));
					break;
				case 36:
					curPlayer->SetAttribute(PLAYER_R_JUMPING, StringToChar(cell));
					break;
				case 37:
					curPlayer->SetAttribute(PLAYER_R_DRIBLING, StringToChar(cell));
					break;
				case 38:
					curPlayer->SetAttribute(PLAYER_R_STRENGTH, StringToChar(cell));
					break;
				case 39:
					curPlayer->SetAttribute(PLAYER_HAIR, StringHexToChar(cell));
				case 40:
					curPlayer->SetAttribute(PLAYER_SKINCOLOR, StringHexToChar(cell));
				default:
					break;
				}

				cellNumber++;
			}
		}

		playerIndex++;
	}

	fclose(romRead);
	fclose(romWrite);
	playerStats.close();
}