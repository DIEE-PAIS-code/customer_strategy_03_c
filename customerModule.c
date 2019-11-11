
#include "customerModule.h"
#include <stdio.h>
#include <string.h> // strcmp()
#include <stdlib.h> // exit()


//******************************************************
//   CUSTOMER
//******************************************************

T_customer * newCustomer(T_customer *p_c){

    printf("Insert customer's name: ");
    fgets(p_c->name, DIM, stdin);

    printf("Choose customer type:\n");
    printf("a: GOLD\n");
    printf("b: SILVER\n");
    printf("c: BRONZE\n");

    switch (getchar()) {
        case 'a':
            p_c->typeOfCustomer = "gold";
            p_c->p_priceStrategy=goldPriceStrategy;
            p_c->p_greetingsStrategy=goldGreetingsStrategy;
            break;
        case 'b':
            p_c->typeOfCustomer = "silver";
            p_c->p_priceStrategy=silverPriceStrategy;
            p_c->p_greetingsStrategy=silverGreetingsStrategy;
            break;
        case 'c':
            p_c->typeOfCustomer = "bronze";
            p_c->p_priceStrategy=bronzePriceStrategy;
            p_c->p_greetingsStrategy=bronzeGreetingsStrategy;
            break;
        default:
            perror("Unknown customer type");
            exit(1);
    }
    return p_c;
}



//******************************************************
//   PRICE STRATEGY
//******************************************************

float computePrice(T_customer *p_c, float amount,float shipping) {
    /* compute the total price
     * depending on customer category. */
    float price;

    price=(p_c->p_priceStrategy)(amount, shipping);
     /* it will be
     * bronzePriceStrategy, silverPriceStrategy, goldPriceStrategy
     * or others
     * depending on the Customer*/
    return price;
}


float bronzePriceStrategy(float amount, float shipping){
    return amount+shipping;
}
float silverPriceStrategy(float amount, float shipping){
    return 0.9*amount+shipping;
}
float goldPriceStrategy(float amount, float shipping){
    return 0.8*amount; // free shipping;
}

//******************************************************
//   GREETINGS STRATEGY
//******************************************************
void greetings(T_customer  * p_c) {
    // Happy Birthday (and gift card for some categories)
    (p_c->p_greetingsStrategy)();
}

void goldGreetingsStrategy(){
    printf("Happy Birthday + gift card 20 euros!");
};
void silverGreetingsStrategy(){
    printf("Happy Birthday + gift card 10 euros!");
};
void bronzeGreetingsStrategy(){
    printf("Happy Birthday!");
};
