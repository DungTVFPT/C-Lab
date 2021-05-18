/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: DAOTHAOVAN
 *
 * Created on March 16, 2020, 3:29 PM
 */

//#include <cstdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include <locale.h>
FILE* file;

int checkContent(char fileName[]) {
    file = fopen(fileName, "r");
    int check = 0;
    char content;
    int count = 0;
    do {
        //Get content in file
        content = getc(file);
        //end of file
        if (content == EOF) {
            break;
        }
        else {
            //if it contains special characters
            if ((content > 122) || (content > 57 && content < 97) || (content > 20 && content < 48)) {
                printf("Invalid data\n");
                count++;//Increases the count by 1 because it contains content
                check = 0;//content is invalid
                break;
            }
            //If the characters are valid
            else {
                count++;//Increases the count by 1 because it contains content
                check = 1;//content is valid
            }

        }
    } while (1);
    //When there is no content, the variable counts = 0
    if (count == 0) {
        printf("NULL\n");
        check = 0;//content is invalid
    }
    return check;
}

char* chooseFile() {
    char* fileName = (char*) malloc(sizeof (char));
    do {
        printf("What file stores the puzzle words?\n");
        fpurge(stdin);
        //Enter file name
        scanf("%[^\n]", fileName);
        file = fopen(fileName, "r");
        //If file doesn't exist
        if (file == NULL) {
            printf("File NOT exist\n");
        }//if file exist
        else {
            //if content is valid
            if (checkContent(fileName) != 1) {
                continue;
            }
            //if content is invalid
            else {
                break;
            }
        }
    } while (1);
    return fileName;
    fclose(file);
}

void getWord(char* filename, int *line, int *len) {
    file = fopen(filename, "r");
    char* content = (char*) malloc(sizeof (char));
    *line = 0; //number of words (lines) in the file
    *len = 0; //length of the string
    int max;
    //File exist   
    while (!feof(file)) {
        fgets(content, sizeof (content), file);
        //Increase the number of words by 1
        ++(*line);
        // Assign len equal to the length of the longest word in the file
        //Let max equal to the length of 1 word in the file
        max = strlen(content);
        //if words are longer than length
        if (max >= *len) {
            *len = max;
        }
    }
}

int askToPlay() {
    char* ask = (char*) malloc(sizeof (char));
    int check;
    while (1) {
        printf("Would you like to play Hangman (yes/no): \n");
        fpurge(stdin);
        //Enter String
        scanf("%[^\n]", ask);
        //Enter 'yes'
        if (strcmp(ask, "yes") == 0) {
            check = 1; //Play
            break;
        }//Enter 'no'
        else if (strcmp(ask, "no") == 0) {
            check = 0; //Out
            break;
        }//Enter others
        else
            printf("( INVALID WORDS, PLEASE TRY AGAIN )\n\n");
    }
    return check;
}
//Check if the player has entered invalid characters

char checkChar() {
    char* ch = (char*) malloc(sizeof (char));
    char temp;
    do {
        fpurge(stdin);
        fgets(ch, sizeof (ch), stdin);
        int is_one_char_input = strlen(ch) == 2 && ch[1] == '\n';
        //If the user enters multiple characters
        if (!is_one_char_input) {
            //if the user enters the character enter
            if (strlen(ch) == 1) {
                printf("You pressed 'Enter'. Please enter a character!\n");
            }//if the user enters a valid character
            else {
                printf("Please enter only 1 character!\n");
            }
        } else {
            // Convert characters to lowercase letters
            temp = tolower(ch[0]);
            // If special characters
            if (temp > 122 || (temp > 57 && temp < 97) || temp < 48) {
                printf("\nDon't except special character\n");
                continue;
            }//if it's a number or a letter
            else {
                break;
            }
        }
    } while (1);
    return temp;
}
//See if the entered letter belongs to the string

int indexof(char str[], char ch) {
    //Consider from the beginning of the chain to the end of the string
    for (int i = 0; i < strlen(str); i++) {
        //If the letter = the letter at position i in the string
        if (str[i] == ch) {
            return i;
        }
    }
    return -1;
}
//Delete characters in the string by position

void deleteChar(char str[], int pos) {

    int n = strlen(str);
    //Consider from the position you want to delete to the end of the string
    for (int i = pos; i < n; i++) {
        str[i] = str[i + 1];
    }
    str[n - 1] = 0;
}
//Delete duplicate characters

