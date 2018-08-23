TITLE Program 3 (Project3.asm)

;*********************************************************
; Thanhbinh Truong
; ID:
; CS271 Spring 2017
;*********************************************************

INCLUDE Irvine32.inc

.data
LOWERLIMIT		=		 -100
UPPERLIMIT		=		 -1

greeting1				BYTE	"Welcome to the Integer Accumulator by Thanhbinh Truong", 0
instruct1				BYTE	"Please enter numbers in [-100, -1].", 0
instruct2				BYTE	"Enter a non-negative number when you are finished to see results.", 0
instruct3				BYTE	"Enter number: ", 0

getName					BYTE	"What is your name?", 0
hello					BYTE	"Hello, ", 0

totalSum				BYTE	"The sum of your valid numbers is ", 0
totalNumbers 			BYTE	"Total valid numbers entered is  ", 0
roundedAve_prompt		BYTE	"The rounded average is	       ", 0

number					DWORD	?
byte_Count				DWORD	?
count					DWORD	1
accumulator				DWORD	0

usersName				BYTE   20 DUP(0)

roundedAve				DWORD	0
remainder				DWORD	?

neg1k					DWORD  -1000
onek					DWORD	1000
subtractor				DWORD	?
floating_point			DWORD	?

goodbye					BYTE	"Thank you for playing Integer Accumulator! It's been a pleasure to meet you, ", 0


.code
 main PROC

;*******************************************
; Program intro
;*******************************************
  	call	 CrLf
  	mov		 edx, OFFSET greeting1
  	call	 WriteString
  	call	 CrLf


;*******************************************
; Get name of user
;*******************************************
  	mov		edx, OFFSET getName
  	call	WriteString
  	call	CrLf
  	mov		edx, OFFSET usersName
  	mov		ecx, SIZEOF usersName
  	call	ReadString
  	mov		byte_Count, eax

;*******************************************
; Prompt hello greeting
;*******************************************
  	mov		edx, OFFSET hello
  	call	WriteString
  	mov		edx, OFFSET usersName
  	call	WriteString
  	call	CrLF

;*******************************************
; intructions for program
;*******************************************
  	mov		edx, OFFSET instruct1
  	call	WriteString
  	call	CrLf
  	mov		edx, OFFSET instruct2
  	call	WriteString
  	call	CrLf
  	mov		ecx, 0

;*******************************************************
; For user to enter negative numbers (loop till positive number is entered)
;*******************************************************
	userNumbers:
	mov		eax, count
	call	WriteDec
	add		eax, 1
	mov		count, eax
	mov		edx, OFFSET instruct3
	call	WriteString
	call	ReadInt
	mov		number, eax
	cmp		eax,LOWERLIMIT
	jb		accumulate;
	cmp		eax, UPPERLIMIT
	jg		accumulate
	add		eax, accumulator
	mov		accumulator, eax
	loop	userNumbers


	accumulate:
	mov		eax, count
	sub		eax, 2
	jz		sayGoodbye
	mov		eax, accumulator
	call	CrLF

;*******************************************
; Accumulate totalSum
;*******************************************
	mov		edx, OFFSET  totalSum
	call	WriteString
	mov		eax, accumulator
	call	WriteInt
	call	CrLF

;*******************************************
; Gather and Display totalNumbers entered
;*******************************************
	mov		edx, OFFSET totalNumbers
	call	WriteString
	mov		eax, count
	sub		eax, 2
	call	WriteDec
	call	CrLf

;*******************************************
; Display rounded number of integer
;*******************************************
	mov		edx, OFFSET roundedAve_prompt
	call	WriteString
	mov		eax, 0
	mov		eax, accumulator
	cdq
	mov		ebx, count
	sub		ebx, 2
	idiv	ebx
	mov		roundedAve, eax
	call	WriteInt
	call	CrLf



;*******************************************
; Goodbye prompt
;*******************************************
	sayGoodbye:
	call	CrLf
	mov		edx, OFFSET goodbye
	call	WriteString
	mov		edx, OFFSET usersName
	call	WriteString
	call	CrLf
	call	CrLf

exit
main ENDP

END main