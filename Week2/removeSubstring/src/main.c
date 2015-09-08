#include <stdio.h>
#include "source.h"

int main()
{
    /* Write function void remove_substr(char *str, const char *sub) that removes the instances of string 'sub' from string 'str'. 
     * String 'str' is modified directly, and as a result of this function it will become shorter (if there were any instances of 'sub' present). 
     * For example, a string  "one two one twotwo three" will become  " two  twotwo three". 
     *  Note that the spaces do not have any special role in these string manipulation operations -- they are just normal characters like everything else.
     */

    char str[] = "one two one twotwo three";

    remove_substr(str, "one");
    printf("remove_substr: %s\n", str);
    
    return 0;
}
