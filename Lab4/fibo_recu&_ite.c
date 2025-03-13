#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long Fibo_Rec(int n)
{
    if(n == 1 || n == 0)
        return n;
    return Fibo_Rec(n-1) + Fibo_Rec(n-2);
}

int Fibo_iter(int n)
{   if (n==0){
        return 0;
    }
    if (n==1){
        return 1;
    }
    int x=0;
    int y=1;
    int z=0;
    for (int i = 2; i <= n; i++) {
        z=x+y;
        x=y;
        y=z;
    }
    return z;

}

int main() {
    int n;
    printf("Entrez un nombre n pour calculer le nieme terme de Fibonacci : ");
    scanf("%d", &n);

    clock_t start = clock();
    long result_rec = Fibo_Rec(n);
    clock_t end = clock();
    double time_rec = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    int result_iter = Fibo_iter(n);
    end = clock();
    double time_iter = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Fibo_Rec(%d) = %ld\n", n, result_rec);
    printf("Fibo_iter(%d) = %d\n", n, result_iter);

    printf("Temps d'execution de Fibo_Rec: %.6f secondes\n", time_rec);
    printf("Temps d'execution de Fibo_iter: %.6f secondes\n", time_iter);

    return 0;
}
