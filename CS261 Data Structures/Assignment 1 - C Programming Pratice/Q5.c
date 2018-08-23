/* CS261- Assignment 1 - Q.5*/
/* Name:
 * Date:
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
    return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
    return ch-'A'+'a';
}

void sticky(char* word){
    for (int i = 0; word[i] != '\0'; i++) {
        int isEven = i % 2 == 0 ? 1 : 0;
        if (!isEven && (word[i] >= 'A' && word[i] <= 'Z')) {
            word[i] += 32;
        } else if (isEven && (word[i] > 'a' && word[i] <= 'z')) {
            word[i] -= 32;
        }
    }
}
    /*Convert to sticky caps*/

int main(){
    
    char string[20];
    scanf("%20s", string);/*Read word from the keyboard using scanf*/
    
    sticky(string);
        
    /*Call sticky*/
    
    printf("%s", string);
    /*Print the new word*/
    
    return 0;
}
