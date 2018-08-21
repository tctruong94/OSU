/************************************
** Name: Thanhbinh Truong
** Class: CS344
** Assignment: Program OTP
** Date: 03/14/2018
************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h> 
#include <sys/socket.h>


#define MAX 5

typedef enum {FALSE = 0, TRUE = 1} boolean;

char* PROGNAME = "ENC_SERVER";
char accepted_Type = 'E';

struct PidStackObj pId_Stack;


//pId struct
struct PidStackObj
{
    int pIdVar;
    pid_t bgPids[MAX];
};


/************************************
** Name: initiatePid
** Description: creates pId stack and initiate them all to == -1
************************************/
void initiatePid()
{
    pId_Stack.pIdVar = -1;

	int i;
    for(i = 0; i < MAX -1; i++)
    {
        pId_Stack.bgPids[i] = -1;
	}

}


/************************************
** Name: popPid
** Description: pops and returns the Pid from the top of the stack
************************************/
pid_t popPid()
{
    return pId_Stack.bgPids[pId_Stack.pIdVar--];
}


/************************************
** Name: topPid
** Description: read and returns the top of the Pid stack
************************************/
pid_t topPid()
{
    return pId_Stack.bgPids[pId_Stack.pIdVar];
}


/************************************
** Name: pushPid
** Description: puts a Pid into the stack
************************************/
void pushPid(pid_t id)
{
    pId_Stack.bgPids[++(pId_Stack.pIdVar)] = id;
}


/************************************
** Name: encryptText
** Description: Function that does the encryptText to the text with a key
************************************/
char* encryptText(char* key,char* text)
{
	int tempKeyData;
	int tempTextData;

	int length = strlen(text);										//set length to the length of the text

	char Encrypt_Buffer[70000];										//initiate size
	memset(Encrypt_Buffer,'\0',sizeof(Encrypt_Buffer));				//initiate the buffer with /O

	int i;
	for(i = 0;i < length; i++)
	{
		if(text[i] == ' ')
		{
			Encrypt_Buffer[i] = '?';								//replace ' ' with '?' for encryption
		}
		else 														//else do this with the rest of the chars
		{
			tempKeyData = (int)key[i];
			tempTextData = (int)text[i];
			Encrypt_Buffer[i] = (char)(tempTextData + (tempKeyData % 3));
		}
	}

	return strdup(Encrypt_Buffer);									//return ecrypted text
}


/************************************
** Name: progNameError
** Description: function that prints the name of the program along with the error
************************************/
void progNameError(const char* message) 
{
	fprintf(stderr,"%s: %s\n",PROGNAME,message);
	exit(1);
}

/************************************
** Name: error
** Description: function use to display error message
************************************/
void error(const char *msg)
{ 
	perror(msg);
	exit(1);
}


/************************************
** Name: killProcess
** Description: function to exit the processes and kill the background
************************************/
void killProcess(int sig)
{
    int i;
    for(i = 0;i < pId_Stack.pIdVar + 1;i++)
    {
        kill(pId_Stack.bgPids[i], SIGINT); 			//Kills the background process
    }
}



int main(int argc, char *argv[])
{
	initiatePid();													//initialize Pid stack
	signal(SIGINT,killProcess);				

	char FileBufferKey[70000];										//set buffer size for key file
	char FileBuffertext[70000];										//set buffer size for text file
	char buffer[256];												//set buffer size

	char* encryptBuffer;

	char clienttype;
	char charResponse;

	int portNumber;													//the port number

	int socketFD;													//used to listen
	int newSocketFD;

	int lengthOfFile;

	socklen_t sizeOfClientInfo;										//holds the size of the client

	struct sockaddr_in serverAddress;								//struct to hold addresses
	struct sockaddr_in clientAddress;

	if (argc < 2)													//error if less than 2 arguments
	{
		fprintf(stderr,"USAGE: %s port\n", argv[0]);
		exit(1);
	}

	memset((char *)&serverAddress, '\0', sizeof(serverAddress)); 	//set address to \0

	portNumber = atoi(argv[1]); 		//Get port number from the second arg & convert from string to int
	serverAddress.sin_family = AF_INET; 							//create network capable socket
	serverAddress.sin_port = htons(portNumber); 					//save port number
	serverAddress.sin_addr.s_addr = INADDR_ANY; 					//any address allowed to connect


	socketFD = socket(AF_INET, SOCK_STREAM, 0); 					//Create socket
	if (socketFD < 0)
	{
		error("ERROR while opening socket");
	}

	if (bind(socketFD, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)	//if less than 0, connect to port
	{
		error("ERROR on binding");
	}
	listen(socketFD, 5); 											//turn on socket to allow up to 5 connections
	sizeOfClientInfo = sizeof(clientAddress); 						//set to size of address for connecting client

	while(TRUE)
	{
		newSocketFD = accept(socketFD, (struct sockaddr *)&clientAddress, &sizeOfClientInfo); //allow to accept sent calls
		
		if (newSocketFD < 0) 										//error
		{
			error("ERROR on accept");
		}

		pid_t pid = fork();
		switch(pid)
		{
			case -1:												//error 
				progNameError("Child fork error.");
			case 0:													//in child process

				recv(newSocketFD,&clienttype,sizeof(char),0);

				if(clienttype != accepted_Type)						//if it does not equal, no connection
				{
					charResponse = 'N';
					send(newSocketFD,&charResponse,sizeof(char),0);
					progNameError("Invalid client connection.");	//err message
				}
				else												//equals, accepts connection and client
				{
					charResponse = 'Y';		
					send(newSocketFD,&charResponse,sizeof(char),0);
				}

				recv(newSocketFD,&lengthOfFile,sizeof(lengthOfFile),0);

				memset(FileBufferKey,'\0',sizeof(FileBufferKey));	//fill key buffer for safetly
				memset(FileBuffertext,'\0',sizeof(FileBuffertext));	//fill text buffer for safetly

				recv(newSocketFD,FileBufferKey, lengthOfFile * sizeof(char),0);		//receive info for key
				recv(newSocketFD,FileBuffertext,lengthOfFile * sizeof(char),0);		//receive info for text

				encryptBuffer = encryptText(FileBufferKey,FileBuffertext);			//add key and text to encryption buffer

				send(newSocketFD,encryptBuffer,lengthOfFile * sizeof(char),0);		//send to the socket
				shutdown(newSocketFD,2);											//cause all connections to be shut down

				exit(0);
			default:												//in parent process
				pushPid(pid);
		}

	}
	return 0; 
}
