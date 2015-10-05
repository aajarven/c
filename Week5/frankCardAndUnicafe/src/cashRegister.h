#ifndef CASHREGISTER_H
#define	CASHREGISTER_H
#include "frankCard.h"

#define ECONOMICAL_MEAL 2.60
#define GOURMET_MEAL 4.40


typedef struct CashRegister CashRegister;

CashRegister* CR_new(char* name);
char* CR_getName(CashRegister* cashRegister);
double CR_getCashIn(CashRegister* cashRegister);
int CR_getEconomicalSold(CashRegister* cashRegister);
int CR_getGourmetSold(CashRegister* cashRegister);
double CR_payEconomical(CashRegister* cashRegister, double cashGiven);
double CR_payGourmet(CashRegister* cashRegister, double cashGiven);
int CR_payEconomicalFromCard(CashRegister* cashRegister, FrankCard* card);
int CR_payGourmetFromCard(CashRegister* cashRegister, FrankCard* card);
double CR_loadMoneyToCard(CashRegister* cashRegister, FrankCard* card, double amount);
void CR_free(CashRegister **cashRegister);


#endif	/* CASHREGISTER_H */

