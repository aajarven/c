#include <stdio.h>
#include "fraction.h"

/* Part of this task is from Aalto C Programming Basics course.
 * Implement a new number type, fraction, that consist of unsigned int numerator and unisigned int denominator. 
 * Implement following functions in fraction.c. 
 * Function Fraction* Fraction_new(int numerator, int denominator) allocates a new fraction from heap, sets its value as given in parameters and returns a pointer to the allocated fraction.
 * Function void Fraction_free(Fraction* f) releases the memory used by the fraction.
 * Function int Fraction_compare(Fraction* first, Fraction* second) returns -1 if first < second, 0 if first == second and 1 if first > second.
 * Fuction void Fraction_reduce(Fraction* f) reduces the value to the smallest possible denominator. For example 2/4 should be 1/2 after this function.
 * You will need to find the greatest common divisor for the numerator and denominator and you can use function gcd for that.
 * Function Fraction* Fraction_add(Fraction* first, Fraction* second) adds values first and second
 * and returns the result in a new object allocated from the heap. You should recude the result to smallest possible denominator.
 * Function Fraction* Fraction_subtract(Fraction* first, Fraction* second) subtracts second value from first
 * and returns the result in a new object allocated from the heap. You should recude the result to smallest possible denominator. 
 * Function Fraction* Fraction_multiply(Fraction* first, Fraction* second) multiplies values first and second
 * and returns the result in a new object allocated from the heap. You should recude the result to smallest possible denominator.
 * Function Fraction* Fraction_divide(Fraction* first, Fraction* second) divides the first value by the second
 * and returns the result in a new object allocated from the heap. You should recude the result to smallest possible denominator.
 * Function Fraction_print can be useful for printing and it is given for you.*/


int main(void) {
    
    Fraction* frac1 = Fraction_new(2, 5);
    Fraction* frac2 = Fraction_new(3, 4);
    
    printf("Result of comparison: %d\n", Fraction_compare(frac1, frac2));
    
    Fraction* sum = Fraction_add(frac1, frac2);
    Fraction_print(sum);
    Fraction_free(sum);
    sum = Fraction_subtract(frac2, frac1);
    Fraction_print(sum);
    Fraction_free(sum);
    sum = Fraction_multiply(frac1, frac2);
    Fraction_print(sum);
    Fraction_free(sum);
    sum = Fraction_divide(frac1, frac2);
    Fraction_print(sum);
    
    Fraction_free(frac1);
    Fraction_free(frac2);
    Fraction_free(sum);
    
    return 0;
}
