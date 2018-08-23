/* CS261- Assignment 1 - Q.1*/
/* Name:Thanhbinh Truong
 * Date:10/1/17
 * Solution description: Allocates memory by using pointers for a struct. Then the pointer will be filled with ID numbers and scores. The ids and score will then be printed and so will the average, minimum and maximum score.
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


struct student{
    int id;
    int score;
};

struct student* allocate(){
    /*Allocate memory for ten students*/
    struct student *stuptr = malloc(10*sizeof(struct student));
    
    /*return the pointer*/
    return stuptr;
}


/*****************************
**function name: generate()
**Description: generate a unique and random ID and random score for the pointer passed as an argument
 ****************************/
void generate(struct student* students){
    /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    
    int i;
    srand(time(NULL));
    
    for(i=0; i<10; i++){
        students[i].id = i;
        students[i].score = rand() % 100;
    }
    
}


/*****************************
 **function name: output()
 **Description: Print each Id and corresponding score
 ****************************/
void output(struct student* students){
    /*Output information about the ten students in the format:
     ID1 Score1
     ID2 score2
     ID3 score3
     ...
     ID10 score10*/
    
    int n = 10;
    
    for(int i=0; i<n; i++){
        printf("ID:%d Score: %d\n", students[i].id + 1, students[i].score);
    }
    
    
}


/*****************************
 **function name: summary()
 **Description: Calculate the minimum, maximum and average score and print the results
 ****************************/
void summary(struct student* students){
    /*Compute and print the minimum, maximum and average scores of the ten students*/
    
    int i;
    double avg=0;
    int min = students[0].score;
    int max = students[0].score;
    
    for(i=0; i<10; i++){
        if(students[i].score < min)
            min = students[i].score;

        if(students[i].score > max)
            max = students[i].score;
        
        avg += students[i].score;
    }
    
    avg = avg / 10;
    
    printf(" min: %d\n max: %d\n avg=%f\n", min, max, avg);
    
}


/*****************************
 **function name: deallocate()
 **Description: Deallocate tha struct memory
 ****************************/
void deallocate(struct student* stud){
    if(stud != NULL)
        free(stud);  /*Deallocate memory from stud*/
}

int main(){
    struct student* stud = allocate(); /*call allocate*/
    
    generate(stud); /*call generate*/
    
    output(stud); /*call output*/
    
    summary(stud);/*call summary*/
    
    deallocate(stud);/*call deallocate*/
    
    return 0;
}
