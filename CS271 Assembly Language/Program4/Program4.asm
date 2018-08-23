TITLE Assignment #4

; Author: Thanhbinh Truong
; Description: Write a program to calculate composite numbers.  First, the user is instructed to enter the number of composites to be displayed, 
; and is prompted to enter an integer in the range [1 .. 400].
; The program then calculates and displays all of the composite numbers up to and including the nth composite.  
; The results should be displayed 10 composites per line with at least 3 blank_spaces between the numbers.

INCLUDE Irvine32.inc

.data
intro					   BYTE	  "Composites by Thanhbinh Truong", 0

instructions_1			   BYTE	  "Please enter a number between [1, 400] ",0
goodbye					   BYTE	  "That is the Composite program, goodbye! ", 0

number					   DWORD  ?
count					   DWORD  1

error_1				       BYTE   "Number is too small ", 0
error_2				       BYTE   "Number is too big ", 0
blank_spaces			   BYTE	  "  ", 0

user_Num				   DWORD  ?
user_NumTemp			   DWORD  ?

inner_LoopCount			   DWORD  ?
outer_LoopCount			   DWORD  ?

outer_Compare			   DWORD  ?
inner_Compare			   DWORD  ?
writeCount				   DWORD  0


;******************************
;Constant
;******************************
LOWERLIMIT		=		 1
UPPERLIMIT		=		 400


.code
 main PROC

	call introduction
	call getUserData
		;validate
	call showComposites
		;validate is composite
	call farewell

	exit
main ENDP


introduction PROC

;******************************
;Intro
;******************************

	call	 CrLf
	mov		 edx, OFFSET intro
	call	 WriteString
	call	 CrLf

	mov		ecx, 0
	ret

introduction ENDP

getUserData PROC

;******************************
;User number loop
;******************************
user_NumLoop:
		mov		eax, count
		add		eax, 1
		mov		count, eax
		mov		edx, OFFSET instructions_1
		call	WriteString
		call	CrLf
		call    ReadInt
		mov     user_Num, eax
		cmp		eax,LOWERLIMIT
		jb		errorBelow
		cmp		eax, UPPERLIMIT
		jg		errorAbove
		jmp		continue

;******************************
;Validate
;******************************

	errorBelow:
			mov		edx, OFFSET error_1
			call	WriteString
			call	CrLf
			jmp		user_NumLoop
	errorAbove:
			mov		edx, OFFSET error_2
			call	WriteString
			call	CrLf
			jmp		user_NumLoop
	continue:
			mov		ecx, 4
			mov		user_NumTemp, ecx

			cmp		ecx, user_Num
			ja		farewell

	ret
getUserData ENDP


showComposites PROC

;******************************
;Inner Loop
;******************************
		mov		eax, user_Num
		sub		eax, 2
		mov		inner_LoopCount, eax

;******************************
;Outer Loop
;******************************
		mov		eax, user_Num
		sub		eax, 3
		mov		outer_LoopCount, eax
		mov		ecx, outer_LoopCount
		mov		eax, 4
		mov		outer_Compare, eax

		mov		eax, 2
		mov		inner_Compare, eax
		call	CrLf

	outerLoop:
		skipCarry:
			mov		eax, 2
			mov		inner_Compare, eax
			mov		eax, outer_Compare
			push	ecx
			push	eax
			mov		ecx, inner_LoopCount

		isComposite:
			mov		eax, outer_Compare
			mov		edx, 0
			div		inner_Compare
			cmp		edx, 0
			jne		skipPrint

			;******************************
			;Loop composite
			;******************************
				mov		eax, outer_Compare
				call	WriteDec
				mov		edx, OFFSET blank_spaces
				call	WriteString
				mov		ebx, writeCount
				inc		ebx
				mov		writeCount, ebx
				cmp		ebx, 10
				jne		exitInnerLoop
				call	CrLf
				mov		writeCount,esi
				jmp		exitInnerLoop

				skipPrint:

				mov		ebx, inner_Compare

				sub		eax, 1
				cmp		eax, ebx
				jae		skipIncrement
				add		eax, 1
				mov		inner_Compare, eax
				skipIncrement:
				loop isComposite
				exitInnerLoop:

				pop		eax
				pop		ecx
				inc		eax
				mov		outer_Compare, eax
				loop	outerLoop

	ret
showComposites ENDP

farewell PROC
;******************************
;Goodbye
;******************************
	call	CrLf
	mov		edx, OFFSET goodbye
	call	WriteString
	call	CrLf
	call	CrLf
	exit
farewell ENDP
END main