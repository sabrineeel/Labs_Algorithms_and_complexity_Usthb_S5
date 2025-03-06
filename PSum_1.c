#include <stdio.h>
#include <stdlib.h>

int main2() {
    double i, n, s;
    printf("Give the number n: ");
    scanf("%lf", &n);
    s = 0;
    i = 1;
        while (i <= n) {
        s += i;
        i++;
    }

    printf("The sum is %lf\n", s);
    return 0;
}

