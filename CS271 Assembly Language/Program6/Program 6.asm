;TITLE: Program 6A    (program6.asm)

 
; Name: Thanhbinh Truong 
; Assignment: Program 6A         
; Description: 
;	Implement and test your own ReadVal and WriteVal procedures for unsigned integers
;	Implement macros getString and displayString.
;	The macros may use Irvine’s ReadString to get input from the user, and WriteString to display output.
;		-) GetString should display a prompt, then get the user’s keyboard input into a memory location.
;		-) DisplayString should the string stored in a specified memory location.
;		-) ReadVal should invoke the getString macro to get the user’s string of digits. 
;		-) It should then convert the digit string to numeric, while validating the user’s input.
;		-) WriteVal should convert a numeric value to a string of digits, and invoke the displayString macro to produce the output.
;	Write a small test program that gets 10 valid integers from the user and stores the numeric values in an array.
;	The program then displays the integers, their sum, and their average.


INCLUDE Irvine32.inc 

;***************************************
;Constant
;**************************************
MAX = 10

;***************************************
;Macros: DisplayString
;Description: Should the string stored in a specified memory location
;***************************************
displayString	MACRO stringResult
	push edx
	mov	 edx, OFFSET stringResult
	call WriteString
	pop edx

ENDM

;****************************************
;Macros: getString
;Description: Display a prompt, then get the user's keyboard input and put into a memory location
;****************************************
getString	MACRO string, length
	push edx
	push ecx
	mov edx, string
	mov ecx, length
	call ReadString
	pop ecx
	pop edx

ENDM


.data

intro1		BYTE	"Program: Low-Level I/O procedures			by:Thanhbinh Truong", 0

instruct1	BYTE	"Please provide 15 unsigned decimal integers.", 0
instruct2	BYTE	"Each number needs to be small enough to fit inside a 32 bit register.", 0
instruct3	BYTE	"After you have finished inputting the raw numbers I will display a list", 0
instruct4	BYTE	"of the integers, their sum, and their average value.", 0

extraCred	BYTE	"Extra Credit #1: Number each line of user input and display a running subtotal of the user's numbers.", 0

prompt      BYTE	"Please enter an unsigned number: ", 0

error1		BYTE	"ERROR: You did not enter an unsigned number or your number was too big.", 0
error2		BYTE	"Please try again. ", 0

input		BYTE	"You entered the following numbers: ", 0
summ	    BYTE	"The sum of these numbers is: ", 0
avg			BYTE	"The average is: ", 0
total		BYTE	"Total Integers entered: ",0

goodbye		BYTE	"Thanks for playing!", 0

buffer		BYTE	 200 DUP(0)	
temp		BYTE	 32 DUP(0)

average		DWORD	?
sum			DWORD	?
array       DWORD	MAX    DUP(?)        ;array containing 10 elements

lineNum		DWORD	?
bracket		BYTE	") ",0



.code

main PROC

	mov edx, OFFSET intro1							;Display program title
	call WriteString
	call CrLf
	call CrLf

	mov	edx, OFFSET instruct1						;Display instructions
	call WriteString
	call CrLf

	mov	edx, OFFSET instruct2
	call WriteString
	call CrLf

	mov	edx, OFFSET instruct3
	call WriteString
	call CrLf

	mov	edx, OFFSET instruct4
	call WriteString
	call CrLf

	mov	edx, OFFSET extraCred						;Display extra credit #1
	call WriteString
	call CrLf
	call CrLf


	mov edi, OFFSET array							;set edi to array offset
	mov ecx, MAX

	inputLoop:
		displayString prompt						;Display user input(macro)
		push OFFSET buffer
		push SIZEOF buffer
		call ReadVal

		mov eax, DWORD PTR buffer
		mov [edi], eax
		add edi, 4									;go to next element in array (4 since DWORD = 4bytes)
		loop inputLoop								;loop until 10 values are entered

		mov ecx, MAX
		mov esi, OFFSET array
		mov ebx, 0
		call CrLf
		displayString input							;Display user input(macro)
		call CrLf

	sumLoop:
		mov eax, [esi]
		add ebx, eax								;add eax to ebx to sum total
		push eax
		push OFFSET temp
		call WriteVal
		add esi, 4									;go to next element in array (4 since DWORD = 4bytes)
		loop sumLoop

		;show sum
		mov eax, ebx								;move total to eax for display
		mov sum, eax
		call CrLf
		displayString summ
		push sum
		push OFFSET temp
		call WriteVal

		mov ebx, MAX								;setting ebx to 10
		mov edx, 0
		div ebx

		mov ecx, eax								;if rounding is necessary
		mov eax, edx
		mov edx, 2
		mul edx
		cmp eax, ebx
		mov eax, ecx
		mov average, eax
		jb noRound
		inc eax
		mov average, eax

	noRound:										;if no rounding is necessary
		displayString avg							;display average message
		push average								;push average by value
		push OFFSET temp
		call WriteVal

		displayString total							;display total numbers that was entered
		mov eax, lineNum
		call WriteDec
		call CrLf
		call CrLf

		mov edx, OFFSET goodbye						;display goodbye
		call WriteString
		call CrLf
		call CrLf

	exit

main ENDP


;****************************************
;function: readVal
;Description: Invoke getString(MACRO) to get user's string of digits. 
;			  It should then convert the digit string to numeric, while validating the user's input.
;****************************************
readVal PROC

	push ebp
	mov ebp, esp
	pushad

	getNum:
		mov eax, 1				;extra credit
		add lineNum, eax
		mov eax, lineNum
		call WriteDec

		mov edx, OFFSET bracket ;display bracket after input line number
		call WriteString
									
		mov edx, [ebp+12]		;buffer address
		mov ecx, [ebp+8]
		getString edx, ecx		;get user inputs
			
		mov esi, edx
		mov eax, 0
		mov ecx, 0
		mov ebx, MAX

	loadbytes:
		lodsb					;loads a byte from ESI into AX
		cmp ax, 0				;check for end of string
		je endString

		cmp ax, 57
		ja invalidInput			;error message if above

		cmp ax, 48
		jb invalidInput			;error message if below

		sub ax, 48
		xchg eax, ecx
		mul ebx
		jc invalidInput			;carry flag is set
		jnc valid				;carry flag is NOT set

	invalidInput:
		mov edx, OFFSET error1
		call WriteString
		call CrLf

		mov edx, OFFSET error2
		call WriteString
		call CrLf
		jmp getNum

	valid:
		add eax, ecx			;add digit to total
		xchg eax, ecx
		jmp loadbytes
	
	endString:
		xchg ecx, eax
		mov DWORD PTR buffer, eax
		popad
		pop ebp
		ret 8

readVal ENDP


;****************************************
;function: writeVal
;Description:  Convert numeric value to a string of digits
;			   Invoke displayString(MACRO) to produce
;****************************************

WriteVal PROC
	push ebp
	mov ebp, esp					;set stack frame pointer
	pushad

	mov eax, [ebp+12]				;convert integer to string
	mov edi, [ebp+8]
	mov ebx, MAX
	push 0

	convert:
		mov edx, 0
		div ebx
		add edx, 48
		push edx					;push digit into stack
		cmp eax, 0					;check for end
		jne convert					;loop until end

	move:
		pop [edi]
		mov eax, [edi]
		inc edi
		cmp eax, 0					;check for end
		jne move					;loop until end

	mov edx, [ebp+8]
	displayString OFFSET temp
	call CrLf

	popad
	pop ebp
	ret 8
		
WriteVal ENDP

END main