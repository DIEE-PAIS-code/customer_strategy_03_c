

#ifndef CUSTOMERMODULE_H
#define CUSTOMERMODULE_H

#define DIM 50


typedef struct Customer {
    char name[DIM];
    char* typeOfCustomer; // gold, silver, bronze, etc
    /* Bind the strategy to Customer using pointers to functions */
    float (*p_priceStrategy)(float amount, float shipping) ;
    void (*p_greetingsStrategy)();
    // to implement:
    //      List orders; address; telephone number; etc
    //      ...
}T_customer;

T_customer * newCustomer(T_customer *p_c);

float computePrice(T_customer *p_c, float amount,float shipping);
float bronzePriceStrategy(float amount, float shipping);
float silverPriceStrategy(float amount, float shipping);
float goldPriceStrategy(float amount, float shipping);

void greetings(T_customer  *p_c);
void goldGreetingsStrategy();
void silverGreetingsStrategy();
void bronzeGreetingsStrategy();

#endif //CUSTOMERMODULE_H
