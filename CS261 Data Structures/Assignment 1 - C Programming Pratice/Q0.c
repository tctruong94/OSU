/* CS261- Assignment 1 - Q. 0*/
/* Name: Thanhbinh Truong
 * Date: 9/28/17
 * Solution description: The program below will illustrate the use of a pointer and function. It will begin by declaring an integer, printing its address, passing it inside the foo function and reprinting the value of the variable once foo returns.
 */

#include <stdio.h>
#include <stdlib.h>

/****************************
**function: FooA()
**Description: Returns the value a pointer is pointing to, the address pointed by the pointer, and the address of the pointer itself.
 ***************************/
void fooA(int* iptr){
    printf("Value pointed to by iptr: %d\n", *iptr);  /*Print the value pointed to by iptr*/
    printf("Address pointed to by iptr: %p\n", iptr); /*Print the address pointed to by iptr*/
    printf("Address of iptr: %p\n", &iptr);           /*Print the address of iptr itself*/
    
}

int main(){
    
    int x = 2;                          /*declare an integer x*/
    
    printf("Address of x: %p\n", &x);   /*print the address of x*/
    
    fooA(&x);                           /*Call fooA() with the address of x*/
    
    printf("value of x: %d\n", x);      /*print the value of x*/
    
    return 0;
}
