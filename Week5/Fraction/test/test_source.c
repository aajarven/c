#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/fraction.h"

START_TEST(test_new) {
    for (int i = 0; i < 3; i++) {
        unsigned int num = rand() % 20, den = rand() % 20;
        Fraction *f = Fraction_new(num, den);
        fail_unless(f != NULL, "Fraction_new returned NULL.\n");
        
        unsigned int refnum = Fraction_getNumerator(f);
        unsigned int refden = Fraction_getDenominator(f);
        if (refnum != num || refden != den) {
            Fraction_free(f);
            fail("When called Fraction_new(%d,%d), you created fraction %d/%d\n",
                    num, den, refnum, refden);
        }
        Fraction_free(f);
    }
}
END_TEST


START_TEST(test_compare) {
    unsigned int a = 20 + (rand() % 10); 
    Fraction *fa = Fraction_new(a, a+1);
    fail_unless(fa != NULL, "Implement Fraction_new first.\n");
    Fraction *fb = Fraction_new(a, a+2);
    
    fail_unless(Fraction_compare(fa, fb) == 1, "Comparing %u/%u and %u/%u should return 1\n",
            a, a+1, a, a+2);
    fail_unless(Fraction_compare(fb, fa) == -1, "Comparing %u/%u and %u/%u should return -1\n",
            a, a+2, a, a+1);
    
    Fraction *faa = Fraction_new(2*a, 2*(a+1));
    fail_unless(Fraction_compare(fa, faa) == 0, "Comparing %u/%u and %u/%u should return 0\n",
            a, a+1, 2*a, 2*(a+1));
    Fraction_free(fa);
    Fraction_free(fb);
    Fraction_free(faa);
}
END_TEST

START_TEST(test_reduce) {
    Fraction *fa = Fraction_new(6, 12);
    fail_unless(fa != NULL, "Implement Fraction_new first.\n");   
    Fraction_reduce(fa);
    unsigned int refnum = Fraction_getNumerator(fa);
    unsigned int refden = Fraction_getDenominator(fa);

    if (refnum != 1 || refden != 2) {
        fail("Reducing 6/12 should result in 1/2. You had %d/%d.\n", refnum, refden);
    }
    
    unsigned int mul1 = rand() % 5 + 1;
    unsigned int mul2 = rand() % 20 + 5;
    Fraction *fb = Fraction_new(mul1, mul2*mul1);
    Fraction_reduce(fb);
    refnum = Fraction_getNumerator(fb);
    refden = Fraction_getDenominator(fb);
    if (refnum != 1 || refden != mul2) {
        fail("Reducing %d/%d should result in 1/%d. You had %d/%d.\n",
                mul1, mul1*mul2, mul2, refnum, refden);
    }
    
    Fraction_free(fa);
    Fraction_free(fb);
}
END_TEST

START_TEST(test_add) {
    Fraction *fa = Fraction_new(2, 3);
    fail_unless(fa != NULL, "Implement Fraction_new first.\n");
    Fraction *fb = Fraction_new(3, 4);
    Fraction *fm = Fraction_new(17, 12);
    Fraction *fn = Fraction_new(75, 36);
    Fraction *fs = Fraction_add(fa, fb);
    
    fail_unless(fs != NULL, "Fraction_add returned NULL.\n");
    
    unsigned int refnum = Fraction_getNumerator(fs);
    unsigned int refden = Fraction_getDenominator(fs);
    
    if (refnum != 17 || refden != 12) {
        fail("Sum of 2/3 and 3/4 should be 17/12. You had %d/%d.\n", refnum, refden);
    }
    Fraction_free(fs);
    
    fs = Fraction_add(fm, fa);
    refnum = Fraction_getNumerator(fs);
    refden = Fraction_getDenominator(fs);
    if (refnum != 25 || refden != 12) {
        fail("Sum of 17/12 and 2/3 should be 25/12. You had %d/%d.\n", refnum, refden);
    }
    Fraction_free(fs);
    
    fs = Fraction_add(fm, fb);
    refnum = Fraction_getNumerator(fs);
    refden = Fraction_getDenominator(fs);
    if (refnum != 13 || refden != 6) {
        fail("Sum of 17/12 and 3/4 should be 13/6. You had %d/%d.\n", refnum, refden);
    }
    Fraction_free(fs);
    
    fs = Fraction_add(fm, fn);
    refnum = Fraction_getNumerator(fs);
    refden = Fraction_getDenominator(fs);
    if (refnum != 7 || refden != 2) {
        fail("Sum of 17/12 and 75/36 should be 7/2. You had %d/%d.\n", refnum, refden);
    }
    
    Fraction_free(fa);
    Fraction_free(fb);
    Fraction_free(fm);
    Fraction_free(fn);
    Fraction_free(fs);
}
END_TEST

