#include <stdio.h>
#include <stdlib.h>

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

void reversStr(char str[], int size){
    //After print out first character
    if(size < 0){
        return;
    }else{
        printf("%c", str[size - 1]); // hello size = 5, vtr 4 ol
        size--; //size = 3
        reversStr(str, size);
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
        }        
        // compare amount of space appear with string size
        if (count == *size) {
            printf("String not allow to be covered by all blank\n");
            printf("Retype a string: ");
        } else {
            break;
        }
    } while (1);
}

int main(int argc, char** argv) {
    int status;
    do {
        char *str;
        int size = 0;
        str = (char *) malloc(size * sizeof (char));
        
        //Step1: Enter a string       
        inputString(str, &size);
        
        //Step2: Reverse string
        printf("Result:\n");
        reversStr(str, size);
        printf("\n");

        free(str);
        
        //Check continue
        checkContinue(&status);
    } while (status == 1); // loop until get esc
    return (EXIT_SUCCESS);
}

