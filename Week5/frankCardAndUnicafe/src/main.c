#include <stdio.h>
#include "frankCard.h"
#include "cashRegister.h"

/* Good to know: structures, own headers, allocating and releasing memory, pointers 
 * This exercise is from Object-oriented programming with Java, week 5.
 * Copy your solution for frankCard.c and frankCard.h from previous exercise. 
 * Header cashRegister.h specifies the public interface of cashRegister. 
 * Define a structure called cashRegister in cashRegister.c.
 * CashRegister contains four members, pointer to string name, double for cashInRegister and integers for economicalSold and gourmetSold.
 * CR_new allocates memory for a new cashRegister and set its name to point to a given name, remember to allocate space for the string also. 
 *    EconomicalSold and gourmetSold are set to 0 and cashInRegister to 1000.
 * CR_getName should return the name of the cashRegister and CR_getCashIn should return the balance of the cashRegister.
 * CR_getEconomicalSold should return the number of economical lunches sold and CR_getGourmetSold should return the number of gourmet lunches sold.
 * Function CR_payEconomical should check if the given cash is at least 2.60 (use the macro name instead of the actual numerical value) and 
 *    then add the price of the lunch to the register, increase the amount of sold economical lunches and return the amount of cash to be given
 *    back to the customer (given amount - price).
 *    If the givenCash is less than 2.60, function should return the whole amount.
 * CR_payGourmet should work like CashRegister_payEconomical, but now the price of the lunch is 4.40.
 * Functions CR_payEconomicalFromCard and CR_payGourmetFromCard should check if the balance of the card is at least the price of the lunch 
      and then pay the lunch from the card, increase the amount of sold lunches and return 1 if the lunch was sold and 0 if not.
 * Function CR_loadMoneyToCard should load a positive amount of money to the given frankCard and increase the cashInRegister correspondingly.
      Because there is a limit to the amount the card can hold, function return the information how much money must be given back to the customer.
 * Function CR_free should free all allocated memory.
 */

int main(void) {
    CashRegister* unicafeExactum = CR_new("Unicafe Exactum");
    FrankCard* cardKalle = FC_new("Kalle's card");
    CR_loadMoneyToCard(unicafeExactum, cardKalle, 2.0);
    printf("%s: after loading 2.0 to card the new balance is %.2f\n", FC_getName(cardKalle), FC_getBalance(cardKalle)); /*Kalle's card: balance is 2.00*/
    printf("%s: after loading 2.0 to card the new balance is %.2f\n", CR_getName(unicafeExactum), CR_getCashIn(unicafeExactum)); /*Unicafe Exactum: balance is 1002.00*/
    printf("payment success: ");
    if (CR_payGourmetFromCard(unicafeExactum, cardKalle)){
        printf("true\n");
    } else {
        printf("false\n"); /*payment success: false*/
    }
    printf("%s: after buying gourmet meal the new balance is %.2f\n", FC_getName(cardKalle), FC_getBalance(cardKalle)); /*Kalle's card: balance is 2.00*/
    double ret = CR_loadMoneyToCard(unicafeExactum, cardKalle, 200.0);
    printf ("trying to load 200 to the card, must return in cash %.2f to customer\n", ret);
    printf("%s: after trying to load 200 to the card, new balance is %.2f\n", FC_getName(cardKalle), FC_getBalance(cardKalle)); /*Kalle's card: balance is 150.00*/
    printf("%s: after trying to load 200 to card the new balance is %.2f\n", CR_getName(unicafeExactum), CR_getCashIn(unicafeExactum)); /*Unicafe Exactum: balance is 1150*/
    CR_payEconomicalFromCard(unicafeExactum, cardKalle);
    printf("%s: after buying economical meal the new balance is %.2f\n", FC_getName(cardKalle), FC_getBalance(cardKalle)); /*Kalle's card: balance is 147.40*/
    printf("%s: after selling economical meal with card the cash balance is balance is %.2f\n", CR_getName(unicafeExactum), CR_getCashIn(unicafeExactum)); /*Unicafe Exactum balance is 1150*/
    printf("%s: Sold %d economical meals and  %d gourment meals \n", CR_getName(unicafeExactum), CR_getEconomicalSold (unicafeExactum), 
                                                                     CR_getGourmetSold(unicafeExactum) );
   FC_free(&cardKalle);
    CR_free(&unicafeExactum);
    if (unicafeExactum != NULL) printf("Free not working properly\n");

    return 0;
}
