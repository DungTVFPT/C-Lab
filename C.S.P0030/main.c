#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

void outPut(int sumEven, int sumOdd) {
    printf("Sum of Even=%d", sumEven);
    printf("\nSum of Odd=%d", sumOdd);
}

int getSum(int n, int arr[], int *sumOdd, int *sumEven) {
    int i;
    int sumO = 0;
    int sumE = 0;
    //Run loop from first element to last element
    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            sumE += arr[i];
        } else {
            sumO += arr[i];
        }
    }
    
    *sumEven = sumE;
    *sumOdd = sumO;

}


int inputValue(int min, int max, char note[]) {
    char character;
    int number;
    
    do {
        fpurge(stdin);
        scanf("%d%c", &number, &character);

        //Check character
        if (character != '\n') {
            printf("Invalid value!");
            printf("\nRetype the value: ");
        } else {
            // character == '\n' && check number
            if ((number < min) || (number > max)) {
                printf("%s", note);
                printf("\nRetype the value: ");
            } else
                return number;
        }
    } while (1);
}

int inputArr(int n, int arr[]) {
    int i = 0;
    printf("Input elements:\n");
    //Run loop from first element to last element
    for (i = 0; i < n; i++) {
        printf("\tElement %d=", i + 1);
        arr[i] = inputValue(0, INT_MAX, "Value must be a natural number");
    }
}

int main() {
    printf("Sum Even Odd program\n");
    printf("Enter a number of element n=");
    //Step 1: Input amount n element
    int n;
    n = inputValue(1,10, "Value must be greater than 0 less than 10");

    //Step 2: Input value of element
    int arr[n];
    arr[n] = inputArr(n, arr);

    //Step 3: Calculate sum
    int sumOdd, sumEven;
    getSum(n, arr, &sumOdd, &sumEven);

    //Step 4: Output
    outPut(sumEven, sumOdd);

    return (EXIT_SUCCESS);
}

