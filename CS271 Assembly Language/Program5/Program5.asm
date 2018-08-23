TITLE Program 5

; Name: Thanhbinh Truong
; Date: 05/28/17
; Description: 
; Get user request in the range [min = 10 .. max = 200].
; Display the list of integers before sorting, after sorted(largest to smallest), and integer's median.


INCLUDE Irvine32.inc

;******************************************
; Constants for the min/max range of numbers and low/high of randomly generated numbers
;******************************************

    MIN = 10
    MAX = 200
    RANDOMLOW = 100
    RANDOMHIGH = 999

.data
	intro           BYTE    "Welcome to the Sorting Random Integers", 0
	goodbye1		BYTE	"Thank you for using the Sorting Random Integer program!", 0
                            
    numChoice       BYTE    "How many numbers should be generated [10 .. 200]: ", 0
    invalidChoice	BYTE    "Invalid input", 0

    unsort			BYTE    "The unsorted random numbers are: ", 0
	sorted          BYTE    "The sorted list of the random numbers are: ", 0
	median	        BYTE    "The median of the random numbers is: ", 0 

    input           DWORD   ?
    temp	        DWORD   ?

	array           DWORD   MAX DUP(0)   
    maxPerLine      DWORD   10;

    allign          BYTE    "   ", 0 
    allign2			BYTE    "  ", 0  
    allign3		    BYTE    " ", 0   
    
.code
main PROC
  
    call    Randomize
    call    introduction								;displays introduction
    
    push    OFFSET input
    call    getNum										;get user input
    
    push    input										;generate random numbers inside array
    push    OFFSET array
    call    fillArray
    
    mov     edx, OFFSET unsort							;print array (unsorted)
    call    WriteString
    call    CrLf
    
    push    input
    push    OFFSET array
    call    displayArray
    
    push    OFFSET array								;sort randomized generated numbers inside array
    push    0
    mov     eax, input
    dec     eax
    push    eax 
    call    quickSort
    
    mov     edx, OFFSET median							;calculate and print median
    call    WriteString
    
    push    input
    push    OFFSET array
    call    print_Med
    
    mov     edx, OFFSET sorted							;print array after randomized numbers have been sorted
    call    WriteString
    call    CrLf
    
    push    input
    push    OFFSET array
    call    displayArray 

	mov		edx, OFFSET goodbye1
	call	WriteString
	call	Crlf

    exit 
main ENDP

;*********************************
;Introduction function
;*********************************

introduction PROC
    mov     edx, OFFSET intro
    call    WriteString
    call    CrLf
    
    ret
introduction ENDP 


;*********************************
;User input
;*********************************
getNum PROC USES eax edx ebp

    mov     ebp, esp
    
    promptLoop:
        mov     edx, OFFSET numChoice
        call    WriteString
        call    ReadInt
        
        cmp     eax, MAX
        jle     lessThanMax
        jg      notValid
        
    lessThanMax:
        cmp     eax, MIN
        jl      notValid
        jmp     Valid
        
	notValid:
        mov     edx, OFFSET invalidChoice
        call    WriteString
        call    CrLf
        jmp     promptLoop
        
    Valid:
        mov     ebx, [ebp+16] 
        mov     [ebx], eax    
        call    CrLf
      
    ret 4
getNum ENDP


;*********************************
;Fill array with randomly generated numbers
;*********************************

fillArray PROC USES esi ecx eax ebp
   
    mov     ebp, esp
    mov     esi, [ebp+20] 
    mov     ecx, [ebp+24]

    mov     eax, RANDOMHIGH
    sub     eax, RANDOMLOW
    inc     eax
    
    fill:
        call    RandomRange
        add     eax, RANDOMLOW
        mov     [esi], eax
        add     esi, SIZEOF DWORD
        loop    fill
    
    ret 8
fillArray ENDP


;*********************************
;Recursive quicksort algorithm()
;*********************************
quickSort PROC USES eax ebx ecx esi ebp
  
    mov     ebp, esp						;set up stack frame
    sub     esp, 4        

    mov     esi, [ebp+32] 
    mov     eax, [ebp+28]
    cmp     eax, [ebp+24]
    jl      sort   
    jmp     sortEnd
    
    sort:
        lea     esi, [ebp-4]
        push    esi         
        push    [ebp+32]    
        push    [ebp+28]    
        push    [ebp+24]    
        call    partition   
        
        push    [ebp+32]
        push    [ebp+28]
        mov     eax, [ebp-4]
        dec     eax
        push    eax         ;p-1
        call    quickSort
        
        push    [ebp+32]
        mov     eax, [ebp-4]
        inc     eax
        push    eax         ;p+1
        push    [ebp+24]    ;end
        call    quickSort
        
    sortEnd:
    mov     esp, ebp
    ret 12
quickSort ENDP


;*********************************
;Swap elements within array
;*********************************

