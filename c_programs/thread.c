#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int position1, position2;
    int count = 0;
    int num = 2; // Start checking numbers from 2 onwards

    printf("Enter the first position: ");
    scanf("%d", &position1);

    printf("Enter the second position: ");
    scanf("%d", &position2);

    if (position1 <= 0 || position2 <= 0) {
        printf("Positions must be positive integers.\n");
        return 1;
    }

    while (count < position2) {
        if (isPrime(num)) {
            count++;
            if (count == position1 || count == position2) {
                printf("Prime at position %d: %d\n", count, num);
            }
        }
        num++;
    }
}
