; Author: Thanhbinh Truong
; Email: Truontha@oregonstate.edu
: class: CS_271_400_S2017
; Program 1
; Due Date: 04/16/2017


INCLUDE Irvine32.inc

.data
intro		BYTE	"Elementary Arithmetic      by Thanhbinh Truong",0
instruct	BYTE	"Takes the 2 ints and calcualtes the sum, difference, product and quotient",0
num1		DWORD	?	;First int
num2		DWORD	?	;Second int
prompt1		BYTE	"Enter the 1st number: ",0
prompt2		BYTE	"Enter the 2nd number(> or = first int): ",0
sum			DWORD	?
difference	DWORD	?
product		DWORD	?
quotient	DWORD	?
remainder	DWORD	?
sumSign	    BYTE	"sum: ",0
diffSign	BYTE	"difference: ",0
prodSign	BYTE	"prodoct: ",0
quotSign	BYTE	"quotient: ",0
resSign	    BYTE	"remainder: ",0
complete	BYTE	"Complete",0

.code
main PROC

;Introduction
	mov		edx, OFFSET	intro
	call	WriteString
	call	CrLf

;Descrption
	mov		edx, OFFSET instruct
	call	WriteString
	call	CrLf

L1:

;User input
	mov		edx, OFFSET prompt1
	call	WriteString
	call	ReadInt
	mov		num1, eax
	call	CrLf
	mov		edx, OFFSET prompt2
	call	WriteString
	call	ReadInt
	mov		num2, eax
	call	CrLf

	cmp		eax, num1 ;extra credit
	jg		L1

;calculate sum
	mov		eax, num1
	add		eax, num2 
	mov		sum, eax

;calculate difference
	mov		eax, num1
	mov		ebx, num2
	sub		eax, ebx
	mov		difference, eax

;calculate product
	mov		eax, num1 
	mov		ebx, num2
	mul		ebx
	mov		product, eax

;calculate quotient & remainder
	
	mov		eax, num1
	mov		ebx, num2
	mov		edx, 0
	div		ebx
	mov		quotient, eax
	mov		remainder, edx

;print sum
	mov 	edx, OFFSET sumSign	
	call	WriteString
	mov		edx, OFFSET sum
	call	WriteInt
	call	CrLf

;print difference
	mov		edx, OFFSET	diffSign
	call	WriteString
	mov		edx, OFFSET difference
	call	WriteInt
	call	CrLf

;print product
	mov		edx, OFFSET prodSign
	call	WriteString
	mov		edx, OFFSET product
	call	WriteInt
	call	CrLf

	
;print quotient
	mov		edx, OFFSET quotSign
	call	WriteString
	mov		edx, OFFSET quotient
	call	WriteInt
	call	CrLf

;print remainder
	mov		edx, OFFSET resSign
	call	WriteString
	mov		edx, OFFSET remainder
	call	WriteInt
	call	CrLf

;print goodbye
	mov		edx, OFFSET complete
	call	WriteString
	call	CrLf

	exit

main ENDP

END main