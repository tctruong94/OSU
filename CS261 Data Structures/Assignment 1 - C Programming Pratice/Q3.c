/* CS261- Assignment 1 - Q.3*/
/* Name:Thanhbinh Truong
 * Date:10/1/17
 * Solution description: Allocate and declare an array of n integers. The array will then be filled with random numbers, printed, sorted, and reprinted.
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>


/*****************************
 **function name: sort()
 **Description: Takes in a pointer and an integer to sort the array.
 ****************************/
void sort(int* number, int n){
    /*Sort the given array number , of length n*/
    int var = 0, j, i;
    
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            if (number[j] > number[j + 1]) {
                var = number[j];
                number[j] = number[j + 1];
                number[j + 1] = var;
            }
        }
    }
}

int main(){
    int n = 20; /*Declare an integer n and assign it a value of 20.*/
    
    int *arr=malloc(n*sizeof(double)); /*Allocate memory for an array of n integers using malloc.*/
    
    for(int i=0; i<20; i++){
        arr[i] = rand() % 10;
    }/*Fill this array with random numbers, using rand().*/
    
    for(int i=0;i<20;i++){
        printf("%d ", arr[i]);
    }/*Print the contents of the array.*/
    
    printf("\n");
    
    sort(arr, n);/*Pass this array along with n to the sort() function of part a.*/
    
    for(int i=0;i<20;i++){
        printf("%d ", arr[i]);
    }/*Print the contents of the array.*/
    
    return 0;
}
