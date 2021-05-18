
#include <stdio.h>
#include <stdlib.h>

void outPut(float mortgage, float rate, float payment) {
    int month = 0;
    float rateMonth = rate / 12;
    float amountOwed = mortgage;
    amountOwed = amountOwed * (100 + rateMonth) / 100;
    if( amountOwed <= payment) {
            printf("The monthly payment is too small to ever pay off the loan");
    }
    else{
        amountOwed = mortgage;
        do{
            amountOwed = amountOwed * (100 + rateMonth) / 100;
            if(amountOwed > payment){
                amountOwed = amountOwed - payment;
                ++month;
                printf("%d\t%0.2f\t%0.2f\n", month, payment, amountOwed);
            }else{
                payment = amountOwed;
                amountOwed = 0;
                ++month;
                printf("%d\t%0.2f\t%0.0f\n", month, payment, amountOwed);
            }   	
	}while(amountOwed != 0);
    }
}


int inputCheck(char a[]) {
    int number;
    int min = 0;
    char character;
    
    printf("%s\n", a);
    do{
        scanf("%d%c", &number, &character);
        fpurge(stdin);
        
        if(character != '\n') {
            printf("INVALID VALUE !!!\n");
            printf("Retype the number: ");
        }else {
            if(number < min) {
                printf("INVALID VALUE !!! (number > 0)\n");
                printf("Retype the number: ");
            }else {
                return number;
            }
        }   
    }while(1);
}

int main(int argc, char** argv) {
    int mortgage, rate, payment;
    
    //Input && check value
    mortgage = inputCheck("What is the value left on the mortgage?");
    rate = inputCheck("What is the annual interest rate of the loan, in percent?");
    payment = inputCheck("What is the monthly payment?");
    
    //Display calculation explanation
    outPut(mortgage, rate, payment);
    
    return (EXIT_SUCCESS);
}

