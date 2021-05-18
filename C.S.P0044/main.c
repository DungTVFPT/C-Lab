#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int size) {
    //Empty array
    if (size == 0) {
        printf("In array don't have any element.\n");
        printf("Please input a number into array!\n");
    } else {
        //Run loop from first element to last element
        for (int i = 0; i < size; i++) {
            printf("\t%d", arr[i]);
        }
    }
}

void displaySearch(int arr[], int size) {
    //Empty array
    if (size == 0) {
        printf("In array don't have number.\n");
    } else {
        //Run loop from first element to last element
        printf("Number has index: ");
        for (int i = 0; i < size; i++) {
            printf("\t%d", arr[i]);
        }
        printf("\n");
    }
}

int inputCheck(char note[]) {
    char character;
    int value;

    printf("%s", note);
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

void sortAscending(int arr[], int size) {
    //Empty array
    if (size == 0) {
        printf("In array don't have any element.\n");
        printf("Please input a number into array!\n\n");
    } else {
        //Run loop from first element to last element
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                //Compare element at i with element at j
                if (arr[i] > arr[j]) {
                    int temp = arr[j]; //temp is intermediate value
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }

        printf("Array after ascending sort:");
        display(arr, size);
        printf("\n\n");
    }
}

void numbersInTheRange(int arr[], int size) {
    //Empty array
    if (size == 0) {
        printf("In array don't have any element.\n");
        printf("Please input a number into array!\n\n");
    } else {
        int minValue;
        int maxValue;
        //Compare min value with max value
        while (minValue > maxValue) {
            minValue = inputCheck("Enter a min value: ");
            fpurge(stdin);
            maxValue = inputCheck("Enter a max value: ");
            fpurge(stdin);
            //Compare min value with max value
            if (minValue > maxValue) {
                printf("Min value must be smaller max value!!!\n");
            }
        }

        int minValueInArr, maxValueInArr;
        minValueInArr = arr[0];
        maxValueInArr = arr[0];
        //Run loop from second element to last element
        for (int i = 1; i < size; i++) {
            //Compare value element i with min value
            if (arr[i] < minValueInArr) {
                minValueInArr = arr[i];
            }
            //Compare value element i with max value
            if (arr[i] > maxValueInArr) {
                maxValueInArr = arr[i];
            }
        }

        //Compare minValue, maxValue with minValueInArr, maxValueInArr
        if (minValue > maxValueInArr || maxValue < minValueInArr) {
            printf("There are no numbers in the range (%d -> %d)!!!\n", minValue, maxValue);
        } else {
            printf("Numbers in the range (%d -> %d): ", minValue, maxValue);
            //Run loop from first element to last element
            for (int i = 0; i < size; i++) {
                if (arr[i] >= minValue && arr[i] <= maxValue) {
                    printf("%d\t", arr[i]);
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}

int existValue(int arr[], int size, int searchValue) {
    //Run loop from firs element to last element of array
    for (int i = 0; i < size; i++) {
        if (arr[i] == searchValue) {
            return 1;
        }
    }
    return 0;
}

void printOut(int arr[], int size) {
    //Empty array
    if (size == 0) {
        printf("In array don't have any element.\n");
        printf("Please input a number into array!\n\n");
    } else {
        printf("Array: ");
        display(arr, size);
        printf("\n\n");
    }
}

//void search(int arr[], int size) {
//    //Empty array
//    if (size == 0) {
//        printf("In array don't have any element.\n");
//        printf("Please input a number into array!\n\n");
//    } else {
//        //Input and check value need to search
//        int searchValue = inputCheck("Enter a number search: ");
//
//        //If check searchValue exist in array
//        if (existValue(arr, size, searchValue)) {
//
//            printf("Number %d has index: ", searchValue);
//            //Run loop from firs element to last element of array
//            for (int i = 0; i < size; i++) {
//                if (arr[i] == searchValue) {
//                    printf("\t%d", i + 1);
//                }
//            }
//        }//If check searchValue exist out array
//        else {
//            printf("In array don't have number:\t%d", searchValue);
//        }
//        printf("\n\n");
//    }
//}

int *add(int *arr, int *size) {
    (*size)++;

    //Maximum size
    if ((*size) > 100) {
        printf("Exceeded the allowed value !!!\n\n");
    }//Size <= 100
    else {
        //(*size) is new size of array

        arr = (int*) realloc(arr, (*size) * sizeof (int));
        fpurge(stdin);

        //Input and check new value element
        arr[*size - 1] = inputCheck("Enter a number add: ");

        printf("Add element successfully !!!\n\n");
    }
    return arr;
}

int *search(int *arrSearch, int *sizeSearch, int *arr, int size) {
    //Input and check value need to search
    int searchValue = inputCheck("Enter a number search: ");

    //Run loop from firs element to last element of array
    for (int i = 0; i < size; i++) {
        if (arr[i] == searchValue) {
            (*sizeSearch)++;
            //(*sizeSearch) is new size of array
            arrSearch = (int*) realloc(arrSearch, (*sizeSearch) * sizeof (int));
            fpurge(stdin);
            arrSearch[*sizeSearch - 1] = i + 1;

        }
    }
    return arrSearch;
}

void menu() {
    printf("--------Menu--------\n");
    printf("1- Add a value\n");
    printf("2- Search a value\n");
    printf("3- Print out the array\n");
    printf("4- Print out values in a range of inputted min and max values, inclusively\n");
    printf("5- Sort the array in descending order\n");
    printf("Others- Quit\n");
}

int main(int argc, char** argv) {
    menu();
    int choice;

    int size = 0, sizeSearch = 0;
    int *arr, *arrSearch;
    arr = (int *) malloc(size * sizeof (int));
    arrSearch = (int *) malloc(sizeSearch * sizeof (int));

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                //Add a value
                arr = add(arr, &size);
                menu();
                break;
            case 2:
                //Search a value
                arrSearch = search(arrSearch, &sizeSearch, arr, size);
                displaySearch(arrSearch, sizeSearch);
                arrSearch = (int*) realloc(arrSearch, (0) * sizeof (int));
                sizeSearch = 0;
                menu();
                break;
            case 3:
                //Print out the array
                printOut(arr, size);
                menu();
                break;
            case 4:
                //Print out values in a range of inputted min and max values
                numbersInTheRange(arr, size);
                menu();
                break;
            case 5:
                //Sort the array in descending order
                sortAscending(arr, size);
                menu();
                break;

            default:
                return 0;
        }
    } while (1);

    return (EXIT_SUCCESS);
}

