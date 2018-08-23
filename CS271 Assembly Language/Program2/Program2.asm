TITLE Program 2  (assignment2.asm)

; Student: Thanhbinh Truong
; Class: CS 271 (400 Spring 2017)
; ID:  933233558

INCLUDE Irvine32.inc

; (set up 46 upper bound)
upperLimit = 46

.data
userName            BYTE      33 DUP(0)
numTerms            DWORD     ?

currentFib          DWORD      ?

;Introduction terms
programIntro        BYTE      "Hi! Welcome to Fibonacci Numbers programmed by Thanhbinh Truong",0
startIntro			BYTE      "First, please enter your name: ",0
greetIntro          BYTE      "Hello, ",0

;Prompts for the user to enter Fibonacci terms
prompt1             BYTE      "Now, enter the number of Fibonacci terms to be displayed [Please stay in the range of 1-46]: ",0
prompt2             BYTE      "Out of range. Again, enter a number between 1 and 46: ",0

;Prompt for the end of the program
exitProg			BYTE      "And that is Fibonacci Numbers.",0
space               BYTE      "   ",0

.code
main PROC

;Beginning introduction of the program
     mov       edx, OFFSET programIntro 
     call      WriteString
     call      CrLf

;Get user's name from user's input
     mov       edx, OFFSET startIntro
     call      WriteString
     mov       edx, OFFSET userName                    
     mov       ecx, 25									                           
     call      ReadString                        

;Greet the user with a Hello 
     mov       edx, OFFSET greetIntro
     call      WriteString
     mov       edx, OFFSET userName
     call      WriteString
     call      CrLf

;Ask the user for the number of Fibonacci terms to be displayed
     mov       edx, OFFSET prompt1
     call      WriteString
     call      ReadInt
     mov       numTerms, eax

;Start of the while loop
     whileStart:                                       
     cmp       eax,upperLimit                         
     jle       exitLoop
     mov       edx, OFFSET prompt2
     call      WriteString
     call      ReadInt
     mov       numTerms, eax
     jmp       whileStart                            
     exitLoop:

;Display all of the Fibonacci numbers on the screen
     mov       eax, 1
     mov       ebx, 0
     mov       ecx, numTerms
     .IF       numTerms < 2
     call      WriteDec
     mov       edx, OFFSET space
     call      WriteString
     .ELSE

     call      WriteDec
     mov       edx, OFFSET space
     call      WriteString
     mov       eax, numTerms
     mov       ebx, 1
     sub       eax, ebx
     mov       ecx, eax
     mov       eax, 1
     mov       ebx, 0

     fibLoop:
     mov       currentFib, eax
     mov       eax, ebx
     mov       ebx, currentFib
     add       eax, ebx
     call      WriteDec
     mov       edx, OFFSET space
     call      WriteString
     loop      fibLoop
     .ENDIF
     call      CrLf


;End of program
     mov       edx, OFFSET exitProg
     call      WriteString
     call      CrLf
	exit	  ;exit program
main ENDP

END main