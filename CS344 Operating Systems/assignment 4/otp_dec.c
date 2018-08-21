/************************************
** Name: Thanhbinh Truong
** Class: CS344
** Assignment: Program OTP
** Date: 03/14/2018
************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <fcntl.h>


struct fileObj
{
	char* textName;						//name of textfile
	char* keyName;						//name of keyfile

	int textVal;
	int keyVal;
	int lengthOfFile;					//length of both textVal and keyVal

};
typedef struct fileObj fileObj;

char* PROGNAME = "DEC_CLIENT";

void error(const char *message);
void progNameError(const char* message);
void checkArgc(int argc);
void closeEncryptedObj(fileObj* Obj);
int getLengthOfFile(fileObj* Obj);

fileObj* setEncryptionObj(char** argv);

char* readFile(fileObj* Obj, char fd);


/************************************
** Name: checkArgc
** Description: checks if 3 arguments, if is then illustrate error
************************************/
void checkArgc(int argc)
{
    if(argc == 3)
    {
        progNameError("Invalid number of arguments.");
        exit(1);
    }
}


/************************************
** Name: readFile
** Description: read file content and return the data inside
************************************/
char* readFile(fileObj* Obj, char fd)
{
	int Buffer;
	int fileDescriptor;

	char* fileInfo = malloc( Obj->lengthOfFile * sizeof(char*));

	if(fd == 'K')												//check of text or key
	{
		fileDescriptor = Obj->keyVal;
	}
	else if(fd == 'T')
	{
		fileDescriptor = Obj->textVal;
	}

	if(read(fileDescriptor,fileInfo,Obj->lengthOfFile) < 0)		//read content & return address
	{
		progNameError("Could not open text file");
	}
	return fileInfo;
}


/************************************
** Name: getLengthOfFile
** Description: checks if key == text size * sets length of file
************************************/
int getLengthOfFile(fileObj* Obj)
{
	struct stat Key;
	struct stat Text;

	if(stat(Obj->keyName,&Key) < 0)							//stat error on keyName file
	{
		progNameError("Error getting stats of Keyfile.");
	}

	if(stat(Obj->textName,&Text) < 0)						//stat error on textName file
	{
		progNameError("Error getting stats of Cipherfile.");
	}


	if(Key.st_size -1 < Text.st_size -1)					//if key != text, return error
	{
		progNameError("KeyFile too short.");
	}
	else
	{
		Obj->lengthOfFile = Text.st_size -1;
	}
	return Obj->lengthOfFile;
}


/************************************
** Name: setEncrpytionObj
** Description: creates object for the file data to be stored
************************************/
fileObj* setEncryptionObj(char** argv)
{
	fileObj* file = malloc(1 * sizeof(fileObj));

	file->textName = argv[1];						//set textName for first argument
	file->keyName = argv[2];						//set keyName for second argument

	file->textVal = open(argv[1],O_RDONLY);			//read only text file 

	if(file->textVal < 0)
	{
		progNameError("Could not open cipherfile file");
	}

	file->keyVal = open(argv[2],O_RDONLY);			//read only key file

	if(file->keyVal < 0)
	{
		progNameError("Could not open keyTxt file");
	}
	return file;
}


/************************************
** Name: CloseEncryptionObjFD
** Description: clean and close up key and text files
************************************/
void closeEncryptedObj(fileObj* Obj)
{
	close(Obj->textVal);							
	close(Obj->keyVal);

	Obj->textVal = -1;
	Obj->keyVal = -1;
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
void error(const char *message)
{ 
	perror(message);
	exit(0);
}


int main(int argc, char* argv[])
{
	int socketFD;							//needed variables
	int portNumber;

	char buffer[256];						//initiate size of buffer
	char allowServer;
    
	struct hostent* serverHostInfo;
	struct sockaddr_in serverAddress;

	checkArgc(argc);

	fileObj* FileInfo = setEncryptionObj(argv);	//create file

	getLengthOfFile(FileInfo);					//get length of the file

	char* keyTxt = readFile(FileInfo,'K');									//read in the key Info 
	char* textTxt= readFile(FileInfo,'T');									//read in the text Info

	char* inputtedText = malloc( FileInfo->lengthOfFile * sizeof(char*));	//create space that has the size of the file

	memset((char*)&serverAddress, '\0', sizeof(serverAddress)); 			//clears server address
	portNumber = atoi(argv[3]);												//get from argument and convert string to int
	serverAddress.sin_family = AF_INET; 									//Network capable socket
	serverAddress.sin_port = htons(portNumber); 							//save port number

	
	serverHostInfo = gethostbyname("localhost");							//convert machine name to address

	if (serverHostInfo == NULL) 											//if serviceHostInfo is empty
	{ 
		fprintf(stderr, "Error: no such host\n");
		exit(1);
	}
	memcpy((char*)&serverAddress.sin_addr.s_addr, (char*)serverHostInfo->h_addr, serverHostInfo->h_length);

	socketFD = socket(AF_INET, SOCK_STREAM, 0);								//set port and socket, if socket does not open then error message
	
	if (socketFD < 0)
	{ 
		error("Eror opening socket");
	}
	
	if (connect(socketFD, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) //error on connection
	{
	 	error("Error connecting");
	}

	send(socketFD,&(PROGNAME[0]), sizeof(char),0);			//send message to socket
	recv(socketFD,&allowServer,sizeof(char),0);				//receive message from socket

	if(allowServer != 'Y')									//if server is not allowed, exit
	{
		close(socketFD);
		progNameError("not a server");
	}

	send(socketFD,&(FileInfo->lengthOfFile), sizeof(FileInfo->lengthOfFile),0);		//send file length
	send(socketFD,textTxt,FileInfo->lengthOfFile * sizeof(char),0); 				//send text to server
	send(socketFD,keyTxt,FileInfo->lengthOfFile * sizeof(char),0); 					//send key to server

	recv(socketFD,inputtedText,FileInfo->lengthOfFile * sizeof(char),0);			//receive text
	printf("%s\n",inputtedText);													//print decrypted text

	closeEncryptedObj(FileInfo);					//close objects
	free(keyTxt);									//free all data to avoid segmentation fault
	free(textTxt);
	free(FileInfo);
	free(inputtedText);

	return 0;
}
