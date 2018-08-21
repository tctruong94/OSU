/********************************
**Name:Thanbinh Truong
**Assignment:Program 2
**Date:February 11th, 2018
**Course:CS 344
*********************************/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>


//constants for game
#define ROOM_LIST 10                                        //maximum # of rooms to be choosen from
#define MAX_ROOMS_IN_GAME 7                                 //maximum # of rooms during game
#define BUFFER_SIZE 256                                     //maximum buffer size set to 256
#define MIN_CONNECTED_ROOMS 3                               //minumum # of rooms connected to one room
#define MAX_CONNECTED_ROOMS 6                               //maximum # of rooms connected to one room

//room types
enum ROOM_TYPES 
{
    START_ROOM,                                             //only 1 room can be START_ROOM
    MID_ROOM,                                               //remaining rooms are MID_ROOM
    END_ROOM                                                //only 1 room can be END_ROOM
};


//struct that holds information about the rooms
struct ROOM 
{
    int currentConnectionCount;                             //# of rooms connected
    char name[BUFFER_SIZE];                                 //holds the name of the room

    struct ROOM * connectionArr[MAX_CONNECTED_ROOMS];       //array of pointers to connected rooms
    enum ROOM_TYPES roomType;                               //holds the room type
};


char * timeOutputFileName = "timeStamp.txt";                //output file name for current time
char dirName[BUFFER_SIZE];
struct ROOM roomArr[MAX_ROOMS_IN_GAME];                     //struct of rooms
pthread_mutex_t timeFilePtrMutex;

void checkDir();
void GenerateRooms();
void ConnectRooms(int firstRoomIndex, int SecondRoomIndex);
int findRoomIndex(char * roomName);
int LocateStartRoomIndex();
void makeRoomArr();
void makeConnectedRoomArr(int index);
void fillRoomArr();
void cleanDirName();
void update(char * key, char * val);
void * GenerateCurrentTimeFilePtr();
void PrintCurrentTime();
void printSteps(int * steps, int totSteps);
void GameStart();


/********************************
**Function Name: checkDir()
**Description: Checks for most recent directory
*********************************/
void checkDir()
{
    struct dirent * dirPtr;
    struct stat * buffer;

    char * dirFolder = "truontha.rooms.";
    char currDir[BUFFER_SIZE];

    time_t lastMod;
    time_t timeHolder = 0;

    DIR * dir;

    buffer = malloc(sizeof(struct stat));
    dirPtr = malloc(sizeof(struct dirent));

    cleanDirName();

    memset(currDir, '\0', sizeof(currDir));
    getcwd(currDir, sizeof(currDir));
    dir = opendir(currDir);


    if (dir != NULL)                                            //check if directory is NOT NULL
    {
        while (dirPtr = readdir(dir)) 
        {	
            if (strstr(dirPtr->d_name,dirFolder) != NULL)
            {
                stat(dirPtr->d_name, buffer);
                lastMod = buffer->st_mtime;

                if(lastMod > timeHolder)
                {
                    timeHolder = lastMod;
                    strcpy(dirName, dirPtr->d_name);
                }
            }
        }
    }
}


/********************************
**Function Name: GenerateRooms()
**Description: makes room files and puts them in most recent directory
*********************************/
void GenerateRooms()
{
    int i;
    char fileName[BUFFER_SIZE];
    char fileInfo[BUFFER_SIZE];

    FILE * roomFilePtr;

    fillRoomArr();
    chdir(dirName);

    for(i = 0;i < MAX_ROOMS_IN_GAME;i++)
    {
        roomFilePtr = fopen(roomArr[i].name,"r");

        if(roomFilePtr == NULL)
        {
            printf("%s file was not accessed\n",roomArr[i].name);
            return;
        }

        memset(fileName, '\0', sizeof(fileName));
        memset(fileInfo, '\0', sizeof(fileInfo));


        while(fgets(fileName, sizeof(fileName),roomFilePtr) != NULL)      //reach each line from current file
        {
            update(fileName, fileInfo);
            if(strcmp(fileName, "ROOM TYP") == 0) 
            {
                if(strcmp(fileInfo, "START_ROOM") == 0) 
                {
                    roomArr[i].roomType = START_ROOM;
                }
                else if(strcmp(fileInfo, "END_ROOM") == 0) 
                {
                    roomArr[i].roomType = END_ROOM;
                }
                else{
                    roomArr[i].roomType = MID_ROOM;
                }
            }
            else if(strcmp(fileName,"CONNECTION ") == 0) 
            {
                int conncroomIndex = findRoomIndex(fileInfo);
                ConnectRooms(i, conncroomIndex);
            }
        }
        fclose(roomFilePtr);
    }
    chdir("..");
}


