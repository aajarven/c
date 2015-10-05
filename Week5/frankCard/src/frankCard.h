#ifndef FRANKCARD_H
#define	FRANKCARD_H

typedef struct FrankCard FrankCard;


FrankCard* FC_new (char* name);
char* FC_getName (FrankCard* card);
double FC_getBalance (FrankCard* card);
double FC_load (FrankCard* card, double amount);
double FC_pay (FrankCard* card, double amount);
void FC_free (FrankCard** card);

#endif	/* FRANKCARD_H */

