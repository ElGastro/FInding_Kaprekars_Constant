#include "stdio.h"
#include "math.h"
#include "stdlib.h"

/*This is a program that calculate how many operations 
 *were needed to find Kaprekar's Constant from a number*/

/*This will be used to quicksort the array from lowest to highest*/
int cmpAsc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/*The same but from highest to lowest*/
int cmpDsc(const void* a, const void*b) {
    return (*(int*)b - *(int*)a);
}

/*Returns the number sorted from highest to lowest*/
void HtL(int num[4]) {
    qsort(num, 4, sizeof(int), cmpDsc);
}

/*Returns the number sorted from lowest to highest*/
void LtH(int num[4]) {
    qsort(num, 4, sizeof(int), cmpAsc);
}

/*Checks if the number given is a four digit number*/
int check (int n) {
    if (n < 1000 || n > 9999)
        return 0;
    return 1;
}

/*Checks if the number has at least two distinct digits*/
int checkValid(int num[4]) {
    if (num[0] == num[1] && num[1] == num[2] && num[2] == num[3])
        return 0;
    return 1;
}

/*Turns the array into a four digit number*/
int ArrToNum(int num[4]) {
    return num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];
}

/*Isolates each digit of the number*/
int giveDigit(int n, int pos) {
    return (n / (int)pow(10, 4 - pos - 1)) % 10;
}

int main(void) {
    int num[4] = {};
    printf("Provide a four digit number\n");
    int n;
    scanf("%d", &n);
    int c = check(n);
    if (!c)
        return 1;
    /*The number was already Kaprekar's Constant*/
    if (n == 6174) {
        printf("No operations needed\nNUmber was already Kaprekar's Constant");
        return 0;
    }
    for (int i = 0; i < 4; i++) {
        num[i] = giveDigit(n, i);
        printf("%d\t", num[i]);
    }
    c = checkValid(num);
    if (!c) {
        printf("Invalid number\n");
        return 1;
    } else
        printf("Valid number");
    printf("\n");
    int count = 0;
    while (n != 6174) {
        count++;
        HtL(num);
        int a = ArrToNum(num);
        LtH(num);
        int b = ArrToNum(num);
        n = a - b;
        printf("%d - %d = %d\n", a, b, n);
        for (int i = 0; i < 4; i++)
            num[i] = giveDigit(n, i);
    }
    printf("Total number of subtractions: %d\n", count);
}