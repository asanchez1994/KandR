/* 
*   Replace tabs with spaces
*/

#include <stdio.h>
#define SPACES 32

bool isTab(char input);
void printFourSpaces(void);

int main(){
    
    int input;

    while((input = getchar()) != EOF){

        if (isTab(input) == true)
            printFourSpaces();
        else
            putchar(input);

    }

    return 0;
}

bool isTab(char input){
    if (input == '\t')
        return true;
    else 
        return false;
}

void printFourSpaces(void){
    
    for (int i = 0; i < 4; ++i){
        putchar(SPACES);
    }
}