/********************************
**Function Name: ConnectRooms()
**Description: connects first room to the second
*********************************/
void ConnectRooms(int firstRoomIndex, int SecondRoomIndex)
{
    int totalConnected = roomArr[firstRoomIndex].currentConnectionCount;

    roomArr[firstRoomIndex].connectionArr[totalConnected] = &roomArr[SecondRoomIndex];
    roomArr[firstRoomIndex].currentConnectionCount++;
}


/********************************
**Function Name: findRoomIndex()
**Description: find a room's index in array using the name of the room
*********************************/
int findRoomIndex(char * roomName)                              //roomName is room being searched
{
    int i;
    int index = -1;

    for(i = 0;i < MAX_ROOMS_IN_GAME; i++ )
    {
        if (strcmp(roomArr[i].name, roomName) == 0 )
        {
            return i;                                           //index of room searched
        }
    }
    return index;                                               //return room's index
}


/********************************
**Function Name: LocateStartRoomIndex()
**Description: Find index of start room
*********************************/
int LocateStartRoomIndex()
{
    int i;

    for(i =0; i < MAX_ROOMS_IN_GAME; i++)
    {
        if(roomArr[i].roomType == START_ROOM)
        { 
            return i;                                               //return index of start room
        }
    }
    return -1;                                                      //not found
}


/********************************
**Function Name: makeRoomArr()
**Description: clears roomArr
*********************************/
void makeRoomArr() 
{
    int i;
    for(i = 0; i < MAX_ROOMS_IN_GAME; i++)
    {
        memset(roomArr[i].name, '\0', sizeof(roomArr[i].name));
        roomArr[i].currentConnectionCount = 0;
        makeConnectedRoomArr(i);
    }
}


/********************************
**Function Name: makeConnectedRoomArr()
**Description: clear room's array of connected rooms
*********************************/
void makeConnectedRoomArr(int index)
{
    int i;

    for(i = 0; i < MAX_CONNECTED_ROOMS; i++)                    //iterates through each index and sets to NULL
    {        
            roomArr[index].connectionArr[i] = NULL;
    }
}


/********************************
**Function Name: fillRoomArr()
**Description: puts the names in each file
*********************************/
void fillRoomArr()
{
    int num = 0;
    struct dirent * var;
    DIR * directoryPtr;

    makeRoomArr();

    if ((directoryPtr = opendir(dirName)) != NULL)
    {
        while ((var = readdir (directoryPtr)) != NULL)
        {
            if (strlen(var->d_name) > 2)
            {
                strcpy(roomArr[num].name, var->d_name);
                num++;
            }
        }
    }
}


/********************************
**Function Name: cleanDirName()
**Description: cleans dirName
*********************************/
void cleanDirName()
{
    memset(dirName, '\0', sizeof(dirName));
}


/********************************
**Function Name: update
**Description: updates key and value for file buffer
*********************************/
void update(char * key, char * val)
{
    int i;
    strtok(key, ":");
    strcpy(val, strtok(NULL, ""));

    val[strlen(val) - 1] = '\0';
    key[strlen(key) - 1] = '\0';

    for(i = 0; i < strlen(val); i++)
    {
        val[i] = val[i + 1];
    }
}


