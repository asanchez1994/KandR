/* 
*  Command line application to remove
*  c-style comments from source code. 
*  Submitted to CS50 as final project 
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int curr_char;
    int prev_char;
    int inline_comment = 0;
    int old_comment = 0;
    int go_counter = 0;
    
    while ((curr_char = getchar()) != EOF){
        
        if (prev_char == '/') {
            if (curr_char == '/'){
                 inline_comment++;
            } else if (curr_char == '*'){
                old_comment++;
            }
            prev_char = curr_char;
            continue;
        } else if (inline_comment){ 
            if (curr_char == '\n') {
                prev_char = curr_char;
                inline_comment = 0;
                continue;
            } else {
               prev_char = curr_char;
               continue;
            }
        } else if (old_comment){
            if (prev_char == '*' && curr_char == '/'){
                old_comment = 0;
                prev_char = curr_char;
                continue;
            } else {
                prev_char = curr_char;
                continue;
            }
        }
    
        
        if (!go_counter && curr_char != '/'){
            go_counter++;
            putchar(curr_char);
            continue;
        } else if (!go_counter && curr_char == '/'){
            go_counter++;
            prev_char = curr_char;
            continue; 
        }
        
        if (go_counter == 1){
            prev_char = curr_char;
            go_counter++;
            continue;
        }

        putchar(prev_char);

        prev_char = curr_char;
        go_counter++;
    }

    putchar('\n');

    return EXIT_SUCCESS;
}
