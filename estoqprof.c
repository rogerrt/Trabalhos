#include <stdio.h>
#include <string.h>

#define MAX 100
#define TAM 10
#define LIN 10
#define COL 10

#define OP_ABASTECER 1
#define OP_PESQUISAR 2
#define OP_SAIR 3

struct Produto {
	int id;
	char nome[MAX];
	float preco;
};
typedef struct Produto TProduto;

void le_produto(TProduto vetor[TAM], int n) {

	int i;
	
	printf("\nInforme os produtos:\n");

	for (i=0; i<n; i++) {

		printf("\nNome: ");
		fgets(vetor[i].nome, MAX-1, stdin);
		printf("Preco: ");
		scanf("%f", &vetor[i].preco);
		getchar();
		vetor[i].id = i;
	}

}

int pesquisa_produto(TProduto vetor[TAM], int matriz[LIN][COL], int linhas, int colunas) {

	char nome[MAX];
	int j; /* indexador de produtos */
	int i; /* indexador de lojas */
	int id = -1;

	printf("\nEntre com o nome do produto: ");
	fgets(nome, MAX-1, stdin);

	for (j=0; j<colunas; j++) {

		if (strcmp(vetor[j].nome, nome) == 0) {

			printf("\nID: %d\n", vetor[j].id);
			printf("Nome: %s", vetor[j].nome);
			printf("Preco: %.2f\n\n", vetor[j].preco);

			id = vetor[j].id;	
			for (i=0; i<linhas; i++) {
				printf("Loja %d: %d unidades\n", i, matriz[i][id]);
 			}
		}
	}

	if (id >= 0) {
		return 1;
	}

	return 0;
}


void le_estoque(int matriz[LIN][COL], int linhas, int colunas) {
	
	int i, j;
 
 	printf("\nInforme a matriz de estoque:\n");

 	for (i=0; i<linhas; i++) {
 	 	for (j=0; j<colunas; j++) {
 		 	scanf("%d", &matriz[i][j]);
 	 	}
 	}
}

void imprime_estoque(int matriz[LIN][COL], int linhas, int colunas) {
 	
	int i, j;

	printf("\nEstoque atualizado:\n");

 	for (i=0; i<linhas; i++) {
 	 	for (j=0; j<colunas; j++) {
 		 	printf("%d ", matriz[i][j]);
 	 	}
 	 	printf("\n");
 	}
}

void le_abastecimento(int vetor[TAM], int n) {
	
	int i;
 
 	printf("\nInforme o vetor de abastecimento:\n");

 	for (i=0; i<n; i++) {
		scanf("%d", &vetor[i]);
 	}
}

void faz_abastecimento(int matriz[LIN][COL], int linhas, int colunas, int vetor[TAM]) {

	int i, j, pos_menor;
 
 	for (i=0; i<linhas; i++) {
	
		pos_menor = 0;
		for (j=0; j<colunas; j++) {

			if (matriz[i][j] < matriz[i][pos_menor]) {
				pos_menor = j;
			}
		}

		matriz[i][pos_menor] += vetor[pos_menor];
 	}
}

void exibe_menu() {

	printf("\nGerenciamento de estoque\n");
	printf("%d - Abastecer estoque\n", OP_ABASTECER);
	printf("%d - Pesquisar produto\n", OP_PESQUISAR);
	printf("%d - Sair\n", OP_SAIR);
}

int main() {

	TProduto vetor_produto[TAM];
	int matriz_estoque[LIN][COL];
	int vetor_abastecimento[TAM];
	int lojas, produtos;
	int op, id;

	printf("Entre com o numero de lojas e produtos:\n");
	do {
		scanf("%d %d", &lojas, &produtos);
	} while (lojas <= 0 || lojas > 10 || produtos <= 0 || produtos > 10);
	getchar();

	le_produto(vetor_produto, produtos);
	le_estoque(matriz_estoque, lojas, produtos);
	le_abastecimento(vetor_abastecimento, produtos);

	do {
		exibe_menu();
		scanf("%d", &op);
		getchar();

		switch (op) {

			case OP_ABASTECER:
				faz_abastecimento(matriz_estoque, lojas, produtos, vetor_abastecimento);
				imprime_estoque(matriz_estoque, lojas, produtos);
				break;
			
			case OP_PESQUISAR:
				if (pesquisa_produto(vetor_produto, matriz_estoque, lojas, produtos) == 1){
					printf("Operacao realizada com sucesso\n");
				}
				else {
					printf("Produto nao encontrado\n");
				}
				break;

			case OP_SAIR:
				break;

			default:
				printf("Opcao invalida\n");
				break;
		}

	} while (op != OP_SAIR);
					
	return 0;
}







