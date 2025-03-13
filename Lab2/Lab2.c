#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

bool Algorithm1(int n) {
    if (n <= 1) { return false; }
    int cmp = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) { cmp++; }
    }
    return (cmp == 2);
}

bool Algorithm2(int n) {
    if (n <= 1) { return false; }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool Algorithm3(int n) {
    if (n <= 1) { return false; }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool Algorithm4(int n) {
    if (n % 2 == 0 && n != 2) return false;

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

double calculateExecutionTime(bool (*algorithm)(int), int n) {
    clock_t start_time = clock();
    algorithm(n);
    clock_t end_time = clock();

    return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}

int main() {

    int n;
    char choice;

    do {
        printf("Entrez un nombre pour tester s'il est premier : ");
        scanf("%d", &n);

        double execution_time = calculateExecutionTime(Algorithm3, n);

        bool is_prime = Algorithm4(n);

        printf("N = %d\n", n);
        printf("Est-ce un nombre premier ? %s\n", is_prime ? "Oui" : "Non");
        printf("Temps d'execution : %.20f s\n", execution_time);

        printf("Voulez-vous tester un autre nombre ? (y:oui, q:quitter) : ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Merci.\n");

    return 0;
}
