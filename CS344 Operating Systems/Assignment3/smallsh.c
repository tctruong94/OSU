/*******************************************
**Thanhbinh Truong
**CS344
**Assignment 3: Program Smallsh
**March 5th, 2018
********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_ARGS 512

//Global Variables
struct Pid_Stack_Background PidStack;

int lastFGStatus;                               //fg == foreground

bool ForegroundOnly = false;


/*******************************************
**name: inputs
**description: a struct containing a parsed line
********************************************/
struct inputs
{
    bool Background;
    int numOfArgs;

    char InputFile[128];
    char OutputFile[128];
    char Command[1028];
    char *Arguments[512];
};


/*******************************************
**name: Pid_Stack_Background
**descrption: stack that is used to handle the background processes
********************************************/
struct Pid_Stack_Background
{
    int Num_Of_Back_Pid;
    pid_t BackgroundPids[MAX_ARGS];
};


/*******************************************
**name: setPidStack
**description: Creates a pid stack with the value (-1) in each position
********************************************/
void setPidStack()
{
    PidStack.Num_Of_Back_Pid = -1;

    int i;
    for(i = 0; i < MAX_ARGS; i++)
    {
        PidStack.BackgroundPids[i] = -1;
    }
}


/*******************************************
**name: add_Pid
**description: puts a Pid into the stack
********************************************/
void add_Pid(pid_t pId)
{
    PidStack.BackgroundPids[++(PidStack.Num_Of_Back_Pid)] = pId;
}


/*******************************************
**name: removeBackgroundPid
**description: Removes pid when a background process from earlier ends
********************************************/
void removeBackgroundPid(pid_t pId)
{
    int i;
    int pidPos;

    for(i = 0; i < PidStack.Num_Of_Back_Pid + 1;i++)
    {
        if(PidStack.BackgroundPids[i] == pId)
        {
            pidPos = i;
            break;
        }
    }

    for(i = pidPos; i < PidStack.Num_Of_Back_Pid + 1;i++)
    {
        PidStack.BackgroundPids[i] = PidStack.BackgroundPids[i+1];
    }
    

    PidStack.Num_Of_Back_Pid--;
}


/*******************************************
**name: popBackgroundPid
**description: pop pid from the top of the stack
********************************************/
pid_t popBackgroundPid()
{
    return PidStack.BackgroundPids[PidStack.Num_Of_Back_Pid--];
}


/*******************************************
**name: returnTopPid
**description: returns the top of the stack
********************************************/
pid_t returnTopPid()
{
    return PidStack.BackgroundPids[PidStack.Num_Of_Back_Pid];
}


/*******************************************
**name: checkSpecialChar
**description: function to check for &, >, or < 
********************************************/
bool checkSpecialChar(char *enter)
{
    bool found = false;
 
    if(enter == NULL)                                                 //Checks if value is NULL for seg.fault reasons
    {
        return true;
    }

    if(enter[0] == '&')                                               //check for background
    {
        found = true;
    }
    else if(enter[0] == '<')                                          //check for input
    {
        found = true;
    }
    else if(enter[0] == '>')                                          //check for output
    {
        found = true;
    }
    else if(enter[0] == '#')                                          //check for comment
    {
        found = true;
    }

    return found;
}

