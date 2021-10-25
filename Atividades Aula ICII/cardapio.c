// Maria Vitoria Ribeiro Mendes - 30/08/2021
#include <stdio.h>
#include <stdlib.h>

// Boa prática: declare a estrutura fora da main

typedef struct pratoRestaurante{

    float valor;
    char nome[50];
    int numIngredientes;
    char **ingredientes;
} PRATO;

PRATO **inicializaEstrutura(PRATO **cardapio, int n)
{
    return (PRATO**)malloc(n*sizeof(PRATO));
}

char **inicializaArrayStrings(char **ingredientes, int n)
{
    return (char**)malloc(n*sizeof(char));
}

void adicionaIngredientes(char **Listaingredientes,int n)
{
    int i;
    printf("Adicionar ingredientes.\n");
    for(i=0;i<n;i++)
    {
        Listaingredientes[i] = (char*)malloc(50*sizeof(char));
        fgets(Listaingredientes[i],50,stdin); // ler, da entrada padrao, uma string de tamanho no maximo 50
        printf("Ingrediente %s adicionado.\n",Listaingredientes[i]);
    }
}

void imprimirCardapio(PRATO **cardapio, int n, int np)
{
    int i;
    int j,k;
    
    for(i=0;i<n;i++)
    {
        printf("\n#Cardapio %d\n\n",i+1);
        for(j=0;j<np;j++)
        {
            printf("*Nome do prato: %s*Valor: %2.2f\n*Contem %d ingredientes:\n",cardapio[i][j].nome,cardapio[i][j].valor,cardapio[i][j].numIngredientes);
            for(k=0;k<cardapio[i][j].numIngredientes;k++)
                printf("  ->%s\n",cardapio[i][j].ingredientes[k]);

        }
    
    printf("\n_________Fim do cardapio %d___________\n", i+1);
    }
}

void preencheEstrutura(PRATO **cardapios,int n)
{   

    int i,j;
    int np;

    for(i=0;i<n;i++)
    {
        printf("#Cardapio %d\nQuantos pratos cadastrar nesse cardapio?\n",i+1);
        scanf("%d%*c",&np);
        cardapios[i] = (PRATO*)malloc(np*sizeof(PRATO));
        for(j=0;j<np;j++)
        {
        printf("\nNome do prato %d:\n",j+1);
        //fscanf(cardapio[i]->nome,50,stdin); // da pra melhorar isso aqui
        fgets(cardapios[i][j].nome,50,stdin);
        printf("Valor:\n");
        scanf("%f%*c",&cardapios[i][j].valor);
        printf("Quantidade de ingrediantes:\n");
        scanf("%d%*c",&cardapios[i][j].numIngredientes);
        cardapios[i][j].ingredientes = inicializaArrayStrings(cardapios[i][j].ingredientes,cardapios[i][j].numIngredientes);
        adicionaIngredientes(cardapios[i][j].ingredientes,cardapios[i][j].numIngredientes);
        printf("\n_____________________\n");

        }
    }

    imprimirCardapio(cardapios,n,np);
}



int main()
{
    
    printf("Criar cardapios. Quantos?\n");
    int n;
    scanf("%d%*c",&n);
    PRATO **cardapios = inicializaEstrutura(cardapios,n); // malloc devolve um ponteiro para o tipo array de PRATO

    //PRATO **cardapio = (PRATO**)malloc(n*sizeof(PRATO));
    // ponteiro para um bloco de memoria capaz de guardar n pratos
    preencheEstrutura(cardapios,n);
    
    return 0;
}