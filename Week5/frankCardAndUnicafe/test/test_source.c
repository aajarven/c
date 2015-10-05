#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/frankCard.h"
#include "../src/cashRegister.h"



START_TEST(test_cash_init)
{
    CashRegister* unicafe;

    unicafe = CR_new("Unicafe");
    ck_assert_msg(unicafe != NULL, "new_CashRegister returned NULL");
    ck_assert_msg(strcmp(CR_getName(unicafe), "Unicafe") == 0, "CashRegister's name should be Unicafe, but it was %s", CR_getName(unicafe));
    ck_assert_msg(fabs(CR_getCashIn(unicafe) - 1000.0) < 0.00001, "Get cash in register doesn't work. Balance should be initially 1000.0, but it was %.2f", CR_getCashIn(unicafe));
    ck_assert_msg(CR_getEconomicalSold(unicafe)==0, "Get cash in register doesn't work. Sold economical meals should be initially 0, but it was %.2f", CR_getEconomicalSold(unicafe));
    ck_assert_msg(CR_getGourmetSold(unicafe)==0, "Get cash in register doesn't work. Sold gourmet meals should be initially 0, but it was %.2f", CR_getGourmetSold(unicafe));
}
END_TEST

START_TEST(test_cash_cash)
{
    CashRegister* unicafe;


    unicafe = CR_new("Unicafe");
    double cashBalance = CR_getCashIn(unicafe);


    double cashBack = CR_payEconomical(unicafe, 5.00);
    cashBalance += ECONOMICAL_MEAL;
    ck_assert_msg(fabs(cashBack - (5.0 - ECONOMICAL_MEAL)) < 0.00001, "Pay Economical doesn't work. When given cash is 5.00, you should get 2.40 back, but it was %.2f", cashBack);
    ck_assert_msg( (CR_getEconomicalSold(unicafe) == 1), "The reported amount of sold economical meals is incorrect. it is %d and it should be 1.\n", CR_getEconomicalSold(unicafe));
    ck_assert_msg(fabs(CR_getCashIn(unicafe) - cashBalance) < 0.00001, "In payEconomical you did not increment the value of the economical meal to the  cash in register in the cash. Value of CashIn is %.2f and it should be %.2f\n", CR_getCashIn(unicafe), cashBalance );

    cashBack = CR_payGourmet(unicafe, 5.00);
    cashBalance += GOURMET_MEAL;
    ck_assert_msg(fabs(cashBack - (5.0 - GOURMET_MEAL)) < 0.00001, "Pay Gourmet doesn't work. When given cash is 5.00, you should get 0.60 back, but it was %.2f", cashBack);
    ck_assert_msg(fabs(CR_getCashIn(unicafe) - cashBalance) < 0.00001, "You did not increment the value of the gourmet meal to the  cash in register in the cash. Value of CashIn is %.2f and it should be %.2f\n", CR_getCashIn(unicafe), cashBalance );
    ck_assert_msg( (CR_getGourmetSold(unicafe) == 1), "The reported the amount of sold gourmet meals is incorrect. it is %d and it should be 1.\n", CR_getEconomicalSold(unicafe));

    cashBack = CR_payEconomical(unicafe, (ECONOMICAL_MEAL -0.1));
    ck_assert_msg(fabs(cashBack - (ECONOMICAL_MEAL -0.1)) < 0.00001, "Pay Economical doesn't work. When given cash is %.2f, you should get %.2f back, but it was %.2f", ECONOMICAL_MEAL-0.1, ECONOMICAL_MEAL-0.1, cashBack);
    ck_assert_msg(fabs(CR_getCashIn(unicafe) - cashBalance) < 0.00001, "In payEconomical you incremented the value of the economical meal even when not selling it. The cash balance is %.2f and it should be %.2f\n", CR_getCashIn(unicafe), cashBalance );

    cashBack = CR_payGourmet(unicafe, (GOURMET_MEAL -0.1));
    ck_assert_msg(fabs(cashBack - (GOURMET_MEAL -0.1)) < 0.00001, "Pay Gourmet doesn't work. When given cash is %.2f, you should get %.2f back, but it was %.2f", GOURMET_MEAL-0.1, GOURMET_MEAL-0.1, cashBack);
    ck_assert_msg(fabs(CR_getCashIn(unicafe) - cashBalance) < 0.00001, "In payGourmet you incremented the value of the economical meal even when not selling it. The cash balance is %.2f and it should be %.2f\n", CR_getCashIn(unicafe), cashBalance );


    cashBack = CR_payGourmet(unicafe, GOURMET_MEAL);
    ck_assert_msg(fabs(cashBack) < 0.00001, "Pay Gourmet doesn't work. When given cash is %.2f, you should get %.2f back, but it was %.2f", GOURMET_MEAL, GOURMET_MEAL, cashBack);

    cashBack = CR_payEconomical(unicafe, (ECONOMICAL_MEAL));
    ck_assert_msg(fabs(cashBack) < 0.00001, "Pay Economical doesn't work. When given cash is %.2f, you should get %.2f back, but it was %.2f", ECONOMICAL_MEAL, ECONOMICAL_MEAL, cashBack);

    CR_free(&unicafe);
   ck_assert_msg(unicafe==NULL,"The free did not set the pointer value to NULL\n");


}
END_TEST


