// Escrita em arquivos
# include <stdio.h>
# include <stdlib.h>
#define tamStr 200			

main () {
	float p;
	char n[tamStr];
	FILE *arq_alunos;
	
	arq_alunos = fopen("alunos.txt", "rt");
	if(arq_alunos == NULL){
		printf("Falha ao abrir o arquivo \n");
		exit(1);
	}
	// lendo arquivo
	fgets(n, tamStr, arq_alunos);       
	fscanf(arq_alunos, "%f", &p);
	
	// escrevendo na tela
	printf("Nome da(o) aluna(o): %s",n);
	printf("Nota: %1.2f \n",p);

	fclose(arq_alunos);
}
