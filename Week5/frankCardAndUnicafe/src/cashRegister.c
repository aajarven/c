#include <stdlib.h>
#include "cashRegister.h"

#define EDULLISESTI 2.6
#define MAUKKAASTI 4.4

struct CashRegister{
    char* name;
    double balance;
    int edulliset;
    int maukkaat;
};

CashRegister* CR_new(char* name){
    struct CashRegister *uusi = malloc(sizeof(struct CashRegister));
    uusi->name = name;
    uusi->balance = 1000;
    uusi->edulliset = 0;
    uusi->maukkaat = 0;
    return uusi;
}

char* CR_getName(CashRegister* cashRegister){
    return cashRegister->name;
}

double CR_getCashIn(CashRegister* cashRegister){
    return cashRegister->balance;
}

int CR_getEconomicalSold(CashRegister* cashRegister){
    return cashRegister->edulliset;
}

int CR_getGourmetSold(CashRegister* cashRegister){
    return cashRegister->maukkaat;
}

double CR_payEconomical(CashRegister* cashRegister, double cashGiven){
    if(cashGiven<EDULLISESTI){
        return cashGiven;
    } else {
        cashRegister->balance += EDULLISESTI;
        cashRegister->edulliset++;
        return cashGiven-EDULLISESTI;
    }
}

double CR_payGourmet(CashRegister* cashRegister, double cashGiven){
    if(cashGiven<MAUKKAASTI){
        return cashGiven;
    } else {
        cashRegister->balance += MAUKKAASTI;
        cashRegister->maukkaat++;
        return cashGiven-MAUKKAASTI;
    }
}

int CR_payEconomicalFromCard(CashRegister* cashRegister, FrankCard* card){
    if(FC_pay(card, EDULLISESTI) >= 0){
        cashRegister->edulliset++;
        cashRegister->balance += EDULLISESTI;
        return 1;
    }
    return 0;
}

int CR_payGourmetFromCard(CashRegister* cashRegister, FrankCard* card){
    if(FC_pay(card, MAUKKAASTI) >= 0){
        cashRegister->maukkaat++;
        cashRegister->balance += MAUKKAASTI;
        return 1;
    }
    return 0;
}

double CR_loadMoneyToCard(CashRegister* cashRegister, FrankCard* card, double amount){
    double ylijaama = FC_getBalance(card) + amount - 150;
    if (ylijaama < 0){
        ylijaama = 0;
        cashRegister->balance += amount;
    } else {
        cashRegister->balance += amount - ylijaama;
    }

    FC_load(card, amount);
    return ylijaama;

}

void CR_free(CashRegister **cashRegister){
    free(*cashRegister);
    *cashRegister=NULL;
}
