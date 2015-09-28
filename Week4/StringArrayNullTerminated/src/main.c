#include <stdio.h>
#include "source.h"

int main()
{
    /* Write function void locate_string, that find the string from the stringarray. 
     * The array and the string are given as parameters. 
     * The last element in the string array is NULL.
     * If the string is found from the array, function returns the first found position of the string 
     *in the array. 
     * If the string is not found, function returns -1.
     */

    char *str[] = {"one","two","three","four", NULL};
    int index;


    index= locate_string(str, "one");
    printf("String one is in the position %d\n", index);

    index= locate_string(str, "three");
    printf("String three is in the position %d\n", index);

    index=locate_string(str, "five");
    printf("String five is in the position %d\n", index);

    return 0;
}



