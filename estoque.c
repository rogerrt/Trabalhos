//Roger Ricardo Tristão

#include<stdio.h>
#include<string.h>

#define MAX 100
#define tam 20
#define lin 10
#define col 10

#define abastecer 1
#define pesquisar 2
#define sair 3

struct produto 
{
    int id;
    char nome[MAX];
    float preco;
}; typedef struct produto prod;

void add_produto(prod vetor[tam], int n)
{
    int i;

    printf("\nInsira os dados do produto:\n");

    for ( i = 0; i < n; i++)
    {
        printf("\nNome: ");
        fgets(vetor[i].nome, MAX-1, stdin);
        printf("\nPreco: ");
        scanf("%f", &vetor[i].preco);
        getchar();
        vetor[i].id = 1;
    }
}

int pesquisa(prod vetor[tam], int matriz[lin][col], int linhas, int colunas)

    char nome[MAX];
    int j;
    int i;
    int id = -1;

    printf("\nInsira o nome do produto: ");
    fgets(nome, MAX-1, stdin);

    for (j=0; j<colunas; j++)
    {
        if (strcmp(vetor[j].nome, nome) == 0)
        {
            printf("\nID: %d\n", vetor[j].id);
            printf
        }
        
    }