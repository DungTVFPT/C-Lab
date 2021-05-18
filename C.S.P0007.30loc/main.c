#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void checkContinue(int *status) {
    char choice;
    printf("\nPress enter to continue, Esc to exit");
alo:
    fpurge(stdin);
    choice = getchar();
    //If choice = Esc
    if (choice == 27) {
        *status = 0;
    } else {
        //If choice = Enter
        if (choice == '\n') {
            *status = 1;
        } else {
            printf("Please Enter or Esc");
            goto alo;
        }
    }
}

void display(char str[], int size) {
    printf("The string after removing: ");
    // consider from first character to last character 
    for (int i = 0; i < size; i++) {
        printf("%c", str[i]);
    }
}

void removed(char str[], int positionDelete, int *size) {
    //Run loop from after first character to nearly last character
    for (int i = positionDelete; i < *size - 1; i++) {
        str[i] = str[i + 1];
    }
    str[*size - 1] = '\0';
    (*size)--;
    str = (char*) realloc(str, *size * sizeof (char));

}

void removeunescessaryBlank(char str[], int *size) {
    //Check first character
    while (str[0] == ' ') {
        removed(str, 0, size);
    }
    //Run loop from after first character to nearly last character
    for (int i = 0; i < strlen(str) - 1; i++) {
        //If two character nearly = ' '
        if (str[i] == ' ' && str[i + 1] == ' ') {
            removed(str, i, size);
            i--;
        }
    }
    //Check last character
    while (str[strlen(str) - 1] == ' ') {
        removed(str, strlen(str) - 1, size);
    }
}

void inputString(char str[], int *size) {
    char character;
    int i = 0;
    int check;
    int count;
    printf("Please enter string: ");
    do {
        check = 0;
        count = 0;
        i = 0;
        *size = 0;
        do {
            character = getc(stdin);
            // compare character get from keyboard with '\n'
            if (character == '\n') {
                break;
            }
            ++(*size);
            str = (char*) realloc(str, (*size) * sizeof (char));
            str[i] = character;
            i++;
        } while (1);
        str[i] = '\0';
        // consider character from begin to end string
        for (int j = 0; j < (*size); j++) {
            // compare ascii of element at position j with ' '
            if (str[j] == ' ') {
                count++;
            }
            //If characters such as @, #, !, [, ], {, }, (, )
            if ((str[j] == 64) || (str[j] == 35) || (str[j] == 33) || (str[j] == 91)
                    || (str[j] == 93) || (str[j] == 123) || (str[j] == 125) || (str[j] == 40) || (str[j] == 41)) {
                check = 1;
                break;
            }
        }
        // compare amount of space-bar's appearence with string size
        if (count == *size) {
            printf("String not allow to be covered by all blank\n");
            printf("Retype a string: ");
        } else //if count != size, compare check with 1
            if ((count != *size)&&(check == 1)) {
            printf("String can not be contain special character such as @,#,!,[,],{,},(,) ");
            printf("\nRetype a string: ");
        } else // string don't have any special character and not covered by all blank
            break;
    } while (1);
}

int main(int argc, char** argv) {

    int status;
    do {
        char *str;
        int size = 0;

        //Step1: Enter a string
        str = (char *) malloc(size * sizeof (char));
        inputString(str, &size);

        //Step2: Remove all unnecessary blank
        removeunescessaryBlank(str, &size);

        //Step3: Display the string
        display(str, size);

        free(str);

        //Step4: Check continue
        checkContinue(&status);


    } while (status == 1); // loop until get esc
    return (EXIT_SUCCESS);
}