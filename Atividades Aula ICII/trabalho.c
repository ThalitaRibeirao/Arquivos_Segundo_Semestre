// Nome: Thalita Alves da Silva    N USP: 12567349
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura dos alunos 
typedef struct registros {
    char nome [75];
    int numero_usp;
    float nota_p1;
    float nota_p2;
    float media;
} aluno; //Para simplificar, estou chamando "struct registros" de "aluno"


void Iniciar_estrutura (aluno *fichas, int n);
void Registrar_aluno (aluno *fichas, int n);
void Calcular_media (aluno *fichas, int n);
void Buscar_aluno (aluno *fichas, int n);


int main () {
    int n = 0; // Armazena a quantidade de alunos no registro
    int opcao = 0; // Armazena a opcao do usuario 
    do {
        printf ("\nQuantos alunos quer registrar?\n->");
        scanf ("%d%*c", &n);
        if (n <= 0) {
            printf ("\nValor invalido! Digite novamente.\n");
        }
    } 
    while (n <= 0);



    // Reserva um bloco de memoria para armazenar as fichas
    aluno *fichas = (aluno*) malloc (n* sizeof (aluno));

    // Verifica se o tamanho de fichas pode ser armazenado 
    if (fichas == NULL) {
        printf ("\nValor de armazenamento muito grande, tente novamente. \n");
        free (fichas);
        return main ();
    }


    // Armazena os dados dos primeiros alunos
    Iniciar_estrutura (fichas, n);


    do {

        // Menu do programa
        printf ("\n --------------- MENU --------------- \n");
        printf ("\n Digite 1 para registrar um novo aluno.");
        printf ("\n Digite 2 para buscar um aluno no sistema.");
        printf ("\n Digite 3 para sair do programa. \n->");
        scanf ("%d%*c", &opcao);

        // Executa a escolha do usuario 
        switch (opcao)
        {
        case 1:
            // Verifica se é possível armazenar mais um usuario
            (void*)realloc(fichas, n * (sizeof(aluno)));

            if (fichas == NULL){
                printf ("\nQuantidade maxima de alunos armazenados!");
            }

            else {
                n++; 
                Registrar_aluno (fichas, n);                
            }

            break;
        case 2:
            // Procura um aluno no sistema; 
            Buscar_aluno (fichas, n);
            break;
        };
    }
    while (opcao != 3);
    free(fichas);
    return 0;
}


void Iniciar_estrutura (aluno *fichas, int n) {
    
    for (int i = 0; i < n; i++) {
        printf ("\n -------- Dados do aluno %d ---------\n ", i+1);
        printf ("\nNome: ");
        fgets (fichas[i].nome, 75, stdin);
        printf ("\nNumero USP: ");
        scanf ("%d%*c", &fichas[i].numero_usp);
        printf ("\nNota da primeira prova: ");
        scanf ("%f%*c", &fichas[i].nota_p1);
        printf ("\nNota da segunda prova: ");
        scanf ("%f%*c", &fichas[i].nota_p2);
        Calcular_media (fichas, i);

    }
}

void Registrar_aluno (aluno *fichas, int n) {
    printf ("\n -------- Dados do aluno %d ---------\n ", n);
    printf ("\nNome: ");
    fgets (fichas[n-1].nome, 75, stdin);
    printf ("\nNumero USP: ");
    scanf ("%d%*c", &fichas[n-1].numero_usp);
    printf ("\nNota da primeira prova: ");
    scanf ("%f%*c", &fichas[n-1].nota_p1);
    printf ("\nNota da segunda prova: ");
    scanf ("%f%*c", &fichas[n-1].nota_p2);
    Calcular_media (fichas, n-1);
}

void Calcular_media (aluno *fichas, int n) {
    fichas[n].media = (fichas[n].nota_p1 + fichas[n].nota_p2)/2;
}

void Buscar_aluno (aluno *fichas, int n) {
    int num_usp, j = 0;
    
    printf ("\nDigite o numero USP do aluno:");
    scanf ("%d%*c", &num_usp);
    for (int i = 0; i < n; i++) {
        if (fichas[i].numero_usp == num_usp) {
            printf ("\nAluno encontrado!");
            printf ("\nNome: %s", fichas[i].nome);
            printf ("\nNumero USP: %d", fichas[i].numero_usp);
            printf ("\nNota da primeira prova: %.2f", fichas[i].nota_p1);
            printf ("\nNota da segunda prova: %.2f", fichas[i].nota_p2);
            printf ("\nMedia das provas: %.2f", fichas[i].media);
            j = 1;
            break;
        }

    }
    if (j == 0) {
        printf ("\n Nao foi encontrado o aluno no sistema.");
    }
}