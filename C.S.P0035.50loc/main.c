/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Fb.com/truongdung0706
 *
 * Created on February 3, 2020, 8:47 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int inputValue() {
    
}

int inputSize() {
    printf("Accept size: ");
    
    int row, column;
    char check1, check2;
    do{
        scanf("%d%c%d%c", &row, &check1, &column, &check2);
//        scanf("%c", &check1);
//        scanf("%d", &column);
//        scanf("%c", &check2);
        fpurge(stdin);
        
        if(row <= 0 || column <= 0) {
            printf("Invalid value!!!\n");
            printf("Please retype the value size: ");
        }else {
            if(check1 != ' ') {
                printf("Invalid value!!!\n");
                printf("Please retype the value: ");
            }else {
                if(check2 != '\n') {
                    printf("Invalid value!!!\n");
                    printf("Please retype the value: ");
                }else {
                    return 0;
                }
            }
            
        }
    }while(1);
    
}

int main(int argc, char** argv) {
    printf("Matrix Add\n");
    int size = inputSize();
    
    int firstMatrix, secondMatrix, sumTwoMatrix;
    
    //firstMatrix = inputFitstMatrix();
    
    //secondMatrix = inputSecondMatrix();
    
    //sumTwoMatrix();
    
    return (EXIT_SUCCESS);
}

