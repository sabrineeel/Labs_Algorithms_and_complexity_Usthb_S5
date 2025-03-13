#include <stdio.h>
#include <stdbool.h>
#include <time.h>
// affichage de matrice

void Afficher_tab_D2( int N,int M , int **arr) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d    ", arr[i][j]);
        }
        printf("\n");
    }
}

// creation d'une matrice N * M avec des valeurs random entre low et high

int** tab_D2(int N ,int M ,  int low , int high) {
    int **matrix = (int**)malloc(N * sizeof(int*));

    if (matrix == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < N; i++) {
        matrix[i] = (int*)malloc(M * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed\n");
            return NULL;
        }

        for (int j = 0; j < M; j++) {
            matrix[i][j] = (rand() % (high - low + 1)) + low;
        }
    }

    return matrix;
}
// liberer espace apres execution
void freeMatrix(int** matrix, int rows) {
    int i;

    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// cette fonction sert a extraire une soumatrice d'une matrice en donnant les indices debut et fin
// de la ligne et la collonne
// le resultat sera utilisé pour la recherche au pire cas

int**  affectation_submat(int row_s , int row_e , int col_s , int col_e ,int **bigarr){

    int A = row_e - row_s;
    int B = col_e - col_s;

    int **matrix = (int**)malloc(A * sizeof(int*));

    if (matrix == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < A; i++) {
        matrix[i] = (int*)malloc(B * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed\n");
            return NULL;
        }

        for (int j = 0; j < B; j++) {
            matrix[i][j]=bigarr[i+row_s][j+col_s];
        }
    }
    return matrix ;
}
int SousMat1( int N, int M, int N_prime, int M_prime , int **A, int **B) {
int i, j, x, y;

if( N_prime > N || M_prime  > M){
printf("La matrice B est plus grande que A \n"); return 0;
}
for (i = 0; i <= N - N_prime; i++) {
   for (j = 0; j <= M - M_prime; j++) {
      int trouve = 1; // si on trouve une valeure different on met trouve a 0 et on sort de boucle
    for (x = 0; x < N_prime; x++) {
       for (y = 0; y < M_prime; y++) {
        if (A[i + x][j + y] != B[x][y]) {
        trouve = 0; // Submatrix doesn't match at this position
     break;
    }
    }
   if (!trouve) {
break;
}}
if (trouve) {
printf("Soumatrice trouvee a ligne =	%d , colonne =	%d\n", i,j);
return 1;
}}}
printf("Soumatrice n'existe pas \n"); return 0;
}


int SousMat2(int N, int M, int N_prime, int M_prime, int **A, int **B) {
if (N_prime > N || M_prime > M) {
printf("La matrice B est plus grande que A \n"); return 0;
}
int i, j, x, y;
for (i = 0; i <= N -N_prime; i++) {
for (j = 0; j <= M - M_prime; j++) {
int trouve = 1;
for (x = 0; x < N_prime; x++) {
// tester seulement la premiere case de chaque ligne
// si vrai , on parcours la matrice B , sinon on passe
if (A[i + x][j] != B[x][0]) { trouve = 0;
break;
}
//	parcourir la matrice B si la premiere case est trouvé
for (y = 1; y < B; y++) {
if (A[i + x][j + y] != B[x][y]) { trouve = 0;
break;
}}
if (!trouve) {
break;
}}
if (trouve) {
printf("Soumatrice trouvee a ligne =	%d , colonne =	%d\n", i, j);
return 1;
}}}
printf("Soumatrice n'existe pas \n"); return 0;
}


int main() {

    clock_t debut , fin ;

    srand ( time(NULL) ); // fonction pour mettre a jours les valeurs de la fonction random

    printf(" \n\n choix du pire cas : \n\n");

    int **B=tab_D2(100,100,6,10);
    int **A= tab_D2(2500 , 2500, 0 , 5);
    int **C=affectation_submat(2000-100 , 2000 , 2000-100 ,2000 , A);

    debut = clock();
    SousMat1(2500,2500,100,100,A,B);
    fin = clock();
    printf("temps quand soumat existe pas : %f \n" , (double)(fin-debut)/CLOCKS_PER_SEC);
    debut = clock();
    SousMat1(2500,2500,100,100,A,C);
    fin = clock();
    printf("temps quand soumat est la derniere  : %f \n" , (double)(fin-debut)/CLOCKS_PER_SEC);

    printf("\n\nEtude experimental  : \n\n");
    printf("taille matrice :  temps execution \n\n");
    int taille_matrice[7]={500,1000,1250,1500,1750,2000,2500};
    int i,N;
    for ( i = 0; i < 7; i++)
    {
        N=taille_matrice[i];
        int **A= tab_D2(N , N, 0 , 5);
        int **C= affectation_submat(N-100,N,N-100,N,A);
        debut = clock();
        SousMat1(N,N,100,100,A,C);
        fin = clock();
        printf(" pour la sousMat1 %d  :  %f " , N , (double)(fin-debut)/CLOCKS_PER_SEC);
        debut = clock();
        SousMat2(N,N,100,100,A,C);
        fin = clock();
        printf(" pour la sousMat2 %d  :  %f " , N , (double)(fin-debut)/CLOCKS_PER_SEC);
        freeMatrix(A , N);
        freeMatrix(C , 100);

     }
    return 0;
}


