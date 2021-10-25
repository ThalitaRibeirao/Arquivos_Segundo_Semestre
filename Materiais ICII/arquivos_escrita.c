// Escrita em arquivos
# include <stdio.h>
# include <stdlib.h>
#define tamStr 200		// constante que define o tamanho max dos strings	

main () {
	float nota;
	char nome[tamStr];
	FILE *arq;
	
	arq = fopen("alunos.txt", "wt");
	if(arq == NULL){
		printf("Falha ao abrir o arquivo \n");
		exit(1);
	}
	
	// lendo do teclado       
	printf("Digite o nome da(o) aluna(o): ");
    fgets(nome, tamStr, stdin);  // equivale ao gets(nome)
    printf("Digite a nota da(o) aluna(o): ");
    scanf("%f%*c",&nota);
    
    // escreve no arquivo
	fprintf(arq, "%s", nome);
	fprintf(arq, "%1.2f", nota);

	fclose(arq);
}

/*main () {
	float nota;
	char nome[tamStr];
	FILE *arq;
	
	arq = fopen("alunos.txt", "wt");
	if(arq == NULL){
		printf("Falha ao abrir o arquivo \n");
		exit(1);
	}
	
	// lendo do teclado       
	printf("Digite o nome da(o) aluna(o): ");
    fgets(nome, tamStr, stdin);  // equivale ao gets(nome)
    printf("Digite a nota da(o) aluna(o): ");
    scanf("%f%*c",&nota);
    
    // escreve no arquivo
	fprintf(arq, "Informacoes da(o) Aluna(o)\n");
	fprintf(arq, "Nome: %s", nome);
	fprintf(arq, "Nota: %1.2f", nota);

	fclose(arq);
}*/


