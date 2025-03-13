#include <stdio.h>
#include <time.h>

void hanoi(int n, char A, char B, char C) {
   if (n == 1) {
        printf("Deplacer le disque 1 de %c a %c\n", A, C);
        return;
    }

    hanoi(n - 1, A, C, B);

    printf("Deplacer le disque %d de %c a %c\n", n, A, C);

    hanoi(n - 1, B, A, C);
}

int main() {
    int n;
    clock_t t1, t2;
    printf("Entrez le nombre de disques : ");
    scanf("%d", &n);
    t1 = clock();
    printf("Les etapes pour resoudre les Tours de Hanoi avec %d disques sont :\n", n);
    hanoi(n, 'A', 'B', 'C');
    t2 = clock();
    double time_taken = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("s : %.3f secondes\n", time_taken);
    return 0;
}
