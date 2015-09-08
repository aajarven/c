#include <stdio.h>
#include "source.h"

/*Task is from Aalto C Programming Basics course.
 * Objective: string
 * Write a function void turn_around(char* p) that reverses the string pointed by parameter p. 
 * The resulting string is produced in the place of the old string. 
 * For example, string "Example string", should become "gnirts elpmaxE"*/

int main(void) {
    
    char str[] = "Example string";
    turn_around(str);
    printf("%s\n", str);
    return 0;
}
