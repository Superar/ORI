#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

typedef struct node
{
	int n; // Número de filhos
	int* ch; // Chaves
	struct node** filhos;
	int folha; // Bool
}
node;

typedef struct arvoreB
{
	node* raiz; //Ponteiro da raíz
	int t; //Grau
}
arvoreB;

void aloca_node(node* x, int grau)
{	
	x->folha = true;
	x->n = 0;
	x->ch = (int*)calloc(2 * grau - 1, sizeof(int));
	x->filhos = (node**)calloc(2 * grau, sizeof(node));
}

void cria_arvore(arvoreB* a, int grau)
{
	node x;

	aloca_node(&x, grau);
	a->t = grau;
	a->raiz = &x;
}

void insere_nao_cheio(node** r, int k)
{
	printf("raiz.n = %d\n", (*r)->n);
	//t->ch[t->n] = k;
	//t->n++;
}

void insere(arvoreB* T, int k)
{
	node* r = T->raiz;
	
	if(r->n == 2 * T->t - 1)
	{
		printf("Raiz cheia\n");
	}
	else
	{
		printf("raiz.n = %d\n", T->raiz->n);
		insere_nao_cheio(&T->raiz, k);
		printf("raiz.n = %d\n", T->raiz->n);
	}
}


int main(int argc, char* argv[])
{
	arvoreB a;
	cria_arvore(&a, 2);
	
	insere(&a, 10);
	
	printf("raiz.n = %d\n", a.raiz->n);
	
	return 0;
}
