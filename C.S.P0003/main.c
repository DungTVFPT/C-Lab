
#include <stdio.h>
#include <stdlib.h>

//New array
void newArray(int arr[], int *size, int positionInsert, int newValue) {
    //Expand the memory of the array
    arr = (int*) realloc(arr, (*size + 1) * sizeof (int));

    //Run loop position elements of array from the first position is size to last position is positionInsert + 1
    for (int i = *size; i > positionInsert; i--) {
        arr[i] = arr[i - 1];
    }
    arr[positionInsert] = newValue;
    (*size)++;
}

//Find position
int findPosition(int newValue, int arr[], int size) {
    //Run loop position elements of array from the first position is 0 to last position is size - 1
    for (int i = 0; i < size; i++) {
        //If newValue < first value
        if(newValue <= arr[i]){
            return i;
        } 
        //If first value < newValue < last value
        if( (arr[i] < newValue) && (newValue <= arr[i + 1])){
            return i + 1;
        } 
        //If newValue > last value
        if(newValue > arr[size - 1]){
            return size;
        }    
    }
}

//Swap function
void swap(int *bigValue, int *smallValue) {
    //temp is intermediate value
    int temp;
    temp = *bigValue;
    *bigValue = *smallValue;
    *smallValue = temp;
}

//Sorting function
void sorting(int size, int arr[]) {
    int i, j;
    //Run loop position elements of array from the first element position is 0 to last position is size - 1
    for (i = 0; i < size - 1; i++) {
        //Run loop position elements of array from the first element position after i to last element
        for (j = i + 1; j < size; j++) {
            //Swap if the previous element is greater than the following to sort ascending  
            if (arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
        }
    }
}

//Input and check value
int inputNewValue() {
    char character;
    int value;

    do {
        //Delete buffer
        fpurge(stdin);
        scanf("%d%c", &value, &character);

        //Check character
        if (character != '\n') {
            printf("INVALID VALUE!");
            printf("\nRetype the value: ");
        } else {
            //Character = '\n'
            return value;
        }
    } while (1);
}

//Display on the screen
void display(int size, int arr[], char note[50]) {
    //Print notice
    printf("%s", note);

    //Run loop position elements of array from the first position is 0 to last position is size - 1 
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
}

int inputElement(int pointFail) {
    char character;
    int value;

    do {
        //Delete buffer
        fpurge(stdin);
        scanf("%d%c", &value, &character);

        //Check character
        if (character != '\n') {
            printf("INVALID VALUE!");
            printf("\nRetype element[%d]: ", pointFail);
        } else {
            //Character = '\n'
            return value;
        }
    } while (1);
}


//Enter the element into the array
void enterElement(int size, int arr[]) {
    int i;
    //Run loop position elements of array from the first position is 0 to last position is size - 1
    for (i = 0; i < size; i++) {
        printf("Enter element[%d]: ", i);
        arr[i] = inputElement(i);
    }
}

int inputValue() {
    char character;
    int number;
    do{
        fpurge(stdin);
        scanf("%d%c", &number, &character);
        
        //Check character
        if(character != '\n'){
            printf("\nInvalid value!");
            printf("\nRetype the value: ");
        }else{
            // character == '\n' && check number
            if( number <= 0 ) {
                printf("\nInvalid value! (size > 0)");
                printf("\nRetype the value: ");
            }
            else
                //character == '\n' && 0 < number <= 10
                return number;
        }     
    }while(1);   
}

int main(int argc, char** argv) {
    int *arr, size, newValue, positionInsert;
    arr = (int *) malloc(size * sizeof (int));
    
    //Step1: Enter the size of array
    printf("Please enter size of array: ");
    size = inputValue();

    //Step2: Enter the element into the array
    enterElement(size, arr);

    //Step3: Sorting array
    sorting(size, arr);

    //Step4: Display array
    display(size, arr, "The array after sorting\n");

    //Step5: Enter new value
    printf("\nPlease enter new value: ");
    newValue = inputNewValue();

    //Step6: Find position insert
    positionInsert = findPosition(newValue, arr, size);

    //Step7: New array
    newArray(arr, &size, positionInsert, newValue);

    //Step8: Display array after insert new value
    display(size, arr, "New array:\n");

    
    free(arr);
    return (EXIT_SUCCESS);
}

