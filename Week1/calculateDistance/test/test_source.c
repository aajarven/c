#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/source.h"

START_TEST(test_powerTwo){
    double res = powerTwo(2.5);
    double ref = pow(2.5, 2);
    fail_unless(res == ref, "powerTwo(2.5) returned %f. Should have returned: %f", res, ref);
    
    res = powerTwo(6);
    ref = pow(6, 2);
    fail_unless(res == ref, "powerTwo(6) returned %f. Should have returned: %f", res, ref);
}
END_TEST

START_TEST(test_distance){
    double res = distance(2.5, 5, 4.3, 2);
    double ref = sqrt(pow((4.3 - 2.5), 2) + pow((2 - 5), 2));
    fail_unless(res == ref, "distance(2.5, 5, 4.3, 2) returned %f. Should have returned: %f", res, ref);
    
    res = distance(7.3, 4.2, 1.5, 9);
    ref = sqrt(pow((1.5 - 7.3), 2) + pow((9 - 4.2), 2));
    fail_unless(res == ref, "distance(7.3, 4.2, 1.5, 9) returned %f. Should have returned: %f", res, ref);
}
END_TEST


START_TEST(test_distanceFromOrigo){
    double res = distanceFromOrigo(2.5, 5);
    double ref = sqrt((2.5 * 2.5) + (5 * 5));
    fail_unless(res == ref, "distanceFromOrigo(2.5, 5) returned %f. Should have returned: %f", res, ref);
    
    res = distanceFromOrigo(0.1, 0.1);
    ref = sqrt((0.1 * 0.1) + (0.1 * 0.1));
    fail_unless(res == ref, "distanceFromOrigo(0.1, 0.1) returned %f. Should have returned: %f", res, ref);
}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("calculateDistance");
        tmc_register_test(s, test_powerTwo, "calculateDistance");
        tmc_register_test(s, test_distance, "calculateDistance");
	tmc_register_test(s, test_distanceFromOrigo, "calculateDistance");
	return tmc_run_tests(argc, argv, s);
}