/********************************
**Function Name: GenerateCurrentTimeFilePtr()
**Description: make text file with current user time
*********************************/
void * GenerateCurrentTimeFilePtr()
{
    char timeStr[BUFFER_SIZE];
    struct tm * data;
    time_t currTime;

    FILE * timeFilePtr;

    memset(timeStr, '\0', sizeof(timeStr));
    time(&currTime);

    data = localtime(&currTime);
    strftime(timeStr, BUFFER_SIZE, "%I:%M%P %A, %B %d, %Y", data);

    timeFilePtr = fopen(timeOutputFileName, "w");

    fprintf(timeFilePtr,"%s\n",timeStr);

    fclose(timeFilePtr);

    return NULL;
}


/********************************
**Function Name: PrintCurrentTime()
**Description: Prints current user time
*********************************/
void PrintCurrentTime()
{
    char buffer[BUFFER_SIZE];
    FILE * timeFilePtr;

    memset(buffer, '\0', sizeof(buffer));
    timeFilePtr = fopen(timeOutputFileName, "r");

    if (timeFilePtr == NULL)                                            //check if empty
    {    
        printf("%s could not be accessed\n", timeOutputFileName);
        return;
    }

    while(fgets(buffer, BUFFER_SIZE, timeFilePtr) != NULL)
    {
        printf("%s\n", buffer);
    }

    fclose(timeFilePtr);
}


/********************************
**Function Name: CreateNewThread()
**Description: Creates thread to allow writing of current time to occur
*********************************/
int CreateNewThread()
{
    pthread_t thread;
    pthread_mutex_lock(&timeFilePtrMutex);
    if (pthread_create(&thread, NULL, GenerateCurrentTimeFilePtr, NULL) != 0)      //error checking
    {    
        printf("Error from thread!");
        return 0;
    }

    pthread_mutex_unlock(&timeFilePtrMutex);
    pthread_join(thread, NULL);

    return 1;
}


/********************************
**Function Name: printSteps()
**Description: outputs rooms visited during game
*********************************/
void printSteps(int * steps, int totSteps)
{
    int i;

    for (i = 0; i < totSteps + 1; i++)
    {
        printf("%s\n", roomArr[steps[i]].name);
    }
}


/********************************
**Function Name: GameStart()
**Description: Game process
*********************************/
void GameStart()
{
    int currentStep = 0;
    int roomFound = 0;
    int savedSteps[1028];
    int currRoomIndex;
    int i;

    struct ROOM currRoom;
    char userInput[BUFFER_SIZE];


    savedSteps[currentStep] = LocateStartRoomIndex();

    do {
        currRoomIndex = savedSteps[currentStep];
        currRoom = roomArr[currRoomIndex];

        printf("CURRENT LOCATION: %s\n", currRoom.name);

        printf("POSSIBLE CONNECTIONS:");
        for (i = 0; i < currRoom.currentConnectionCount - 1; i++)
        {
            printf(" %s,", currRoom.connectionArr[i]->name);
        }

        printf(" %s.\n", currRoom.connectionArr[i]->name);

        memset(userInput,'\0', sizeof(userInput));
        printf("WHERE TO? > ");
        scanf("%255s", userInput);
        printf("\n");

        roomFound = 0;

        for (i = 0; i < currRoom.currentConnectionCount; i++) 
        {
            if(strcmp(userInput, currRoom.connectionArr[i]->name) == 0) 
            {
                ++currentStep;
                savedSteps[currentStep] = findRoomIndex(userInput);
                currRoomIndex = savedSteps[currentStep];
                currRoom = roomArr[currRoomIndex];
                roomFound = 1;
                if(currRoom.roomType == END_ROOM)
                {
                    printf("YOU HAVE FOUND THE END ROOM. CONGRATULATIONS!\n");
                    printf("YOU TOOK %d STEPS. YOUR PATH TO VICTORY WAS:\n",currentStep + 1);
                    printSteps(savedSteps, currentStep);
                    return;
                }
            }
        }

        if(strcmp(userInput,"time") == 0 && roomFound == 0)
        {
            if (CreateNewThread() == 1) 
            {
                PrintCurrentTime();
            }
        } 
        else if (roomFound == 0)                        //error checking
        {                                                
            printf("HUH? I DON’T UNDERSTAND THAT ROOM. TRY AGAIN.\n\n");
        }
    } while(1);
}


int main()
{
    checkDir();
    GenerateRooms();
    GameStart();
    return 0;
}