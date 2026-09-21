#include <stdio.h>

// Function definition
int is_prime(int n) {
    if (n <= 1) return 0; // 0 and 1 are not prime
    if (n == 2) return 1; // 2 is the only even prime

    // Check divisibility from 2 up to the square root of n
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0; // Found a divisor, not prime
        }
    }
    return 1; // No divisors found, it is prime
}

int main(void) {
    int n;
    
    printf("Enter n: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Error: n must be at least 2.\n");
    } else {
        printf("Prime numbers up to %d are: ", n);
        for (int i = 2; i <= n; i++) {
            if (is_prime(i)) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    
    return 0;
}
