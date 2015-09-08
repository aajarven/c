#include <stdio.h>
#include "source.h"

/*Task is from Aalto C Programming Basics course.
 * Objective: string
 * Write a function int is_palindrome(const char* p) that returns 1 if the given string is palindrome and 0 if it is not. 
 * Palindrome is a string which reads the same backward or forward. For example "race car" and "saippuakauppias" are palindromes. */

int main(void) {
    
    char test[][10] = { "testi", "sokos", "toimii", "12345678" };
    for (int i = 0; i < 4; i++) {
        printf("%s is palindrome: %d\n", test[i], is_palindrome(test[i]));
    }
    return 0;
}
