#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int num) 
{
    bool primo = true
    if (num <= 1) primo = false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) primo = false;
    }
    return primo;
}

void primos(int m, int *p1, int *p2) {
    
    // Encontrar o maior primo menor que m
    int = m - 1;
    for (int i = m - 1; i > 1; i--) {
        if (is_prime(i)) {
            *p1 = i;
            break;
        }
    }

    // Encontrar o menor primo maior que m
    for (int i = m + 1;; i++) {
        if (is_prime(i)) {
            *p2 = i;
            break;
        }
    }
}

int main() {
    int m = 10;
    int p1, p2;
    primos(m, &p1, &p2);
    printf("Maior primo menor que %d: %d\n", m, p1);
    printf("Menor primo maior que %d: %d\n", m, p2);
    return 0;
}