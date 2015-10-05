#include <stdio.h>
#include "frankCard.h"

/* Good to know: structures, own headers, allocating and releasing memory, pointers 
 * This exercise is from Object-oriented programming with Java, week 4. 
 * Header frankCard.h specifies the public interface of frankCard. 
 * Define a structure called frankCard in frankCard.h. frankCard contains two members, pointer to string name and double balance. 
 * Implement all functions in frankCard.c. 
 * FrankCard_new allocate memory for a new frankCard and set its name to point to a given name. Balance is set to 0.0.
 * FrankCard_new should return a pointer to the allocated FrankCard.
 * FrankCard_getName returns the name of the card and FrankCard_getBalance returns the balance of the card.
 * Function FrankCard_payEconomical should decrease the balance by 2.60 euros and function FrankCard_payGourmet should decrease the balance by 4.40 euros.
 * If there isn't enought money, the balance of the card doesn't change.
 * Function FrankCard_loadMoney should increase the balance of the card by the given amount. It isn't possible to load a negative amount. 
 * If the balance of the card is more than 150 euros, the balance is set to 150 euros.
 * Function FrankCard_free should free all allocated memory and return 1 if successful. */

#define ECONOMICAL_MEAL 2.60
#define GOURMET_MEAL 4.40

int main(void) {
    double ret;
    FrankCard* cardKalle = FC_new("Kalle's card");
    FrankCard* cardVille = FC_new("Ville's card");
    FC_load(cardKalle, 20.0);
    FC_load(cardVille, 15.0);
    printf("%s: balance is %.2f\n", FC_getName(cardKalle), FC_getBalance(cardKalle)); /*Kalle's card: balance is 20.00*/
    printf("%s: balance is %.2f\n", FC_getName(cardVille), FC_getBalance(cardVille)); /*Ville's card: balance is 15.00*/
    ret = FC_pay(cardKalle, ECONOMICAL_MEAL);
    ret = FC_pay(cardVille, GOURMET_MEAL);
    printf("%s: balance is %.2f\n", FC_getName(cardKalle), FC_getBalance(cardKalle)); /*Kalle's card: balance is 17.40*/
    printf("%s: balance is %.2f\n", FC_getName(cardVille), FC_getBalance(cardVille)); /*Ville's card: balance is 10.60*/
    ret=FC_load(cardKalle, 200.0);
    ret=FC_pay(cardVille, GOURMET_MEAL);
    ret=FC_pay(cardVille,ECONOMICAL_MEAL);
    printf("%s: balance is %.2f\n", FC_getName(cardKalle), FC_getBalance(cardKalle)); /*Kalle's card: balance is 150.00*/
    printf("%s: balance is %.2f\n", FC_getName(cardVille), FC_getBalance(cardVille)); /*Ville's card: balance is 3.60*/
    ret=FC_pay(cardKalle, GOURMET_MEAL);
    ret=FC_pay(cardVille, GOURMET_MEAL);
    printf("%s: balance is %.2f\n", FC_getName(cardKalle), FC_getBalance(cardKalle)); /*Kalle's card: balance is 145.60*/
    printf("%s: balance is %.2f\n", FC_getName(cardVille), FC_getBalance(cardVille)); /*Ville's card: balance is 3.60*/
    FC_free(&cardKalle);
    if (cardKalle !=NULL) printf("Free not working correctly\n");
    FC_free(&cardVille);
    return 0;
}
