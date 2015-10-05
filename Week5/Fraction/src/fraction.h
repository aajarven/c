#ifndef FRACTION_H
#define	FRACTION_H

typedef struct Fraction Fraction;

unsigned int Fraction_getNumerator(Fraction* f);
unsigned int Fraction_getDenominator(Fraction* f);
Fraction* Fraction_new(unsigned int numerator, unsigned int denominator);
void Fraction_free(Fraction* f);
int Fraction_compare(const Fraction* first, const Fraction* second);
void Fraction_print(const Fraction* f);
void Fraction_reduce(Fraction* f);
Fraction* Fraction_add(const Fraction* first, const Fraction* second);
Fraction* Fraction_subtract(const Fraction* first, const Fraction* second);
Fraction* Fraction_multiply(const Fraction* first, const Fraction* second);
Fraction* Fraction_divide(const Fraction* first, const Fraction* second);

#endif	/* FRACTION_H */

