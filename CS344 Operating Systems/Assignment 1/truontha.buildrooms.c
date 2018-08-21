/********************************
**Name:Thanbinh Truong
**Assignment:Program 2
**Date:February 11th, 2018
**Course:CS 344
*********************************/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <time.h>



//constants for game
#define MAX_ROOMS_IN_GAME 7                                 //maximum # of rooms during game
#define ROOM_LIST 10                                        //maximum # of rooms to be choosen from
#define MIN_CONNECTED_ROOMS 3                               //minumum # of rooms connected to one room
#define MAX_CONNECTED_ROOMS 6                               //maximum # of rooms connected to one room
#define BUFFER_SIZE 256                                     //maximum buffer size set to 256


void ConnectRoom(int index);
int checkConnection(int firstRoom, int secondRoom);
int checkRoomConnectionCount(int index);
int checkIfRoomsAreConnected(int firstRoom, int secondRoom);
int generateRoomIndex(int min, int max);
int chooseRoomPosition();
void initRoomConnectArr(int index);
void makeRoomArr();
void fillRoomArr();
void makeRoomDirectory();
void moveRoomFilestoDir();

//Names of Rooms
char * ROOM_NAMES[ROOM_LIST] = 
{
    "Newark", "Union_City", "Milpitas", "San_Francisco", "Antioch", "Concord", "Pittsburg", "Tracy", "Pleasanton", "Berkeley"
};


//Holds the different types of rooms
enum TypeOfRoom 
{
    START_ROOM,                                             //only 1 room can be START_ROOM
    MID_ROOM,                                               //remaining rooms are MID_ROOM
    END_ROOM                                                //only 1 room can be END_ROOM
};


//Struct holding data for each room
struct ROOM
{
    int totalCurrConnected;                                 //Total number of connections per room
    char name[BUFFER_SIZE];                                 //Name of each room

    struct ROOM * connectionArr[MAX_CONNECTED_ROOMS];       //Array holding pointers to the connected rooms
    enum TypeOfRoom roomType;                               //Holds the room type
};

struct ROOM roomArr[MAX_ROOMS_IN_GAME];                     //struct of rooms during game
int roomsUsed[ROOM_LIST];                                   //# of initialized rooms
char directoryName[BUFFER_SIZE];                            //name of output file filled with room names


/********************************
**Function Name: ConnectRoom()
**Description: Connects passed-in room to other rooms
*********************************/
void ConnectRoom(int index)
{
    int connected = 0;
    int room1, room2;

    if (roomArr[index].totalCurrConnected == MAX_CONNECTED_ROOMS)
    {
        return;
    }

    do {
        room1 = index;
        room2 = generateRoomIndex(0, MAX_ROOMS_IN_GAME);

        if (checkConnection(room1, room2) == 0) {
            int connectionCount1 = roomArr[room1].totalCurrConnected;
            int connectionCount2 = roomArr[room2].totalCurrConnected;

            roomArr[room1].connectionArr[connectionCount1] = &roomArr[room2];
            roomArr[room2].connectionArr[connectionCount2] = &roomArr[room1];
            roomArr[room1].totalCurrConnected++;
            roomArr[room2].totalCurrConnected++;
            connected = 1;
        }
    } while(connected == 0);
}


/********************************
**Function Name: checkConnection()
**Description: Compares rooms and checks whether they are the same room or already connected
*********************************/
int checkConnection(int firstRoom, int secondRoom)
{
    if (firstRoom == secondRoom) {                             //compares two rooms to see if they are the same
        return 1;
    }

    if (checkIfRoomsAreConnected(firstRoom, secondRoom) == 1) {       //returns 1 if rooms are not connected
        return 1;
    } else {
        return 0;
    }
}

/********************************
**Function Name: checkRoomConnectionCount()
**Description: Returns 0 if current room has the max # of connections, 1 if it does not
*********************************/
int checkRoomConnectionCount(int index)
{
    if(roomArr[index].totalCurrConnected == MAX_CONNECTED_ROOMS)     //index is current room being checked
    {    
        return 0;
    }
    else
    {
        return 1;
    }
}

/********************************
**Function Name: checkIfRoomsAreConnected()
**Description: checks # of connections and connections of two rooms
*********************************/
int checkIfRoomsAreConnected(int firstRoom, int secondRoom)
{
    int i;
    if(roomArr[firstRoom].totalCurrConnected == MAX_CONNECTED_ROOMS) //firstRoom == first room
    {    
        return 1;
    }

    for(i = 0; i < roomArr[firstRoom].totalCurrConnected;i++)
    {
        if(roomArr[firstRoom].connectionArr[i] == NULL )
        {
            return 0;
        }
        else if(strcmp(roomArr[firstRoom].connectionArr[i]->name, roomArr[secondRoom].name) == 0)      //compares if both rooms are connected
        {    
            return 1;
        }
    }
    return 0;
}