/*******************************************
**name: parseCommandLine
**description: parse input for struct input to hold the arguments
********************************************/
void parseCommandLine(char* enteredInput,struct inputs* val)
{
    char Buffer[1028];
    char *Temp;

    char *input_File;
    char *output_File;

    val->numOfArgs = 0;

    enteredInput[strlen(enteredInput) -1] = '\0';                         //removes \n 

    if(enteredInput[strlen(enteredInput) -1] == '&')                      //checks if the background has been enabled
    {
        val->Background = true;                                         //background is enabled
        enteredInput[strlen(enteredInput) -1] = '\0';
    }
    else
    {
        val->Background = false;                                        //background is disabled
    }


    memset(Buffer,'\0',sizeof(Buffer));                                 //clears out the buffer to grab command
    strcpy(Buffer,enteredInput);                                         //copies enteredInput into Buffer
    strtok(Buffer," ");                                                 //grabs command part of input;
    strcpy(val->Command,Buffer);                                        //puts command place in command object


   
    memset(Buffer,'\0',sizeof(Buffer));                                 //clears out buffer for inputFile
    strcpy(Buffer,enteredInput);                                         //copies args into enteredInput
    input_File = strstr(Buffer,"<");                                    // grabs stdin (anything after <)
    if(input_File != NULL)
    {
        memmove(input_File, input_File+2, strlen(input_File));          //grabs everything but < and puts ut in a string
        strtok(input_File," ");
        input_File[strlen(input_File)] = '\0';                          //add end character
        strcpy(val->InputFile,input_File);                              //copies into inputFile
    }


    memset(Buffer,'\0',sizeof(Buffer));                                 //clears out the buffer for outputfile
    strcpy(Buffer,enteredInput);                                         //copies args into enteredInput
    output_File = strstr(Buffer,">");                                   //grabs stdout (anything after >)
    if(output_File != NULL)
    {
        memmove(output_File, output_File+2, strlen(output_File));       //grabs everything but > and puts it in a string
        strtok(output_File," ");
        output_File[strlen(output_File)] = '\0';                        //add end character
        strcpy(val->OutputFile,output_File);                            //copies into OutputFile
    }
    

    memset(Buffer,'\0',sizeof(Buffer));

    strcpy(Buffer,enteredInput);
    strtok(Buffer," ");                                                 //splits at the first space

    Temp = strtok(NULL,"");                                             //contains arguments after first space


    if(checkSpecialChar(Temp) == false)                                 //checks if any arguments exist
    {
        strcpy(Buffer,Temp);
        strtok(Buffer,"<>&#");
        strtok(Buffer," ");                                             //take out spaces

        val->Arguments[0] = Buffer;
        val->numOfArgs = 1;

        Temp = strtok(NULL," ");

        while(Temp != NULL)                                             //while temp isnt empty, put each argument into a list
        {
            val->Arguments[val->numOfArgs] = Temp;                      //each argument going into arguments object
            val->numOfArgs++;

            Temp = strtok(NULL," ");                                    //take out spaces in temp file
        }
        val->Arguments[val->numOfArgs] = strtok(NULL, "");

    }
}


/*******************************************
**name: createArgumentList
**description: Creates argument list for execvp
********************************************/
void createArgumentList(struct inputs* val,char** Args)
{
    int i;

    Args[0] = val->Command;                                     //first argument == the command
    for(i = 0;i < val->numOfArgs ;i++)
    {
        if(getenv(val->Arguments[i]) != NULL)
        {
            Args[i+1] = getenv(val->Arguments[i]);              
        }
        else if(strcmp(val->Arguments[i],"$$") == 0)
        {
            sprintf(Args[i+1],"%d",getpid());
        }
        else
        {
            Args[i+1] = (val->Arguments[i]);
        }
    }
    Args[i+1] = NULL;
}


/*******************************************
**name: redirectInputOutput
**description: redirects input and output for program
********************************************/
void redirectInputOutput(struct inputs* val)
{
    int inputDescriptor = STDIN_FILENO;
    int outputDescriptor = STDOUT_FILENO;

    if(val->InputFile[0] != '\0')                                           //check if input is not empty
    {
        inputDescriptor = open(val->InputFile,O_RDONLY);                    //if not empty, then open file

        if(inputDescriptor < 0)                                             //if opened but nothing found
        {    
            printf("File could not be found.\n");                           //print error and exit
            exit(1);
        }

        dup2(inputDescriptor,0);                                            //duplicate inputdescriptor
        close(inputDescriptor);                                             //close file just to be safe
    }

    if(val->OutputFile[0] != '\0')                                          //check if output is not empty
    {
        outputDescriptor = open(val->OutputFile,O_WRONLY | O_CREAT | O_TRUNC,0644); // create new file or edit.

        if(outputDescriptor < 0)                                            //check if ouput has invalid value
        {
            printf("Error opening or creating file.");                      //print error if invalid, exit after
            exit(1);
        }

        dup2(outputDescriptor,1);
        close(outputDescriptor);
    }
}


