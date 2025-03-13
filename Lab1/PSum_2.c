#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main3() {
    double i, n, s;
    clock_t T1, T2;
     T1 = clock();
    double D;
    printf("Give the number n: ");
    scanf("%lf", &n);
    s = 0;
    i = 1;
    while (i <= n) {
        s += i;
        i++;
    }
    T2 = clock();
    D = ((double)(T2 - T1)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", D);
    printf("The sum is%.0lf\n", s);
    return 0;
}
