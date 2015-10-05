/*  From Aalto
 *
 * Implement in arraytool.h header the following three macros:
 *
 * CHECK(cond, msg) that will check logical condition cond, and if the condition fails, output string msg 
 *                  to standard output stream. This is like the assert macro, but does not terminate the 
 *                  execution of the program if condition fails. Example: CHECK(5 > 10, "5 > 10 failed\n");
 *
 * MAKE_ARRAY(type, n) that will create a dynamically allocated array, that contains n obejcts of type type. 
 *                  The macro returns pointer to the allocated memory. Example: void *ptr = MAKE_ARRAY(int, 10);
 *
 * ARRAY_IDX(type, array, i) that will access the given array at index i (count starting from 0, as always), 
 *                  with given type. Example: ARRAY_IDX(int, ptr, i) = i * 2;
 *
 * When the three macros are correctly implemented, src/main.c should allocate an int array for 10 members, 
 * initialize it, and print its contents. 
 * The main function also demonstrates the use of CHECK macro with failing condition.
 *
 */



#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "arraytool.h"

int main(void)
{

#ifdef CHECK
    CHECK(5 > 10, "5 > 10 failed\n");
#endif

#ifdef MAKE_ARRAY
    void *ptr = MAKE_ARRAY(int, 10);
#else
    printf("Implement MAKE_ARRAY first");
#endif

#ifdef ARRAY_IDX
    for (int i = 0; i < 10; i++) {
        ARRAY_IDX(int, ptr, i) = i;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", ARRAY_IDX(int, ptr, i));
    }
    free(ptr);
#else
    printf("Implement ARRAY_IDX first");
#endif
}