/*******************************************
**name: processCommand
**description: forks from parent to start running the command
********************************************/
void processCommand(struct inputs* val)
{
    int ProcessStatus;
    pid_t pid = fork();

    char *ArgList[512];

    switch(pid)
    {
        case -1:                                                            //error case
            printf("Something went wrong with fork().\n");                  //print error and exit with 1
            exit(1);
            break;

        case 0:                                                             //child case
            redirectInputOutput(val);

            createArgumentList(val,ArgList);                                //create the list of arguments
            execvp(val->Command, ArgList);                                  //run the command with the arguments
            
            printf("Command not found.\n");
            exit(1);
            break;

        default:                                                            //default == Parent case
            if(val->Background == true && ForegroundOnly == false)
            {
                add_Pid(pid);
                printf("Background Pid is %d\n",returnTopPid());
            }
            else
            {
                waitpid(pid,&ProcessStatus,0);                              //wait for background process to complete
                lastFGStatus = ProcessStatus;
            }
            break;
    }
}



/*******************************************
**name: navigateDirectory
**description: Allows navigation through file directories
********************************************/
int navigateDirectory(char* enteredInput)
{
    char NewPath[1028];
    char* homePath = getenv("HOME");                               //initiates to home path

    enteredInput[strlen(enteredInput) -1] = '\0';

    if(strcmp(enteredInput,"cd") == 0){
        if(chdir(homePath) != 0)                                   //if directory cannot be found
        {
            printf("Directory:%s not found.\n",homePath);
            return 1;
        }
        return 0;
    }

    memset(NewPath,'\0',sizeof(NewPath));

    strtok(enteredInput," ");                                        //removes spacing
    strcpy(enteredInput,strtok(NULL,""));


    if(enteredInput[0] == '/')
    {
        sprintf(NewPath,"%s%s",homePath,enteredInput);               //nagivate to specified directory

    }
    else if(strcmp(enteredInput,"..") == 0)                          //enter previous folder
    {
        strcpy(NewPath,enteredInput);
    }
    else if(strcmp(enteredInput,"~") == 0)                           //enter previous folder
    {
        strcpy(NewPath,homePath);
    }
    else if(enteredInput[0] == '.' && enteredInput[1] == '/')         //return current directory
    {
        sprintf(NewPath,"%s",enteredInput);
    }
    else
    {
        sprintf(NewPath,"%s",enteredInput);                          //go to specified directory
    }

    if(chdir(NewPath) != 0)                                         //directory cannot be found
    {
        printf("Directory:%s not found.\n",NewPath);
        return 1;
    }
    return 0;
}


/*******************************************
**name: childSignal
**description: signal handler for ctrl-c (foreground)
********************************************/
void termSignal(int signalValue)
{
    printf("\nterminated by signal %d\n",signalValue);                              //print out which signal terminated it
}


/*******************************************
**name: stopSignal
**description: signal handler for crtl-z
********************************************/
void stopSignal(int signalValue)
{
    if(ForegroundOnly == false)
    {
        char* message = ("\nEntering foreground-only mode\n");              //entering foreground
        write(STDOUT_FILENO, message, 50);
        ForegroundOnly = true;
    }
    else
    {
        char* message = "\nExiting foreground-only mode\n";                 //exiting foreground
        write(STDOUT_FILENO, message, 31);
        ForegroundOnly = false;
    }
}


/*******************************************
**name: childSignal
**description: Signal handler for when the child process ends
********************************************/
void childSignal(int signalValue)
{
    int i;
    int ChildStatus;
    
    pid_t ChildPid;

    for(i = 0;i < PidStack.Num_Of_Back_Pid + 1;i++)                         //loop to find which child process ended
    {
        ChildPid = waitpid(PidStack.BackgroundPids[i],&ChildStatus,WNOHANG);

        if((ChildStatus == 0 || ChildStatus == 1) && ChildPid != 0 )        //check if exited
        {
            fprintf(stdout,"\nBackground pid %d is done: exit value %d\n",ChildPid,ChildStatus);
            removeBackgroundPid(ChildPid);
        }
        else if(ChildPid != 0)                                              //if terminated by signal
        { 
            fprintf(stdout,"\nBackground pid %d is done: terminated by signal %d\n", ChildPid, ChildStatus);
            removeBackgroundPid(ChildPid);
        }
    }
}


