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
    node* y = x->filhos[i];

//Copia metade superior do nó cheio para um novo nó
    z.folha = y->folha;
    z.n = T.t-1;

    for(int j = 0; j < T.t-1; j++)
    {
        z.ch[j] = y->ch[j+T.t];
    }

    if(!y->folha)
    {
        for(int j = 0; j < T.t; j++)
        {
            z.filhos[j] = y->filhos[i+T.t];
        }
    }

    y->n = T.t-1;

//Coloca z como filho de x
    for(int j = x->n+1; j > i+1; j--)
    {
        x->filhos[j+1] = x->filhos[j];
    }
    x->filhos[i+1] = &z;

//Atualiza chaves
    for(int j = x->n; j > i; j--)
    {
        x->ch[j+1] = x->ch[i];
    }
    x->ch[i] = y->ch[T.t];
    x->n++;
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
