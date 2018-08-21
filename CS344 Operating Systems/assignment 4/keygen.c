/************************************
** Name: Thanhbinh Truong
** Class: CS344
** Assignment: Program OTP
** Date: 03/14/2018
************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define GENERATE_MAX 90
#define GENERATE_MIN 65

/******************************************
** Name: createKey
** Description: create a char pointer of randomly generated chars
******************************************/
char* createKey(int max)
{
    char* Key = malloc(sizeof(char) * max);

    int i;
    for(i = 0;i < max;i++)
    {
        if( (rand() % (10) + 1) == 3 || (rand() % (10) + 1) == 6)
        {
            Key[i] = ' ';
        }
        else
        {
            Key[i] = (rand() % (GENERATE_MAX + 1 - GENERATE_MIN) + GENERATE_MIN);
        }
    }

    Key[i] = '\0';                              //insert so program knows its the end of the pointer

    return Key;
}


/******************************************
** Name: checkArgc
** Description: makes sure there is at least 1 argument passed into the function
******************************************/
void checkArgc(int argc)
{
    if(argc == 1)                               //looking to make sure arg count equals 1
    {
        fprintf(stderr,"KeyGen: Enter a key length\n");
        exit(1);
    }
}

int main(int argc, char* argv[])
{
    int keySize;
    char* encryptedKey;

    checkArgc(argc);

    srand(time(NULL));                          //set randomizer

    keySize = atoi(argv[1]) + 1;

    encryptedKey = createKey(keySize);          //create key

    printf("%s",encryptedKey);                  //print out the encrypted key
    free(encryptedKey);                         //free encrypted key since it was created by Malloc
    return 0;
}