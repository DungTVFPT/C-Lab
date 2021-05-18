
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define fee 0.25
#define reward_1 0.50
#define reward_2 10.00

int checkResult() {
    int arr[3];
    srand(time(NULL));
    int i;
    //Run loop from first number to last number of result
    for (i = 0; i < 3; i++) {
        arr[i] = 1 + rand() % 9;
    }

    printf("The slot machine shows: %d%d%d.\n", arr[0], arr[1], arr[2]);

    int count = 0;
    //If first number equal two number
    if (arr[0] == arr[1])
        count++;
    //If first number equal three number
    if (arr[0] == arr[2])
        count++;
    //If two number equal three number
    if (arr[1] == arr[2])
        count++;
    //If result does has number equal
    if (count == 0) {
        return 1;
    }
    //If result has two number equal
    if (count == 1) {
        return 2;
    }
    //If result has three number equal
    if (count == 3) {
        return 3;
    }
}

void cashOut(char file[], float *money){   
    printf("Thank you for playing! You end with $%.2f\n", *money);
    *money = 0;
    FILE* fl;
    fl = fopen(file, "w+");
    fprintf(fl, "%.2f", money);
    fclose(fl);
}

void saveGame(char file[], float money) {
    FILE* fl;
    fl = fopen(file, "w+");
    fprintf(fl, "%.2f", money);
    printf("Your money had saved!\n");
    fclose(fl);
}

void play(float *money) {
    //If money is not enough one time to play
    if (*money < fee) {
        printf("You have no money!!!\n");
    } else {
        *money = *money - fee;
        int result;
        result = checkResult();
        //If the result does not have two or three equal numbers
        if (result == 1) {
            printf("Sorry you don't win anything.\n");
            printf("You have $%.2f.\n", *money);
        } else {
            //If the result have two equal numbers
            if (result == 2) {
                *money = *money + reward_1;
                printf("You win 50 cents!\n");
                printf("You have $%.2f.\n", *money);
            } else {
                //If the result have three equal numbers
                *money = *money + reward_2;
                printf("You win the big prize, $10.00!\n");
                printf("You have $%.2f.\n", *money);
            }
        }
    }
}

int inputChoice() {
    char character;
    int number;
    do {
        scanf("%d%c", &number, &character);
        fpurge(stdin);

        //Check character
        if (character != '\n') {
            printf("Invalid value!");
            printf("\nRetype the choice: ");
        } else {
            // character == '\n' && check number
            if (number <= 0 || number > 3) {
                printf("Invalid value! (0 < choice <= 3)");
                printf("\nRetype the choice: ");
            } else
                //character == '\n' && 0 < number <= 3
                return number;
        }
    } while (1);
}

void menu() {  
    printf("Choose one of the following menu options: \n");
    printf("1) Play the slot machine. \n");
    printf("2) Save game. \n");
    printf("3) Cash out. \n");
}

float getFromFile(char file[]) {
    FILE *fl;
    fl = fopen(file, "r");
    float money;
    float moneyInFile;
    
    //If fl is not NULL
    if (fl != NULL) {
        fseek(fl, SEEK_SET, SEEK_END);
        int size = ftell(fl);

        //If file empty
        if (0 == size) {
            printf("File exist!\nInvalid data!\n");
            money = 10.00;
        } else {
            char character;
            rewind(fl);
            fscanf(fl,"%f%c", &moneyInFile, &character);
            fpurge(stdin);
            //If character is not '\0'
            if(character != '\0'){
                printf("File exist!\nInvalid data!\n");
                money = 10.00;
            }else{
                //If money is not enough one time to play
                if(moneyInFile < fee){
                    printf("File exist!\nInvalid data!\n");
                    money = 10.00;
                }else{
                    //If money enough to play
                    printf("File exist!\n");
                    money = moneyInFile;
                }
            }           
        }
    } else {
        //If file not exist
        printf("File not exist!\n");
        money = 10.00;
    }
    fclose(fl);
    return money;
}

int main(int argc, char** argv) {
    int status = 1;
    const char *file = "SaveGame.txt";
    
    float money;
    money = getFromFile(file);
    
    printf("You have $%.2f.\n", money);
    do {
        menu();
        int choice;
        choice = inputChoice();

        switch (choice) {
            case 1:
                //Play game
                play(&money);
                break;
            case 2:
                //Save game
                saveGame(file, money);
                break;
            case 3:
                //Cash out
                cashOut(file, &money);  
                status = 0;
                break;
        }
    } while (status == 1);

    return (EXIT_SUCCESS);
}

