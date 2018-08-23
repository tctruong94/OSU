/* CS261- Assignment 1 - Q.2*/
/* Name:Thanhbinh Truong
 * Date:10/1/17
 * Solution description: Declare 3 integers and print their value. Then, run the foo function and print the value of the returned value. Lastly, reprint the values of the 3 integers.
 */

#include <stdio.h>
#include <stdlib.h>


/*****************************
 **function name: foo()
 **Description: Take in 2 pointers and 1 variable and modify their values. Return the c value
 ****************************/
int foo(int* a, int* b, int c){
    *a = (*a) * 2;/*Set a to double its original value*/
    
    *b = (*b) / 2;/*Set b to half its original value*/
    
    c = (*a) + (*b);/*Assign a+b to c*/
    
    return c;/*Return c*/
}

int main(){
    int x = 5;
    int y = 6;
    int z = 7; /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    
    printf("%d\n%d\n%d\n", x, y, z); /*Print the values of x, y and z*/
    
    int temp = foo(&x, &y, z); /*Call foo() appropriately, passing x,y,z as parameters*/
    
    printf("%d \n", temp); /*Print the value returned by foo*/
    
    printf("%d\n%d\n%d\n", x, y, z); /*Print the values of x, y and z again*/
    
    /*Is the return value different than the value of z?  Why?*/
    
    /* Yes, the return value is different than the value of z because unlike x and y, which
     was passed by reference, z was passed by value. Passing by value only gives the function
     a copy of the value rather than the value itself. So when the return value is different,
     is is returning z within the function, yet when z is called later, it is returning the 
     orignal z when it was declared. */
    return 0;
}


