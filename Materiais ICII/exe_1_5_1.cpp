#include "stdio.h"
# include <stdlib.h>
# include <string.h> //strcpy e outras

# define MAXCHAR 150
# define MAXLIVRO 5


typedef struct {
	char nome[MAXCHAR];
	char autor[MAXCHAR];
	char editora[MAXCHAR];
	int ano;
} livro;

// variaveis globais
livro l[MAXLIVRO];

void cadastrar_livro(int indice) {

	printf("\nNome do livro: ");
	fgets(l[indice].nome, MAXCHAR, stdin);
	printf("\nAutor: ");
	fgets(l[indice].autor, MAXCHAR, stdin);
	printf("\nEditora: ");
	fgets(l[indice].editora, MAXCHAR, stdin);
	printf("\nAno: ");
	scanf("%d%*c", &l[indice].ano);

}

void imprimir_info_livro(int indice) {

	printf("\n%d \n", indice + 1);
	printf(" Nome do livro: %s", l[indice].nome);
	printf(" Autor: %s", l[indice].autor);
	printf(" Editora: %s", l[indice].editora);
	printf(" Ano: %d\n", l[indice].ano);
}


main() {

	int op, num_livro_cad=0, i, op2;
	// cria ponteiro para arquivo;
	FILE *arq;
	
	printf("Primeira vez que entra no sistema: (1-sim, 2-nao)\n");
	scanf("%d%*c",&op2);
	
	if (op2==2){
		// abrir arquivo para leitura do tipo texto
		arq = fopen("dados_livro.txt", "rt");
		if (arq==NULL){
			printf("erro na leitura do arquivo\n");
			exit(1);
		}
		while (feof(arq)==0){
			fgets(l[num_livro_cad].nome, MAXCHAR, arq);
			fgets(l[num_livro_cad].autor, MAXCHAR, arq);
			fgets(l[num_livro_cad].editora, MAXCHAR, arq);
			fscanf(arq, "%d%*c", &l[num_livro_cad].ano);
			num_livro_cad++;
		}
		fclose(arq);
	}

	do {
		printf("\n---- Escolha uma das opcoes ----");
		printf("\n1 - Cadastrar livro.");
		printf("\n2 - Vizualizar livros cadastrados.");
		printf("\n3 - Sair");
		printf("\nOpcao -> ");
		scanf("%d%*c", &op);

		switch (op) {
			case 1:
				if (num_livro_cad < MAXLIVRO) {
					cadastrar_livro(num_livro_cad);
					printf("\nLivro cadastrado com sucesso!\n");
					num_livro_cad++;
				}
				else {
					printf("\nNumero maximo de livros cadastrado!");
				}
				break;
			case 2:
				printf("\n---- Livros cadastrados ----");
				for (i = 0; i < num_livro_cad; i++) {
					imprimir_info_livro(i);
				}
				break;

		}
	}
	while (op != 3);

	// abrir arquivo para escrita do tipo texto
	arq = fopen("dados_livro.txt", "wt");

	// Salvar dados em arquivo
	for (i=0;i<num_livro_cad;i++){
					fprintf(arq, "%s", l[i].nome);
					fprintf(arq, "%s", l[i].autor);
					fprintf(arq, "%s", l[i].editora);
					if (i==num_livro_cad-1)
						fprintf(arq, "%d", l[i].ano);
					else
						fprintf(arq, "%d\n", l[i].ano);
	}
	// fechar arquivo apos o uso
	fclose(arq);
}