/*******************************************
**name: CheckBackgroundMode
**description: switches modes depending on returned signal
********************************************/
void CheckBackgroundMode()
{
    if(WTERMSIG(lastFGStatus) == 11 && ForegroundOnly == true)              //if foreground == true, switch modes
    {
        printf("\nExiting foreground-only mode\n");
        ForegroundOnly = false;
    }
    else if(WTERMSIG(lastFGStatus) == 11 && ForegroundOnly == false)        //if foreground == false, switch mode
    {
        printf("\nEntering foreground-only mode (& is now ignored)\n");
        ForegroundOnly = true;
    }
}


/*******************************************
**name: killBackGround
**description: kill background processes for ending program
********************************************/
void killBackGround()
{
    int i;

    for(i = 0;i < PidStack.Num_Of_Back_Pid + 1;i++)
    {
        kill(PidStack.BackgroundPids[i], SIGINT);                           //kill all background processes
    }
}


/*******************************************
**name: clearAll
**description: frees input objects
********************************************/
void clearAll(struct inputs* val)
{
    val->Background = false;
    memset(val->InputFile,'\0',sizeof(val->InputFile));                     //clear inputFile
    memset(val->OutputFile,'\0',sizeof(val->OutputFile));                   //clear outputFile
    memset(val->Command,'\0',sizeof(val->Command));                         //clear command

    free(val);                                                              //free up val
}


/*******************************************
**name: startShell
**description: function to run the actual shell
********************************************/
void startShell()
{
    int ForegroundStatus;
    char enteredInput[1028];
    struct inputs *val;


    //all the signals
    struct sigaction StopSignal;
    StopSignal.sa_handler = stopSignal;
    StopSignal.sa_flags = 0;

    struct sigaction ChildSignal;
    ChildSignal.sa_handler = childSignal;
    StopSignal.sa_flags = 0;

    struct sigaction TermSignal;
    TermSignal.sa_handler = termSignal;
    StopSignal.sa_flags = 0;

    do
    {
        sigaction(SIGTSTP,&StopSignal, NULL);                       //set the signal handlers to NULL
        sigaction(SIGINT,&TermSignal, NULL);
        sigaction(SIGCHLD,&ChildSignal, NULL);

        CheckBackgroundMode();

        fflush(stdout);                                             //flushing output and input for buffer
        fflush(stdin);

        printf(": ");                                               //print : to user for commands/arguments

        memset(enteredInput,'\0',sizeof(enteredInput));

        fgets(enteredInput,sizeof(enteredInput),stdin);               //get the command line from the buffer
        
        fflush(stdout);                                             //always flush after using the buffer
        fflush(stdin);

        if(strncmp(enteredInput,"exit",4) == 0)                      //if command is exit, exit program
        {
            killBackGround();
            exit(0);
        }
        else if(strncmp(enteredInput, "#",1) == 0)                   //if first char is #, ignore bc it is a comment
        {
            continue;                                               //continue for next command line
        }
        else if(strncmp(enteredInput,"cd", 2) == 0)                  //if command is cd, then change directory
        {
            navigateDirectory(enteredInput);
        }
        else if(strncmp(enteredInput,"status",6) == 0)               //if the command is status, return last fg status
        {
            if(WEXITSTATUS(lastFGStatus))
            {
                ForegroundStatus = WEXITSTATUS(lastFGStatus);       //check if last FG exited
            }
            else
            {
                ForegroundStatus = WTERMSIG(lastFGStatus);          //check if last FG terminated from a signal
            }
            printf("exit value %d\n",ForegroundStatus);
        }
        else
        {
            if(enteredInput != NULL && strcmp(enteredInput,"") != 0)  //if command line is none o the above, read in command
            {
                val = malloc(1 * sizeof(struct inputs)); 
                parseCommandLine(enteredInput,val);                        //parse command
                processCommand(val);                                //run the command
                clearAll(val);                            //clear all inputs
            }
            else
            {
                continue;
            }
        }
    }
    while(true);
}


/*******************************************
**name: main
**description: runs the whole shell program
********************************************/
int main(void)
{
    setPidStack();
    startShell();
    return 0;
}