#define PLAYER_SIZE 93

#define PLAYER_NUMBER  0x0000
#define PLAYER_POSITION  0x0001                // 0 - C, 1 - PF, 2 - SF, 3 - PG, 4 - SG
#define PLAYER_HEIGHT  0x0002                  // In inches, 5 less than actual
#define PLAYER_WEIGHT  0x0003                  // 100 less than actual
#define PLAYER_EXP  0x0004
#define PLAYER_UNIVERSITY  0x0005              // Starts at 0x01
#define PLAYER_SKINCOLOR  0x0006               // Range 0x00 - 0x03
#define PLAYER_HAIR  0x0007                    // Range 0x00 - 0x26

// Season stats
#define PLAYER_S_GAMES  0x0008
#define PLAYER_S_MINUTES  0x000A          // 2 Byte values from here
#define PLAYER_S_MADEGOALS  0x000C
#define PLAYER_S_ATTEMPTEDGOALS  0x000E
#define PLAYER_S_MADETHREES  0x0010
#define PLAYER_S_ATTEMPTEDTHREES  0x0012
#define PLAYER_S_MADEFREETHROWS  0x0014
#define PLAYER_S_ATTEMPTEDFREETHROWS  0x0016
#define PLAYER_S_OFFREBOUNDS  0x0018
#define PLAYER_S_REBOUNDS  0x001A
#define PLAYER_S_ASSISTS  0x001C
#define PLAYER_S_STEALS  0x001E
#define PLAYER_S_TURNOVERS  0x0020
#define PLAYER_S_BLOCKS  0x0022
#define PLAYER_S_POINTS  0x0024
#define PLAYER_S_FOULEDOUT  0x0026
#define PLAYER_S_FOULS  0x0028

// Ratings
// Single byte values from here
// PLAYER Offset 0x002A is unknown
#define PLAYER_R_GOALS  0x002B
#define PLAYER_R_THREES  0x002C
#define PLAYER_R_FREETHROW  0x002D
#define PLAYER_R_DUNKING  0x002E
#define PLAYER_R_STEALING  0x002F
#define PLAYER_R_BLOCKS  0x0030
#define PLAYER_R_OFFREBOUNDING  0x0031
#define PLAYER_R_DEFREBOUNDING  0x0032
#define PLAYER_R_PASSING  0x0033
#define PLAYER_R_OFFAWARENESS  0x0034
#define PLAYER_R_DEFAWARENESS  0x0035
#define PLAYER_R_SPEED  0x0036
#define PLAYER_R_QUICKNESS  0x0037
#define PLAYER_R_JUMPING  0x038
#define PLAYER_R_DRIBLING  0x0039
#define PLAYER_R_STRENGTH  0x003A
#define PLAYER_NAME  0x0045

// PLAYER Offsets 0x003B through 0x44 are unknown, probably for saving stats