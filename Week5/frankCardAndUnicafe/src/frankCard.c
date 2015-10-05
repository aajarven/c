#include <stdlib.h>
#include "frankCard.h"

struct FrankCard{
    char *name;
    double balance;
};

FrankCard* FC_new(char* name){
    struct FrankCard *uusi = malloc(sizeof(struct FrankCard));
    uusi->name=name;
    uusi->balance=0;  
    return uusi;
}

char* FC_getName(FrankCard* card){
    return card->name;
}

double FC_getBalance(FrankCard* card){
    return card->balance;
}

double FC_load(FrankCard* card, double amount){
    if(amount<0) return -1;
    
    card->balance += amount;
    if(card->balance > 150) card->balance=150;
    return card->balance;
}

double FC_pay(FrankCard* card, double amount){
    if (card->balance >= amount){
        card->balance -= amount;
        return card->balance;
    } else {
        return -1;
    }
}

void FC_free(FrankCard** card){
    free(*card);
    *card = NULL;
    return;
}
