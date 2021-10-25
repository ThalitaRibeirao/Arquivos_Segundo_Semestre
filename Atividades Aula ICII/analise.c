// Thalita Alves da Silva    N USP: 12567349
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int prefixMedia1(int *X, int *A, int n);
int prefixMedia2(int *X, int *A, int n);

int main () {
    // Inteiro n e vetor alocado dinamicamente
    int n, *X, *A;
    clock_t t0, t1;
    double tempo_total;
    for (int i=1; i < 2002; i+=100) {
        n = i;
        // Alocando um bloco de memória para o vetor
        X = (int *) malloc (n * sizeof(int));
        A = (int *) malloc (n * sizeof(int));

        // Formando um vetor com elementos 1
        for (int j = 0; j < n; j ++) {
            X[j] = 1;
        }
        t0 = clock();

        prefixMedia1 (X, A, n);
        // prefixMedia2 (X, A, n);

        t1 = clock();
        tempo_total = (difftime (t1,t0))/CLOCKS_PER_SEC;
        printf ("\nQuando n = %d, t = %lf s", i, tempo_total);
        
        free(X);
        free(A);
   
    }  

    return 0;

}

int prefixMedia1(int *X, int *A, int n) {
    float a;
    for (int i = 0; i < n; i++) {
        a = 0; 
        for (int j = 0; j <= i; j++) {
            a = a + X[j];
        }
        A[i] = a/(i+1);
    }
    return A;
}

int prefixMedia2(int *X, int *A, int n) {
    float s = 0;
    for (int i =0; i <n; i++) {
        s = s+X[i];
        A[i] = s/(i+1);
    }
    return A;
}