/********************************
**Function Name: generateRoomIndex()
**Description: Generates random integer between a minimum and maximum boundary
*********************************/
int generateRoomIndex(int min, int max)
{
    int index;
    do {
        index = rand() % max + min;                                                    // generates random index between the min and max values
    } while(checkRoomConnectionCount(index) == 0 && index <= max && index >= min);     //makes sure index is within range of bounds

    return index;                                                                      //index == rooms index for game
}


/********************************
**Function Name: chooseRoomPosition()
**Description: Selects a random position for each room in roomArr
*********************************/
int chooseRoomPosition()
{
    int index;
    do {
        index = rand() % ROOM_LIST;
    } while (checkRoomConnectionCount(index) == 0);

    return index;
}


/********************************
**Function Name: initRoomConnectArr()
**Description: initializes indexed room connectionArr(array of connection rooms) to NULL
*********************************/
void initRoomConnectArr(int index)
{
    int i;

    for(i = 0; i < MAX_CONNECTED_ROOMS; i++)
    {
            roomArr[index].connectionArr[i] = NULL;
    }
}



/********************************
**Function Name: makeRoomArr()
**Description: initializes room array
*********************************/
void makeRoomArr()
{
    int i;
    for(i = 0; i < MAX_ROOMS_IN_GAME; i++)                          //initializes rooms in game
    {    
        roomsUsed[i] = 0;
    }

    for (i = 0; i < MAX_ROOMS_IN_GAME; i++) 
    {
        roomArr[i].totalCurrConnected = 0;
        initRoomConnectArr(i);
    
        while (1) {
            int randomRoomIndex = chooseRoomPosition();
            if (roomsUsed[randomRoomIndex] == 0) 
            {
                roomsUsed[randomRoomIndex] = 1;
                memset(roomArr[i].name,'\0', sizeof(roomArr[i].name));
                strcpy(roomArr[i].name,ROOM_NAMES[randomRoomIndex]);
                roomArr[i].roomType = MID_ROOM;
                break;
            }
        }
    }

    roomArr[0].roomType = START_ROOM;                             //set start room
    roomArr[MAX_ROOMS_IN_GAME - 1].roomType = END_ROOM;           //set end room
}

/********************************
**Function Name: fillRoomArr()
**Description: Generate connections of all rooms
*********************************/
void fillRoomArr()
{
    int i;
    int j;
    makeRoomArr();
    for(i = 0; i < MAX_ROOMS_IN_GAME; i++)
    {
        for(j = 0; j < MIN_CONNECTED_ROOMS; j++)
        {
            ConnectRoom(i);
        }
    }
}


/********************************
**Function Name: makeRoomDirectory()
**Description: generates directory containing rooms visited
*********************************/
void makeRoomDirectory()
{
    char * dirName = "truontha.rooms.";
    int pid = getpid();
    int setting = 0770;
    memset(directoryName, '\0', sizeof(directoryName));
    sprintf(directoryName, "%s%d", dirName, pid);

    mkdir(directoryName, setting);
}


/********************************
**Function Name: moveRoomFilestoDir()
**Description: Function that enters the room files into a room directory in the current game
*********************************/
void moveRoomFilestoDir()
{
    FILE * roomFilePtr;
    char dirName[BUFFER_SIZE];
    int i, j;

    sprintf(dirName, "./truontha.rooms.%d", getpid());              //beginning name of directory

    makeRoomDirectory();
    
    if(chdir(dirName) != 0){
        printf("DIR NOT CHANGED TO: %s\n", dirName);
        return;
    }


    for(i = 0; i < MAX_ROOMS_IN_GAME; i++)                          //creating room files
    {
        roomFilePtr = fopen(roomArr[i].name,"w");

        fprintf(roomFilePtr,"ROOM NAME: %s\n", roomArr[i].name);
        for(j = 0; j < roomArr[i].totalCurrConnected; j++)
        {
            fprintf(roomFilePtr,"CONNECTION %d: %s\n", j+1, roomArr[i].connectionArr[j]->name);
        }
        
        if(roomArr[i].roomType == START_ROOM)
        {
            fprintf(roomFilePtr,"ROOM TYPE: %s\n", "START_ROOM");
        }
        else if(roomArr[i].roomType == MID_ROOM)
        {
            fprintf(roomFilePtr,"ROOM TYPE: %s\n", "MID_ROOM");
        }
        else if(roomArr[i].roomType == END_ROOM)
        {
            fprintf(roomFilePtr,"ROOM TYPE: %s\n", "END_ROOM");
        }
        else
        {
            fprintf(roomFilePtr,"ROOM TYPE: %s\n", "NULL");
        }
        fclose(roomFilePtr);
    }
}


/********************************
**Function Name: main()
**Description: main function for building the rooms
*********************************/
int main()
{
    srand(time(NULL));                                      //seeding randomizer
    fillRoomArr();                                          //initiates and populates room array
    moveRoomFilestoDir();                                   //write room directory
    return 0;
}