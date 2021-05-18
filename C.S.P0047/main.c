#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct listStudent {
    char name[50];
} student[100];

typedef struct listStudent listStudent;

int inputChoice() {
    int choice;
    int min = 1, max = 5;
    char character;
    
    do{
        fpurge(stdin);
        scanf("%d%c", &choice, &character);
        if(character != '\n') {
            printf("INVALID CHOICE!!!");
            printf("\nPlease retype the choice: ");
        }else {
            if((choice < min) || (choice > max)) {
                printf("INVALID CHOICE!!!");
                printf("\nPlease retype the choice from 1 to 5: ");
            }else {
                return choice;
            }
        }
    }while(1);
}

void swap(listStudent *a, listStudent *b){
	listStudent temp;
	temp=*a; *a=*b; *b=temp;
}


void remove2(char s[], int k) {
	if(k < 0 || k >= strlen(s)) {
		return;
	}
	for(int i = k; i < strlen(s) - 1; i++) {
		s[i] = s[i + 1];
	}
	s[strlen(s) - 1] = '\0';
}

void standardizeString(char a[]) {
    while(a[0] == ' ') {
        remove2(a,0);
    } 
    a[0] = toupper(a[0]);

    while(a[strlen(a) - 1] == ' ') {
        remove2(a,strlen(a) - 1);
    } 

    for(int i = 0; i < strlen(a); i++) {
        while(a[i] == ' ' && a[i + 1] == ' ') {
            remove2(a,i);
        }

        if(a[i] == ' ' && a[i + 1] != ' ') {
            a[i + 1] = toupper(a[i + 1]);
        }
    }	
}

//Output
void function5(int *amountStudent) {
    if(*amountStudent == 0) {
        printf("Empty list, please add a student !!!\n");
    }else {
        int i;
        for(i = 0; i < *amountStudent - 1; i++) {
            for(int j = 1; j < *amountStudent; j++) {
                if(strcmp(student[i].name, student[j].name) > 0) {
                    swap(&student[i], &student[j]);
                    i--;
                }
            }
        }
        
        printf("List Student:\n");
        
        for(i = 0; i < *amountStudent; i++) {
            printf("%d. %s\n", i + 1, student[i].name);
        }
    }   
}
    
    

//Search
void function4(int amountStudent) {
    if(amountStudent == 0) {
        printf("Empty list, please add a student !!!\n");
    }else {
        
        char searchName[50];
        printf("Enter a name student: ");
        gets(searchName);
        standardizeString(searchName);
        
        int i, exist = 0;
        
        for(i = 0; i < amountStudent; i++) {
            if(strcmp(student[i].name, searchName)==0){
                exist = 1; 
                break; 
            }    
        }
        
        if(exist == 1) {
            printf("The position of %s is: %d\n", searchName, i + 1);
        }else {
            printf(" Student \"%s\" not exist on list.\n", searchName);
            
        }    
    }
}

//Remove
void function3(int *amountStudent) {
    if(*amountStudent == 0) {
        printf("Empty list, please add a student !!!\n");
    }else {
        
        char removeName[50];
        printf("Enter a name student: ");
        gets(removeName);
        standardizeString(removeName);
        int i, exist = 0;
        
        for(i = 0; i < *amountStudent; i++) {
            if(strcmp(student[i].name, removeName)==0){
                exist = 1; 
                break; 
            }    
        }
        
        if(exist == 1) {
            for(int k = i; k < *amountStudent; k++){
                swap(&student[k], &student[k+1]);
            }
            printf("Student \"%s\" has been removed successfully!\n", removeName);
            --(*amountStudent);
        }else {
            printf("Student \"%s\" not exist on list.\n", removeName);
        }    
    }
}


//Add
int function2(int *amountStudent) {
    if(*amountStudent > 100) {
        printf("The list has full. It cannot add a new student");
    }else {
        printf("Enter a new name: ");
        fpurge(stdin);
        
        gets(student[*amountStudent].name);
        standardizeString(student[*amountStudent].name);
        
        printf("Student \"%s\" has been added to list successfully!\n", student[*amountStudent].name);
        ++*amountStudent;
    }
    
}

//Display and asks users to input an opinion
void function1() {
    printf("**************************\n");
    printf("1. Add a student name into the array.\n");
    printf("2. Remove a student name.\n");
    printf("3. Search a student name.\n");
    printf("4. Output student names in ascending orders alphabetically\n");
    printf("5. Exit the program.\n");
    
    //Number of original students
    int amountStudent = 0;
    do{
        printf("\nEnter your choice: ");
        int choice;
        choice = inputChoice();
        
        switch ( choice ) {
            case 1: 
                //Add a student
                function2(&amountStudent);
                break;
            case 2:
                //Remove a student
                function3(&amountStudent);
                break;
            case 3:
                //Search
                function4(amountStudent);
                break;
            case 4:
                //Output ascending
                function5(&amountStudent);
                break;
            case 5:
                return;
        }
    }while(1);
}

int main() {

    printf("========Student Management=======\n");
    
    //Display program
    function1();
    
    
}