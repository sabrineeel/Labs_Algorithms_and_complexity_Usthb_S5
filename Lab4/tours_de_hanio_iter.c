#include <stdio.h>
#include <math.h>
#include <time.h>
void moveDisk(int d, int ar) {
    printf("Deplacer le disque de %d a %d\n", d, ar);
}
void hanoiIterative(int n) {
    int total = pow(2, n) - 1;
    int tours[3];
 for (int i = 0; i < 3; i++) {
        tours[i] = i + 1;
    }
 if (n % 2 == 0) {
        int temp = tours[1];
        tours[1] = tours[2];
        tours[2] = temp;
    }
  for (int i = 1; i <= total; i++) {
        int d = (i % 3);
        int ar = ((i + 1) % 3);
        if (i % 3 == 0) {
            d = (d + 1) % 3;
        }
        moveDisk(tours[d], tours[ar]);
    }}

int main() {
    int n;
    clock_t t1, t2;
    printf("Entrez le nombre de disques : ");
    scanf("%d", &n);
    t1 = clock();
    printf("Les etapes pour resoudre les Tours de Hanoi avec %d disques sont :\n", n);
    hanoiIterative(n);
    t2 = clock();
    double time_taken = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("Temps : %.3f secondes\n", time_taken);
    return 0;
}
