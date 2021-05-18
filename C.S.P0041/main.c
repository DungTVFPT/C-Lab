#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int size){
    int i;
    printf("Array elements:\n");
    
    //Run loop from first element to last element of array
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]); 
    } 
    
    printf("\n\n");
    
    //Run loop from second element to last element of array
    int max = arr[0];
    for(i = 1; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }  
    printf("Array maximum value:\nThe max is %d", max);
    
    printf("\n\n");
    
    //Display array even
    printf("Array even values:\n");
    //Run loop from first element to last element of array
    int count = 0;
    for(i = 0; i < size; i++){
        if(arr[i] % 2 == 0){
            count++;
            printf("%d ", arr[i]);
        }
    }
    if(count == 0){
        printf("Array don't have even number\n");
    }
    

}

int inputSize(int min, int max) {
    printf("Enter the size of an array\n");

    do {
        int number;
        char character;
        scanf("%d%c", &number, &character);
        fpurge(stdin);
        //Compare character with '\n'
        if (character != '\n') {
            printf("Invalid value, please retype:\n");
        } else {
            //If size <= 0
            if (number < min || number > max) {
                printf("Size must be greater than 0 and smaller than 100, please retype:\n");
            } else {
                return number;
            }
        }
    } while (1);
}

int inputValue() {
    do {
        int number;
        char character;
        scanf("%d%c", &number, &character);
        fpurge(stdin);
        //Compare character with '\n'
        if (character != '\n') {
            printf("Invalid value, please retype:\n");
        } else {
            return number;
        }
    } while (1);
}

void inputElement(int arr[], int size) {
    printf("Enter the elements of the array\n");

    //Run loop from first element to last element
    for (int i = 0; i < size; i++) {
        arr[i] = inputValue();
    }
    printf("\n");
}

int main(int argc, char** argv) {
    int size;
    //Step1: Input size
    size = inputSize(1,100);

    //Step2: Input element
    int arr[size];
    inputElement(arr, size);
    
    //Step3: Display
    display(arr, size);

    return (EXIT_SUCCESS);
}

