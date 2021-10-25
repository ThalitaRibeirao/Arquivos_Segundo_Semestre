// Escrita em arquivos
# include <stdio.h>
# include <stdlib.h>  // porque usei o exit
			

main () {
	FILE *arq;   // cria ponteiro para arquivo (arq)
	
	arq = fopen("alunos.txt", "wt");   // abro arquivo alunos.txt no modo escrita formato texto
									  // e associo ponteiro arq 
    // verifica se ponteiro eh nulo, ou seja, nao conseguiu criar o arquivo
	if(arq == NULL){
		printf("Falha ao abrir o arquivo \n");
		exit(1);
	}
	       

	fclose(arq);  // fecha arquivo
}


