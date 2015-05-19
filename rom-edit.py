from globals import *
import csv

# return amount of memory used to move movingEmptyOffset
def CreatePlayer(rom, offset, player):
    rom.seek(offset, 0)
    rom.write(b'\x05')                  # Player Number

    lastName = player[1].split()[0]
    firstName = player[1].split()[1]

    nameLength = len(row[1])
    return SIZEOF_PLAYER + nameLength

def main():
    pathToStats = 'D:\\OwnCloud\Team95\\stats\\players.csv'
    pathToRom = 'D:\\OwnCloud\Team95\\rom-edit.md'

    romFile = open(pathToRom, 'r+b')
    csvFile = open(pathToStats)
    statSheet = csv.reader(csvFile)

    movingEmptyOffset = EMPTY_OFFSET

    playerCount = 0
    for row in statSheet:
        if playerCount > 15:
            break
        playerCount = playerCount + 1

        CreatePlayer(romFile, movingEmptyOffset)



    romFile.close()
    csvFile.close()


if __name__ == '__main__':
    main()