void deleteDuplicate(char str[]) {
    //Consider from beginning to end of string most
    for (int i = 0; i < strlen(str) - 1; i++) {
        //Consider from the next position i to the end of the string
        for (int j = i + 1; j < strlen(str); j++) {
            // If 2 locations have the same character
            if (str[i] == str[j]) {
                deleteChar(str, j);
                j--;
            }
        }
    }
}
//Random

int randomW(int line) {
    int index;
    srand(time(NULL));
    //Get random position of word
    index = rand() % (line);
    return index;
}
//Create an array to save words to guess

void saveTemp(char wordTemp[], char targetTemp[]) {
    //Copy the word to be guessed in the clipboard
    strcpy(wordTemp, targetTemp);
    //Delete repetitive words in words to guess
    deleteDuplicate(wordTemp);
}
//Create a 2-dimensional array to store words in a file

void listWord(char fileName[], int len, char puzzle[][len]) {
    int i;
    file = fopen(fileName, "r");
    while (!feof(file)) {
        //assign a word to an element in an array
        fscanf(file, "%s", puzzle[i++]);
    }
    fclose(file);
}
//Save the array that the player guessed as '----'

void saveGuess(char Mword[], int size) {
    strcpy(Mword, "");
    //Look at each letter from beginning to end of words 
    for (int i = 0; i < size; i++) {
        Mword[i] = '-';
    }
    Mword[size] = 0; // end of string
}
//Show word after guessing

void displayLetter(int size, char guess, char Mword[], int index, int len, char puzzle[index][len]) {
    for (int j = 0; j < size; j++) {
        //If the letter they guessed is the letter j at the j position of the word to guess
        if (guess == puzzle[index][j]) {
            Mword[j] = guess; // turn '-' into the correct letter
        }
    }
}
//Play Game

void guessWord(char fileName[]) {

    int turnMax = 5; //Most wrong guesses
    int turnWrong = 0; // Wrong guess
    int turnTrue = 0; // True guess
    int line; //The number of words in the file
    int len; //The length of the word

    //Step1: Get the numbers of word and word length
    getWord(fileName, &line, &len);

    //Step2: Get random 1 word to play:
    int index = randomW(line);

    //Step3: Initialize the array to store the words contained in the file
    char puzzle[line][len];
    listWord(fileName, len, puzzle);

    //Initialize the temporary array for words to guess
    char wordTemp[len];
    saveTemp(wordTemp, puzzle[index]);

    //Step4: Initialize the saved word array that the player guesses
    char Mword[strlen(wordTemp)];
    int size = strlen(puzzle[index]); //length of word to be choose
    saveGuess(Mword, size);

    while (1) {

        printf("You currently have %d incorrect guessess\n", turnWrong);
        printf("Here is your puzzle:\n%s", Mword);
        printf("\nPlease enter your guess:\n");
        //Step5: Players enter the letters they guess
        char guess = checkChar();
        fpurge(stdin);
        //Step6: Check
        //If guess the right letter       
        if (indexof(puzzle[index], guess) != -1) {

            // If this letter was previously guessed
            if (indexof(Mword, guess) != -1) {
                turnWrong++;
                printf("The %c exist\n", guess);
                printf("Incorrect %d\n", turnWrong);

            }//If this letter was not previously guessed
            else {
                turnTrue++; //increase turn True
                //If the correct guess is equal to the length of the word -> guess the right word
                if (turnTrue == strlen(wordTemp)) {
                    printf("Congratulations!You got correct word %s\n", puzzle[index]);
                    break;
                }//If the correct guess is not equal the length of the word -> the word is not really guessed correctly
                else {
                    printf("Congratulations,you guessed a letter in the puzzle!\n");
                    //Display the word after guessing the letter
                    displayLetter(size, guess, Mword, index, len, puzzle);
                }
            }
        }//if guess wrong letter
        else {
            turnWrong++;
            printf("\nSorry,that letter is not in the puzzle.\n");
        }
        //Run out of turn
        if (turnWrong == turnMax) {
            printf("\nSorry,you have made 5 incorrect guesses,you lose\n");
            printf("The correct word was %s\n", puzzle[index]);
            break;
        }
    }
}

/*
 * 
 */
int main(int argc, char** argv) {

    do {
        char* fileName = chooseFile();
        //Play or Not
        int ys = askToPlay();
        //Don't Play
        if (ys == 0) {
            break;
        }//Play Game
        else {
            guessWord(fileName);
        }
        printf("\nThanks for playing!\n");
    } while (1);

}


