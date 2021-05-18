#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int delete(int *size, int positionDelete, int arr[]) {
    int i;
    //Run loop position elements of array from the first element position is positionDelete to last position is size - 2
    for (i = positionDelete; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    arr = (int*) realloc(arr, *size * sizeof (int));
}

void removeDuplicate(int *size, int arr[]) {
    int i, j;
    //Run loop position elements of array from the first position is 0 to last position is size - 2
    for (i = 0; i < *size - 1; i++) {
        //Run loop position elements of array from the first element position after i to last element
        for (j = i + 1; j < *size; j++) {
            //If two values ​​are equal
            if (arr[i] == arr[j]) {
                delete(size, j, arr);
                j--;
            }
        }
    }
}

void display(int size, int arr[], char note[]) {
    int i;
    printf("\n%s", note);
    
    //Run loop position elements of array from the first element position is 0 to last element position
    for (i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
}

int inputElement(int pointFail) {
    char character;
    int number;
    do {
        fpurge(stdin);
        scanf("%d%c", &number, &character);

        //check character
        if (character != '\n') {
            printf("Invalid value! Retype the value");
            printf("\nElement[%d] = ", pointFail);
        } else
            //character == '\n'
            return number;
    } while (1);
}

int inputArr(int size, int arr[]) {
    int i;
    //Run loop position elements of array from the first element position is 0 to last element position
    for (i = 0; i < size; i++) {
        printf("Element[%d] = ", i);
        arr[i] = inputElement(i);
    }
}

int inputSize() {
    char character;
    int number;

    printf("Please enter size of array: ");
    do {
        fpurge(stdin);
        scanf("%d%c", &number, &character);

        //Check character
        if (character != '\n') {
            printf("Invalid value!");
            printf("\nRetype the value: ");
        } else {
            // character == '\n' && check number
            if (number <= 0) {
                printf("Invalid value! (value > 0)");
                printf("\nRetype the value: ");
            } else
                //character == '\n' && 0 < number <= 10
                return number;
        }
    } while (1);
}

int main() {
    int *arr;
      
    //Step 1: Enter the size of array
    int size;
    size = inputSize();
    
    //Step 2: Enter value of array
    arr = (int *) malloc(size * sizeof (int));
    inputArr(size, arr);

    printf("\nSize before remove: %d\n", size);
    
    //Step 3: Display the original array
    display(size, arr, "The original array:\n");


    //Step 4: Remove duplicate element
    removeDuplicate(&size, arr);
    
    printf("\nSize after remove: %d\n", size);

    //Step5: Display after remove duplicate element
    display(size, arr, "\nThe array after removing duplicate elements:\n");
    
    free(arr);

    return (EXIT_SUCCESS);
}

