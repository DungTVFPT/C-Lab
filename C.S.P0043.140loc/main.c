#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void display(int *arr, int size) {
    //Empty array
    if (size == 0) {
        printf("In array don't have any element.\n");
        printf("Please input a number into array!\n");
    }else {
        for (int i = 0; i < size; i++) {
            printf("\t%d", arr[i]);
        }
    }
}

void sortDescending(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[j]; //temp is intermediate value
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void sortAscending(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[j]; //temp is intermediate value
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void copy(int arr[], int arrCoppy[], int size) {
    for (int i = 0; i < size; i++) {
        arrCoppy[i] = arr[i];
    }
}

void deletePosition(int *arr, int *size, int position) {
    for (int i = position; i <*size; i++) {
        arr[i] = arr[i + 1];
    }
    
    //New size of array after delete
    (*size)--;
    arr = (int*) realloc(arr, (*size) * sizeof (int));
    
}

int existValue(int *arr, int size, int searchValue) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == searchValue) {
            return 1;
        }
    }
    return 0;
}

int inputCheck() {
    char character;
    int value;
    
    printf("Enter a number: ");
    do{
        //Delete buffer
        fpurge(stdin);
        scanf("%d%c", &value, &character);
        
        //Check character
        if(character != '\n'){
            printf("INVALID VALUE!");
            printf("\nRetype the value: ");
        }else{
            //Character = '\n'
            return value;
        }     
    }while(1);   
}

void removeAllExistValue(int *arr, int *size) {
    //Empty array
    if (*size == 0) {
        printf("In array don't have any element.\n");
        printf("Please input a number into array!\n");
    } else {
        //Input and check remove value
        int removeValue = inputCheck();
        
        //If check searchValue exist in array
        if ( existValue(arr, *size, removeValue) ) {
            int i;
            for (i = 0; i< *size; i++) {
                if (arr[i] == removeValue) {
                    //i is the location to delete
                    deletePosition(arr, size, i);
                    //i-- is the new i position after deleted un scanned
                    i--;
                }
            }
            
            printf("New Array:\n");
            display(arr, *size);
            printf("\n");
        } 
        //If check searchValue exist out array
        else {
            printf("In array don't have number you were entered\n");
        }
    }
}

void removeFirstExistValue(int *arr, int *size) {
    //Empty array
    if (*size == 0) {
        printf("In array don't have any element.\n");
        printf("Please input a number into array!\n");
    }else {
        //Input and check remove value
        int removeValue = inputCheck();
        
        //If check searchValue exist in array
        if ( existValue(arr, *size, removeValue) ) {
            int i;
            for (i = 0; i< *size; i++) {
                if (arr[i] == removeValue) {
                    
                    //i is the location to delete
                    deletePosition(arr, size, i);
              
                    break;
                }
            }
            
            printf("Removed successful !!!\n");
            printf("New Array:\n");
            display(arr, *size);
            printf("\n");
        }
        //If check searchValue exist out array
        else {
            printf("In array don't have number you were entered\n");
        }
    }
}

void search(int *arr, int size) {
    //Empty array
    if (size == 0) {
        printf("In array don't have any element.\n");
        printf("Please input a number into array!\n");
    }else {
        //Input and check value need to search
        int searchValue = inputCheck();
        
        //If check searchValue exist in array
        if ( existValue(arr, size, searchValue) ) {
            //display array
            printf("Array:\n");
            display(arr, size);
            printf("\n");
            
            printf("Number %d has index: ", searchValue);
            for (int i = 0; i < size; i++) {
                if (arr[i] == searchValue) {
                    printf("\t%d", i);
                }
            }
        }
        //If check searchValue exist out array
        else {
            printf("Array:\t");
            display(arr, size);
            printf("\n");
            printf("In array don't have number: %d.", searchValue);
        }
        printf("\n");
    }
}

int *add(int *arr, int *size) {
    ++(*size);
    
    //Maximum size
    if( (*size) > 100 ) {
        printf("Exceeded the allowed value !!!\n");
        return arr;
    }
    //Size <= 100
    else {
        //(*size) is new size of array
        arr = (int*) realloc(arr, (*size) * sizeof (int));
        fpurge(stdin);
        
        //Input and check new value element
        arr[*size - 1] = inputCheck();
    
        printf("Add element successfully !!!\n");
    }
   
    return arr;
}

void menu() {
    printf("--------Menu--------\n");
    printf("1- Add a value\n");
    printf("2- Search a value\n");
    printf("3- Remove the first existence of a value\n");
    printf("4- Remove all existences of a value\n");
    printf("5- Print out the array\n");
    printf("6- Sort the array in ascending order\n");
    printf("7- Sort the array in descending order\n");
    printf("Others- Quit\n");
    
}

int menuOption(int *arr, int size) {
    do {
        printf("\nEnter your choice: ");
        //Input choice
        int choice;
        scanf("%d", &choice);
        
        switch( choice ) {
            case 1://Add a value
            {
                arr = add(arr, &size);
                break;
            }
            case 2://Search a value
            {
                search(arr, size);
                break;
            }
            case 3://Remove the first existence of a value
            {
                removeFirstExistValue(arr, &size);
                break;
            }
            case 4://Remove all existences of a value
            {
                removeAllExistValue(arr, &size);
                break;
            }
            case 5://Display
            {
                printf("Array:\n");
                display(arr, size);
                printf("\n");
                break;
            }
            case 6://Sort the array in ascending order
            {
                int arrCoppy[size];
                
                copy(arr, arrCoppy, size);
                
                sortAscending(arrCoppy, size);
                
                printf("Arrays after ascending sort:\n");
                display(arrCoppy, size);
                printf("\n");
                
                break;
            }
            case 7://Sort the array in descending order
            {
                int arrCoppy[size];
                
                copy(arr, arrCoppy, size);
                
                sortDescending(arrCoppy, size);
                
                printf("Arrays after descending sort:\n");
                display(arrCoppy, size);
                printf("\n");
                
                break;
            }
            default:
            {
                return 0;
            }
        }
    } while (1);
}

int main(int argc, char** argv) {
    //Size of array start
    int size = 0;
    
    //Array contains values
    int *arr = (int *) malloc(size * sizeof (int));
    
    //Display a menu
    menu();
    
    //Function on menu
    menuOption(arr, size);
    
    free(arr);
    return (EXIT_SUCCESS);
}