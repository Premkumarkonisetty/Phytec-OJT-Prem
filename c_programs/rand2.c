#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    printf("Enter the range of numbers from 0 to: ");
    scanf("%d", &num);
    
    int numbers[num];
    int i, randomNumber, count = 0;

    for (i = 0; i < num; i++) {
        numbers[i] = i + 1;
    }

    while (count < num) {
        randomNumber = rand() % num;
        if (numbers[randomNumber] != 0) {
            printf("%d ", numbers[randomNumber]);
            numbers[randomNumber] = 0;
            count++;
        }
    }

    printf("\n");

    return 0;
}