START_TEST(test_cash_card)
{
    CashRegister* unicafe;
    FrankCard* cardPekka;
    
    unicafe = CR_new("Unicafe");
    ck_assert_msg(unicafe != NULL, "new_CashRegister returned NULL");
    cardPekka = FC_new("cardPekka");
    ck_assert_msg(cardPekka != NULL, "new_FrankCard returned NULL");
    ck_assert_msg(strcmp(CR_getName(unicafe), "Unicafe") == 0, "CashRegister's name should be Unicafe, but it was %s", CR_getName(unicafe));
    ck_assert_msg(strcmp(FC_getName(cardPekka), "cardPekka") == 0, "Card's name should be cardPekka, but it was %s", FC_getName(cardPekka));

    double cardBalance = FC_getBalance(cardPekka);
    double cashBalance = CR_getCashIn(unicafe);

    int ret=1;
    int mealcount = CR_getEconomicalSold(unicafe);

    while (ret)
    if (cardBalance < ECONOMICAL_MEAL) {
       ret = 0;
       ck_assert_msg(CR_payEconomicalFromCard(unicafe, cardPekka) == 0, "payEconomicalFromCard doesn't work. If there isn't enough money, you should return 0.");
       ck_assert_msg( (CR_getEconomicalSold(unicafe) == mealcount), "payEconomicalFromCard: The reported amount of sold economical meals is incorrect. it is %d and it should be %d.\n", CR_getEconomicalSold(unicafe), mealcount);
       }
    else {
       ret= CR_payEconomicalFromCard(unicafe, cardPekka);
       ck_assert_msg(ret == 1, "payEconomicalFromCard doesn't work. If there is enough money, you should return 1.");
       mealcount++;
       ck_assert_msg( (CR_getEconomicalSold(unicafe) == mealcount), "payEconomicalFromCard: The reported amount of sold economical meals is incorrect. it is %d and it should be %d.\n", CR_getEconomicalSold(unicafe), mealcount);
       ck_assert_msg(fabs(CR_getCashIn(unicafe) - cashBalance) < 0.00001, "payEconomicalFromCard: With card payments, you should not change the cash balance, which is %.2f and it should be %.2f\n", CR_getCashIn(unicafe), cashBalance );
       }


    cardBalance = FC_getBalance(cardPekka);
    cashBalance = CR_getCashIn(unicafe);
    ret =1;

    while (ret)
    if (cardBalance < GOURMET_MEAL) {
       ret=0;
       ck_assert_msg(CR_payGourmetFromCard(unicafe, cardPekka) == 0, "payGourmetFromCard doesn't work. If there isn't enough money, you should return 0.");
       ck_assert_msg( (CR_getGourmetSold(unicafe) == mealcount), "payGourmetFromCard: The reported amount of sold gourmet meals is incorrect. it is %d and it should be %d.\n", CR_getGourmetSold(unicafe), mealcount);
       }
    else {
       ret=CR_payGourmetFromCard(unicafe, cardPekka);
       ck_assert_msg(ret == 1, "payGourmetFromCard doesn't work. If there is enough money, you should return 1.");
       mealcount++;
       ck_assert_msg( (CR_getGourmetSold(unicafe) == mealcount), "payGourmetFromCard: The reported amount of sold gourmet meals is incorrect. it is %d and it should be %d.\n", CR_getGourmetSold(unicafe), mealcount);
       ck_assert_msg(fabs(CR_getCashIn(unicafe) - cashBalance) < 0.00001, "payEconomicalFromCard: With card payments, you should not change the cash balance, which is %.2f and it should be %.2f\n", CR_getCashIn(unicafe), cashBalance );
       }

    double amount = GOURMET_MEAL + ECONOMICAL_MEAL + (ECONOMICAL_MEAL-1)<0?0:(ECONOMICAL_MEAL-1) ;

    cardBalance = FC_getBalance(cardPekka)+ amount ;
    cashBalance = CR_getCashIn(unicafe) + amount;

    double cashBack;

    cashBack=CR_loadMoneyToCard(unicafe, cardPekka, amount);


    ck_assert_msg(fabs(CR_getCashIn(unicafe) - cashBalance) < 0.00001, "GetCashIn doesn't work. Cash Balance should be %.2f, but it was %.2f", cashBalance, CR_getCashIn(unicafe));
    ck_assert_msg(fabs(FC_getBalance(cardPekka) - cardBalance) < 0.00001, "GetCashIn doesn't work. Card Balance should be %.2f, but it was %.2f", cardBalance, FC_getBalance(cardPekka));


    if (cardBalance < ECONOMICAL_MEAL) {
       ret = 0;
       ck_assert_msg(CR_payEconomicalFromCard(unicafe, cardPekka) == 0, "payEconomicalFromCard doesn't work. If there isn't enough money, you should return 0.");
       ck_assert_msg( (CR_getEconomicalSold(unicafe) == mealcount), "payEconomicalFromCard: The reported amount of sold economical meals is incorrect. it is %d and it should be %d.\n", CR_getEconomicalSold(unicafe), mealcount);
       }
    else {
       ret= CR_payEconomicalFromCard(unicafe, cardPekka);
       ck_assert_msg(ret == 1, "payEconomicalFromCard doesn't work. If there is enough money, you should return 1.");
       mealcount++;
       ck_assert_msg( (CR_getEconomicalSold(unicafe) == mealcount), "payEconomicalFromCard: The reported amount of sold economical meals is incorrect. it is %d and it should be %d.\n", CR_getEconomicalSold(unicafe), mealcount);
       ck_assert_msg(fabs(CR_getCashIn(unicafe) - cashBalance) < 0.00001, "payEconomicalFromCard: With card payments, you should not change the cash balance, which is %.2f and it should be %.2f\n", CR_getCashIn(unicafe), cashBalance );
       }



    if (cardBalance < GOURMET_MEAL) {
       ret=0;
       ck_assert_msg(CR_payGourmetFromCard(unicafe, cardPekka) == 0, "payGourmetFromCard doesn't work. If there isn't enough money, you should return 0.");
       ck_assert_msg( (CR_getGourmetSold(unicafe) == mealcount), "payGourmetFromCard: The reported amount of sold gourmet meals is incorrect. it is %d and it should be %d.\n", CR_getGourmetSold(unicafe), mealcount);
       }
    else {
       ret=CR_payGourmetFromCard(unicafe, cardPekka);
       ck_assert_msg(ret == 1, "payGourmetFromCard doesn't work. If there is enough money, you should return 1.");
       mealcount++;
       ck_assert_msg( (CR_getGourmetSold(unicafe) == mealcount), "payGourmetFromCard: The reported amount of sold gourmet meals is incorrect. it is %d and it should be %d.\n", CR_getGourmetSold(unicafe), mealcount);
       ck_assert_msg(fabs(CR_getCashIn(unicafe) - cashBalance) < 0.00001, "payEconomicalFromCard: With card payments, you should not change the cash balance, which is %.2f and it should be %.2f\n", CR_getCashIn(unicafe), cashBalance );
       }




    if (cardBalance < ECONOMICAL_MEAL) {
       ret = 0;
       ck_assert_msg(CR_payEconomicalFromCard(unicafe, cardPekka) == 0, "payEconomicalFromCard doesn't work. If there isn't enough money, you should return 0.");
       ck_assert_msg( (CR_getEconomicalSold(unicafe) == mealcount), "payEconomicalFromCard: The reported amount of sold economical meals is incorrect. it is %d and it should be %d.\n", CR_getEconomicalSold(unicafe), mealcount);
       }
    else {
       ret= CR_payEconomicalFromCard(unicafe, cardPekka);
       ck_assert_msg(ret == 1, "payEconomicalFromCard doesn't work. If there is enough money, you should return 1.");
       mealcount++;
       ck_assert_msg( (CR_getEconomicalSold(unicafe) == mealcount), "payEconomicalFromCard: The reported amount of sold economical meals is incorrect. it is %d and it should be %d.\n", CR_getEconomicalSold(unicafe), mealcount);
       ck_assert_msg(fabs(CR_getCashIn(unicafe) - cashBalance) < 0.00001, "payEconomicalFromCard: With card payments, you should not change the cash balance, which is %.2f and it should be %.2f\n", CR_getCashIn(unicafe), cashBalance );
       }




    cardBalance = FC_getBalance(cardPekka);
    cashBalance = CR_getCashIn(unicafe);


    cashBack= CR_loadMoneyToCard(unicafe, cardPekka, 300);

    ck_assert_msg(fabs(cashBack+FC_getBalance(cardPekka)-(300+cardBalance)) < 0.0001, "LoadMoney with amount over 150 causes incorrect value to be returned.\n");


    ck_assert_msg(fabs(CR_getCashIn(unicafe) - (cashBalance+300-cashBack)) < 0.00001, "LoadMoney with amount over 150 caused the cash balance to be incorrect. Cash Balance should be %.2f, but it was %.2f", cashBalance+300-cashBack, CR_getCashIn(unicafe));
    ck_assert_msg(fabs(FC_getBalance(cardPekka) - 150) < 0.00001, "LoadMoney doesn't work. Card Balance should be 150.00, but it was %.2f", FC_getBalance(cardPekka));


    CR_free(&unicafe);
    ck_assert_msg(unicafe==NULL,"The free did not set the pointer value to NULL\n");
    FC_free(&cardPekka);
    ck_assert_msg(cardPekka==NULL,"The free did not set the pointer value to NULL\n");

}
END_TEST


int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("CardAndUnicafe");
	tmc_register_test(s, test_cash_init, "CashInit");
	tmc_register_test(s, test_cash_cash, "CashCash");
        tmc_register_test(s, test_cash_card, "CashCard");
	return tmc_run_tests(argc, argv, s);
}
