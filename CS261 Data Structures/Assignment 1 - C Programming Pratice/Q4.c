/* CS261- Assignment 1 - Q.4*/
/* Name:Thanhbinh Truong
 * Date:10/1/17
 * Solution description: allocate and declare a struct student and filling each with an ID and score. Print the ID and score of the students, then pass the struct into Sort, and reprint the ID and scores but now it is sorted by score.
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
    int id;
    int score;
};


/*****************************
**function name: sort()
**Description: sorts the pointer(or array) based on their scores
****************************/
void sort(struct student* students, int n){
    struct student var;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (students[j].score > students[j + 1].score) {
                var = students[j];
                students[j] = students[j + 1];
                students[j + 1] = var;
            }
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 20;

    
    /*Allocate memory for n students using malloc.*/
    struct student *students = malloc(n*sizeof(struct student));

    
    /*Generate random and unique IDs and random scores for the n students, using rand().*/
    for(int i=0; i<n; i++){
        students[i].id = i;
        students[i].score = rand() % 100;
    }
    

    /*Print the contents of the array of n students.*/
    for(int i=0; i<n; i++){
        printf("ID:%d has a score of %d\n", students[i].id, students[i].score);
    }
    
    /*Pass this array along with n to the sort() function*/
    sort(students,n);

   
    /*Print the contents of the array of n students.*/
    for(int i=0; i<n; i++){
        printf("ID:%d has a score of %d\n", students[i].id, students[i].score);
    }
    
    return 0;
}
