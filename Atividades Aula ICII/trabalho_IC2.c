// Nome: Thalita Alves da Silva    N USP: 12567349
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura dos alunos 

typedef struct registros {
    char nome [100];
    int numero_usp;
    float nota_p1;
    float nota_p2;
    float media;
} aluno; //Para simplificar, estou chamando "struct registros" de "aluno"

void Iniciar_estrutura (aluno *fichas, int n) {

    printf ("\n ----------------------------- \n");

    for (int i = 0; i < n; i ++) {
        printf ("\nDigite o nome do aluno. \n ->");
        gets (fichas[i].nome);

    }

}

void main () {

    int n = 0; // Armazena a quantidade de alunos no sistema
    
    do {
        // Verifica a quantidade de alunos para iniciar o sistema
        printf ("\nQuantos alunos deseja cadastrar?\n->");
        scanf ("%d%*c", &n);
        if (n <= 0) {
            printf ("\nValor invalido! Digite novamente.\n");
        }
    }
    while (n <= 0); 
     
    // Reserva um bloco de memória para os registros
    aluno *fichas = (aluno *) malloc (n * syzeof (aluno));

    // Inicializa a estrutura 
    Iniciar_estrutura (fichas, n);

    for (int i = 0; i < n ; i++) {
        printf ("\n%s", *(fichas[i].nome));
    }
    
}

