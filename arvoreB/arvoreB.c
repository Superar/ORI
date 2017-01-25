#include "arvoreB.h"

/** Inicialização*/
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

/**Busca**/
int busca(node* T, node* x, int k)
{
    int i = 1;
    while(i <= T->n && k > T->ch[i])
        i++;
    if(i <= T->n && k == T->ch[i])
    {
        x = T;
        return i;
    }
    else if (T->folha)
    {
        x = NULL;
        return -1;
    }
    else
        return busca(T->filhos[i], x, k);
}

/** Inserção*/

void divide_filho(arvoreB T, node* x, int i)
{
    node z;
    aloca_node(&z, T.t);
}

void insere_nao_cheio(node* r, int k)
{
	r->ch[r->n] = k;
	r->n++;
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
		insere_nao_cheio(T->raiz, k);
	}
}
