#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, s;

    printf("Give the number n: ");
    scanf("%d", &n);
    s = 0;
    i = 1;
    while (i <= n) {
        s += i;
        i++;
    }
    printf("The sum is %d\n", s);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    double i, n, s;
    clock_t T1, T2;
    double D;
    printf("Give the number n: ");
    scanf("%lf", &n);
    T1 = clock();
    s = 0;
    i = 1;
    while (i <= n) {
        s += i;
        i++;
    }
    T2 = clock();
    D = ((double)(T2 - T1)) / CLOCKS_PER_SEC;
    printf("Time taken: %.10f seconds\n", D);
    printf("The sum is %f\n", s);
    return 0;
}

