#include <stdio.h>
#include "anydata.h"

int main()
{

/* FROM Aalto:
 *
 * Implement functions to handle an array that can store different numerical values. The types and function signatures are 
 * already defined in  anydata.h. Implement in anydata.c the following functions:
 *
 * -   setDouble, setInt and setByte to form an element of type AnyData to the array.
 * -   printValue to print the given AnyData value. (print-functions for individual types are already given in the file.)
 * -   calcSum to calculate a sum of elements in the array. Pointers to the first and last element are given as arguments. 
 *             Function returns the sum as AnyData object that is as "small" data type as possible. If all the elements are of type byte, 
 *             then return element of type byte, if all the elements are of types int and byte then return element of type int, 
 *             if any of the elements is of type double, then return element with double value.
 */


    /* Feel free to modify this function to test different things */
    /* For example, you can temporarily hide unimplemented functions
     * inside comments */

    AnyData array[5];

    array[0] = setDouble(3.14159);
    array[1] = setByte(2);
    array[2] = setByte(3);
    array[3] = setInt(10000);
    array[4] = setDouble(5.555);

    for (int i = 0; i < 5; i++) {
        printValue(array[i]);
        printf("\n");
    }

    printValue(calcSum(&array[1], &array[3]));
}
