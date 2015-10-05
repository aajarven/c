#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/frankCard.h"

START_TEST(test_frank_card) {
    FrankCard* cardPekka;

    cardPekka = FC_new("cardPekka");
    ck_assert_msg(cardPekka != NULL, "new_FrankCard returned NULL");
    ck_assert_msg(strcmp(FC_getName(cardPekka), "cardPekka") == 0, "Card's name should be cardPekka, but it was %s", FC_getName(cardPekka));
    ck_assert_msg(fabs(FC_getBalance(cardPekka) - 0.0) < 0.00001, "Balance should be 0.0 when creating a new card, but it was %.2f", FC_getBalance(cardPekka));
    FC_load(cardPekka, 7.0);
    ck_assert_msg(fabs(FC_getBalance(cardPekka) - 7.0) < 0.00001, "Load money doesn't work. Balance should be 7.0 after adding 7.0, but it was %.2f", FC_getBalance(cardPekka));
    FC_load(cardPekka, -10.0);
    ck_assert_msg(fabs(FC_getBalance(cardPekka) - 7.0) < 0.00001, "Load money doesn't work. Balance should not change when adding a negative amount and it should be 7.0, but it was %.2f", FC_getBalance(cardPekka));
    FC_load(cardPekka, 1.0);
    ck_assert_msg(fabs(FC_getBalance(cardPekka) - 8.0) < 0.00001, "Load money doesn't work. Balance should be 8.0 after addind several times, but it was %.2f", FC_getBalance(cardPekka));
    FC_pay(cardPekka, 4.40);
    ck_assert_msg(fabs(FC_getBalance(cardPekka) - 3.6) < 0.00001, "Pay gourmet doesn't work. Balance should be 3.60 after payment, but it was %.2f", FC_getBalance(cardPekka));
    FC_pay(cardPekka,2.60);
    ck_assert_msg(fabs(FC_getBalance(cardPekka) - 1.0) < 0.00001, "Pay economical doesn't work. Balance should be 1.00 after payment, but it was %.2f", FC_getBalance(cardPekka));
    FC_pay(cardPekka,4.40);
    ck_assert_msg(fabs(FC_getBalance(cardPekka) - 1.0) < 0.00001, "Pay gourmet doesn't work. Balance should not change when there isn't enough money and should be 1.00, but it was %.2f", FC_getBalance(cardPekka));
    FC_load(cardPekka, 2.0);
    ck_assert_msg(fabs(FC_getBalance(cardPekka) - 3.0) < 0.00001, "Load money doesn't work. Balance should be 3.00 after loading money again, but it was %.2f", FC_getBalance(cardPekka));
    FC_pay(cardPekka,2.60);
    ck_assert_msg(fabs(FC_getBalance(cardPekka) - 0.4) < 0.00001, "Pay economical doesn't work. Balance should be 0.4 after payment, but it was %.2f", FC_getBalance(cardPekka));
    FC_pay(cardPekka,2.60);
    ck_assert_msg(fabs(FC_getBalance(cardPekka) - 0.4) < 0.00001, "Pay economical doesn't work. Balance should not change when there isn't enough money and it should be 0.4, but it was %.2f", FC_getBalance(cardPekka));
    FC_free(&cardPekka);
    ck_assert_msg(cardPekka == NULL, "FC_free did not set the card pointer to NULL");

}
END_TEST

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("FrankTest");
	tmc_register_test(s, test_frank_card, "FrankCard");
	return tmc_run_tests(argc, argv, s);
}
