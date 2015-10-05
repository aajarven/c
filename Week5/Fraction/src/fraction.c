#include <stdlib.h>
#include <stdio.h>
#include "fraction.h"

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;
};

unsigned int gcd(unsigned int u, unsigned int v);

unsigned int Fraction_getNumerator(Fraction* f){
    return f->numerator;
}

unsigned int Fraction_getDenominator(Fraction* f){
    return f->denominator;
}

Fraction* Fraction_new(unsigned int numerator, unsigned int denominator){
    struct Fraction *uusi = malloc(sizeof(Fraction));
    uusi->numerator = numerator;
    uusi->denominator = denominator;
    return uusi;
}

void Fraction_free(Fraction* f){
    free(f);
}

int Fraction_compare(const Fraction* first, const Fraction* second){
    double ero = (double) first->numerator / first->denominator - (double) second->numerator / second->denominator;
    if(ero < 0) {
        return -1;
    } else if (ero == 0){
        return 0;
    } else {
        return 1;
    }
}

void Fraction_print(const Fraction* f){
    printf("%d / %d\n", f->numerator, f->denominator);
}


/* Algorithm for determining greatest common divisor */
/* The function returns gcd between the two parameters, u and v */
/* Taken from http://en.wikipedia.org/wiki/Binary_GCD_algorithm */
unsigned int gcd(unsigned int u, unsigned int v)
{
    // simple cases (termination)
    if (u == v)
        return u;

    if (u == 0)
        return v;

    if (v == 0)
        return u;

    // look for factors of 2
    if (~u & 1) // u is even
    {
        if (v & 1) // v is odd
            return gcd(u >> 1, v);
        else // both u and v are even
            return gcd(u >> 1, v >> 1) << 1;
    }

    if (~v & 1) // u is odd, v is even
        return gcd(u, v >> 1);

    // reduce larger argument
    if (u > v)
        return gcd((u - v) >> 1, v);

    return gcd((v - u) >> 1, u);
}

void Fraction_reduce(Fraction* f){
    unsigned int syt = gcd(f->numerator, f->denominator);
    f->numerator /= syt;
    f->denominator /= syt; 
}


Fraction* Fraction_add(const Fraction* first, const Fraction* second){
    struct Fraction *uusi = Fraction_new(first->numerator * second->denominator + second -> numerator * first->denominator, first->denominator*second->denominator);
    Fraction_reduce(uusi);
    return uusi;
}

Fraction* Fraction_subtract(const Fraction* first, const Fraction* second){
    struct Fraction *uusi = Fraction_new(first->numerator * second->denominator - second -> numerator * first->denominator, first->denominator*second->denominator);
    Fraction_reduce(uusi);
    return uusi;
}

Fraction* Fraction_multiply(const Fraction* first, const Fraction* second){
    struct Fraction *uusi = Fraction_new(first->numerator * second->numerator, first->denominator*second->denominator);
    Fraction_reduce(uusi);
    return uusi;
}

Fraction* Fraction_divide(const Fraction* first, const Fraction* second){
    struct Fraction *uusi = Fraction_new(first->numerator * second->denominator, first->denominator*second->numerator);
    Fraction_reduce(uusi);
    return uusi;
}
