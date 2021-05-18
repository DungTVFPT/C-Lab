
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void outPut(int number) {
    printf("Multiplication table for %d number:\n", number);
    int a;
    for(int i = 1; i <= 10; i++) {
        a = number * i;
        printf("%dx%d=%d\n", number, i, a);
    }
    printf("-------------------------------------------\n");
    printf("Press enter to continue, Esc to exit.");
    
}

int inputNumber() {
    int number;
    int min = 1, max = 9;
    char character;
    printf("Please enter a number (1 – 9):");
    
    do {
        fpurge(stdin);
        scanf("%d%c", &number, &character);
        //check character
        if( character != '\n') {
            printf("\nINVALID VALUE!!!");
            printf("\nRetype a number: ");
        }else {
            // character == '\n' && check number
            if( (number < min) || (number > max) ) {
                printf("\nInvalid value! (1 - 9)");
                printf("\nRetype the value: ");
            }
            else
                //character == '\n' && 0 < number <= 9
                return number;
        }
    }while(1);
}

int main(int argc, char** argv) {
    int number;
    char choice;
    do {
        //Enter number (1 - 9)
        number = inputNumber();
    
        //Display multiplication table
        outPut(number);
        
        fpurge(stdin);
        scanf("%s", &choice);
        switch ( choice ){
            case '\n': {
                //Enter number (1 - 9)
                number = inputNumber();

                //Display multiplication table
                outPut(number);
            }   
            case 27: {
                return 0;
                break;
            }
            default : {
                printf("\nPress enter to continue, Esc to exit.\n");
                //break;
            }
        }
        
    }while (1);
    
    
    return (EXIT_SUCCESS);
}

