#include <stdio.h>

void FiboGoldenRatio(int n) {
    double a = 0, b = 1, fib, ratio;

    for (int i = 1; i <= n; i++) {
        fib = a + b;

        if (i == 1) {
            printf("%d: Un = %.15f, Ratio = Division by zero\n", i, b);
        } else {
            ratio = b / a;
            printf("%d: Un = %.15f, Ratio = %.15f\n", i, b, ratio);
        }
        a = b;
        b = fib;
    }
}

int main() {
    int n;
    printf("Enter the number of terms (n): ");
    scanf("%d", &n);

    FiboGoldenRatio(n);
    return 0;
}