swap PROC USES eax ebx ecx esi ebp

    mov     ebp, esp
    sub     esp, 4        
    mov     esi, [ebp+32] 

    mov     eax, [ebp+28]      
    mov     ebx, SIZEOF DWORD
    mul     ebx
    mov     ebx, [esi+eax]
    mov     DWORD PTR [ebp-4], ebx
    
    mov     eax, [ebp+24]   
    mov     ebx, SIZEOF DWORD
    mul     ebx
    mov     ecx, [esi+eax]
    mov     eax, [ebp+28]   
    mul     ebx
    mov     [esi+eax], ecx
    
    mov     eax, [ebp+24]
    mov     ebx, SIZEOF DWORD
    mul     ebx
    mov     ecx, [ebp-4]
    mov     [esi+eax], ecx
    
    mov     esp, ebp
    ret 12
swap ENDP


;**************************************
;Align the numbers in highest to lowest
;**************************************
alignNum PROC USES eax edx ebp

    mov     ebp, esp
    
    mov     eax, [ebp+16] 
    cmp     eax, 10
    jl      single
    cmp     eax, 1000
    jl      double
    cmp     eax, 10000
    jl      triple
    
    single:
    mov     edx, OFFSET allign
    call    WriteString
    jmp     endAllign
    
    double:
    mov     edx, OFFSET allign2
    call    WriteString
    jmp     endAllign
    
    triple:
    mov     edx, OFFSET allign3
    call    WriteString
    jmp     endAllign
    
    endAllign:
    ret 4

alignNum ENDP


;*********************************
;Prints the array
;*********************************

displayArray PROC USES ebx ecx esi ebp ;prints array
    
    mov     ebp, esp
    mov     esi, [ebp+20] 
    mov     ecx, [ebp+24] 
    mov     ebx, 0 
    
    display:
        mov     eax, [esi] 
        call    WriteDec
        
        mov     temp, eax
        push    temp
        call    alignNum
        
        add     esi, SIZEOF DWORD
        
        inc     ebx
        cmp     ebx, maxPerLine
        jl      next
        
        newLine:
            call    CrLf
            mov     ebx, 0
            
        next:
            loop    display
        
    call    CrLf
    call    CrLf
    ret 8

displayArray ENDP

;*********************************
;Partition function 
;*********************************

partition PROC USES eax ebx ecx esi ebp
    
    mov     ebp, esp
    sub     esp, 8        
    mov     esi, [ebp+32] 
    
    mov     eax, [ebp+28]
    mov     ebx, SIZEOF DWORD
    mul     ebx
    mov     eax, [esi+eax]
    mov     [ebp-4], eax
    
    mov     eax, [ebp+28]
    mov     [ebp-8], eax
    inc     eax
    mov     ecx, eax  
    
    outerLoop:
        cmp     ecx, [ebp+24] 
        jg      endLoop
        
        inner:
        mov     eax, ecx       
        mov     ebx, SIZEOF DWORD
        mul     ebx
        mov     eax, [esi+eax]       
        cmp     eax, [ebp-4]   
        jl      next         
        
        push    [ebp+32]    ;swap
        mov     eax, [ebp-8]
        inc     eax
        push    eax         
        push    ecx         
        call    swap
        push    [ebp+32]    
        push    [ebp-8]     
        mov     eax, [ebp-8]
        inc     eax
        push    eax   
        call    swap

        mov     eax, [ebp-8]
        inc     eax
        mov     [ebp-8], eax

        next:
        inc     ecx     
        jmp     outerLoop
        
        
    endLoop:
    mov     eax, [ebp+36]
    mov     ebx, [ebp-8]
    mov     [eax], ebx
    mov     esp, ebp
    ret 12
partition ENDP


;*********************************
;Prints out the median number within the array
;*********************************

print_Med PROC ;prints median
    pushad
    
    mov     ebp, esp
    mov     esi, [ebp+36] 
    mov     ecx, [ebp+40] 

    cdq
    mov     eax, ecx
    mov     ecx, 2
    div     ecx
    mov     ecx, eax
    
    cmp     edx, 0 
    jz      isEven
    jmp     isOdd
    
    isEven:
    mov     ebx, SIZEOF DWORD
    mul     ebx
    mov     ebx, [esi+eax]  
    
    mov     eax, ecx
    dec     eax
    mov     ecx, SIZEOF DWORD
    mul     ecx
    mov     ecx, [esi+eax] 
    
    cdq
    mov     eax, ebx
    add     eax, ecx
    mov     ebx, 2
    div     ebx
    
    jmp     printMedian
    
    isOdd:
    mov     ebx, SIZEOF DWORD
    mul     ebx
    mov     ebx, [esi+eax]
    mov     eax, ebx
    
    printMedian:
    call    WriteDec
    call    CrLf
    call    CrLf
    
    popad
    ret     8
print_Med ENDP


END main