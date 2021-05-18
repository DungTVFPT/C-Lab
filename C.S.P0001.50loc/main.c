#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int Continue() {
    char character;
    printf("\nPress enter to continue another reverse, Esc to exit.");
alo:
    fpurge(stdin);
    character = getchar();
    //Compare the character get from keyboard with Ascii of esc (27)
    if (character == 27) {
        return 0;
    } else {
        // compare the character get from keyboard with the enter '\n'
        if (character == '\n') {
            return 1;
        } else {
            // if character different with esc and enter
            printf("Please enter enter or esc");
            goto alo;
        }

    }
}

int checkStr(char str[], int size) {
    //Run loop from first character to last character
    for (int i = 0; i < size; i++) {
        //Compare element i with '_'
        if (str[i] == '_') {
            return 1;
        }
    }
    return 0;
}

void inputString(char str[], int *size) {

    char character;
    int i = 0;
    int check = 1;
    *size = 0;
    printf("Please enter string: ");

    do {
        character = getc(stdin);
        //Character = '\n' exits
        if (character == '\n') {
            break;
        }
        ++(*size);
        str = (char*) realloc(str, (*size) * sizeof (char));
        str[i] = character;
        i++;
    } while (1);
    str[i] = '\0';


}

char* reverseString(char* str, char* revstr) {
    int i = 0, position;
    int size = 0;
    int characterStart = strlen(str) - 1;
    int lastCharacter = strlen(str) - 1;

    //Run loop to get each character of string    
    while (characterStart > 0) {
        //Compare character at each position with "_"        
        if (str[characterStart] == '_') {
            position = characterStart + 1;

            //Run loop from character from after '_' of word to end of word
            while (position <= lastCharacter) {
                size++;
                revstr = (char*) realloc(revstr, size * sizeof (char));
                revstr[i] = str[position];
                position++;
                i++;
            }
            revstr[i++] = '_';
            //New last character
            lastCharacter = characterStart - 1;
        }
        characterStart--;
    }
    //Run loop from fist character to last character of first word in old string
    for (position = 0; position <= lastCharacter; position++) {
        revstr[i] = str[position];
        i++;
    }
    revstr[i] = '\0';
    return revstr;

}

int main(int argc, char** argv) {
    //int status;
    do {
        int size = 0;
        char* str = (char*) malloc(sizeof (char));
        char* revstr = (char*) malloc(sizeof (char));

        //step 1: Input string from keyboard
        inputString(str, &size);

        // step 2: Display old string
        printf("The old string: %s\n", str);
        
        //Step 3: Rever string if check = 1
        if (checkStr(str, size) == 1) {
            //Reverse string
            revstr = reverseString(str, revstr);

            //Display reversed string
            printf("The reversed string: %s", revstr);
        } else {
            printf("String without '_' , cannot be reversed!");
        }

        fpurge(stdin);
        free(str);
        free(revstr);

    } while (Continue() == 1);

    return (EXIT_SUCCESS);
}