START_TEST(test_subtract) {
    Fraction *fa = Fraction_new(2, 3);
    fail_unless(fa != NULL, "Implement Fraction_new first.\n");
    Fraction *fb = Fraction_new(3, 4);
    Fraction *fm = Fraction_new(17, 12);
    Fraction *fn = Fraction_new(75, 36);
    Fraction *fs = Fraction_subtract(fb, fa);
    
    fail_unless(fs != NULL, "Fraction_subtract returned NULL.\n");
    
    unsigned int refnum = Fraction_getNumerator(fs);
    unsigned int refden = Fraction_getDenominator(fs);
    
    if (refnum != 1 || refden != 12) {
        fail("Difference of 3/4 and 2/3 should be 1/12. You had %d/%d.\n", refnum, refden);
    }
    Fraction_free(fs);
    
    fs = Fraction_subtract(fm, fa);
    refnum = Fraction_getNumerator(fs);
    refden = Fraction_getDenominator(fs);
    if (refnum != 3 || refden != 4) {
        fail("Difference of 17/12 and 2/3 should be 3/4. You had %d/%d.\n", refnum, refden);
    }
    Fraction_free(fs);
    
    fs = Fraction_subtract(fm, fb);
    refnum = Fraction_getNumerator(fs);
    refden = Fraction_getDenominator(fs);
    if (refnum != 2 || refden != 3) {
        fail("Difference of 17/12 and 3/4 should be 2/3. You had %d/%d.\n", refnum, refden);
    }
    Fraction_free(fs);
    
    fs = Fraction_subtract(fn, fm);
    refnum = Fraction_getNumerator(fs);
    refden = Fraction_getDenominator(fs);
    if (refnum != 2 || refden != 3) {
        fail("Difference of 75/36 and 17/12 should be 2/3. You had %d/%d.\n", refnum, refden);
    }
    
    Fraction_free(fa);
    Fraction_free(fb);
    Fraction_free(fm);
    Fraction_free(fn);
    Fraction_free(fs);
}
END_TEST

START_TEST(test_multiply) {
    Fraction *fa = Fraction_new(2, 3);
    fail_unless(fa != NULL, "Implement Fraction_new first.\n");
    Fraction *fb = Fraction_new(3, 4);
    Fraction *fm = Fraction_new(17, 12);
    Fraction *fn = Fraction_new(75, 36);
    Fraction *fs = Fraction_multiply(fb, fa);
    
    fail_unless(fs != NULL, "Fraction_multiply returned NULL.\n");
    
    unsigned int refnum = Fraction_getNumerator(fs);
    unsigned int refden = Fraction_getDenominator(fs);
    
    if (refnum != 1 || refden != 2) {
        fail("Product of 3/4 and 2/3 should be 1/2. You had %d/%d.\n", refnum, refden);
    }
    Fraction_free(fs);
    
    fs = Fraction_multiply(fm, fa);
    refnum = Fraction_getNumerator(fs);
    refden = Fraction_getDenominator(fs);
    if (refnum != 17 || refden != 18) {
        fail("Product of 17/12 and 2/3 should be 17/18. You had %d/%d.\n", refnum, refden);
    }
    Fraction_free(fs);
    
    fs = Fraction_multiply(fm, fb);
    refnum = Fraction_getNumerator(fs);
    refden = Fraction_getDenominator(fs);
    if (refnum != 17 || refden != 16) {
        fail("Product of 17/12 and 3/4 should be 17/16. You had %d/%d.\n", refnum, refden);
    }
    Fraction_free(fs);
    
    fs = Fraction_multiply(fn, fm);
    refnum = Fraction_getNumerator(fs);
    refden = Fraction_getDenominator(fs);
    if (refnum != 425 || refden != 144) {
        fail("Product of 75/36 and 17/12 should be 425/144. You had %d/%d.\n", refnum, refden);
    }
    
    Fraction_free(fa);
    Fraction_free(fb);
    Fraction_free(fm);
    Fraction_free(fn);
    Fraction_free(fs);
}
END_TEST

START_TEST(test_divide) {
    Fraction *fa = Fraction_new(2, 3);
    fail_unless(fa != NULL, "Implement Fraction_new first.\n");
    Fraction *fb = Fraction_new(3, 4);
    Fraction *fm = Fraction_new(17, 12);
    Fraction *fn = Fraction_new(75, 36);
    Fraction *fs = Fraction_divide(fb, fa);
    
    fail_unless(fs != NULL, "Fraction_divide returned NULL.\n");
    
    unsigned int refnum = Fraction_getNumerator(fs);
    unsigned int refden = Fraction_getDenominator(fs);
    
    if (refnum != 9 || refden != 8) {
        fail("Quotient of 3/4 and 2/3 should be 9/8. You had %d/%d.\n", refnum, refden);
    }
    Fraction_free(fs);
    
    fs = Fraction_divide(fm, fa);
    refnum = Fraction_getNumerator(fs);
    refden = Fraction_getDenominator(fs);
    if (refnum != 17 || refden != 8) {
        fail("Quotient of 17/12 and 2/3 should be 17/8. You had %d/%d.\n", refnum, refden);
    }
    Fraction_free(fs);
    
    fs = Fraction_divide(fm, fb);
    refnum = Fraction_getNumerator(fs);
    refden = Fraction_getDenominator(fs);
    if (refnum != 17 || refden != 9) {
        fail("Quotient of 17/12 and 3/4 should be 17/9. You had %d/%d.\n", refnum, refden);
    }
    Fraction_free(fs);
    
    fs = Fraction_divide(fn, fm);
    refnum = Fraction_getNumerator(fs);
    refden = Fraction_getDenominator(fs);
    if (refnum != 25 || refden != 17) {
        fail("Quotient of 75/36 and 17/12 should be 25/17. You had %d/%d.\n", refnum, refden);
    }
    
    Fraction_free(fa);
    Fraction_free(fb);
    Fraction_free(fm);
    Fraction_free(fn);
    Fraction_free(fs);
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("Test-demo");
	tmc_register_test(s, test_new, "1");
        tmc_register_test(s, test_compare, "1");
        tmc_register_test(s, test_reduce, "1");
        tmc_register_test(s, test_add, "1");
        tmc_register_test(s, test_subtract, "1");
        tmc_register_test(s, test_multiply, "1");
        tmc_register_test(s, test_divide, "1");
	return tmc_run_tests(argc, argv, s);
}
