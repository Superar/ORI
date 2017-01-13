#include <stdio.h>
#include <stdlib.h>

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
	node* raiz;
	int t;
}
arvoreB;

node aloca_node(int grau)
{
	node x;
	x.folha = 1;
	x.n = 0;
	x.ch = (int *)malloc((2*grau-1) * sizeof(int));
	x.filhos = (node **)malloc((2*grau-1) * sizeof(int));
	return x;
}

arvoreB cria_arvore(int grau)
{
	node x = aloca_node(grau);
	arvoreB arvore;
	
	arvore.t = grau;
	arvore.raiz = &x;
	
	return arvore;
}

void divide_filho(arvoreB T, node* x, int i)
{
	node z = aloca_node(T.t);
	node y = x->filhos[i];
	
	z.folha = y.folha;
	z.n = T.t - 1;

	for(j = 0; j < T.t - 2; j++)
	{
		z.ch[j] = y.ch[j + T.t];
	}
	
	if(!y.folha)
	{
		for(j = 0; j < T.t-1; j++)
		{
			z.filhos[j] = y.filhos[j + T.t];
		}
	}
	
	y.n = T.t-1;

	for(j = x->n + 1; j > i + 1; j--)
	{
		x->filhos[j+1] = x->filhos[j];
	}

	x->filhos[i+1] = z;

	for(j = x->n; j > i; j--)
	{
		x->filhos[j+1] = x->filhos[j];
	}
	
	x->filhos[i] = y.filhos[T.t];
	x->n++;
}

void insere(arvore* T, int k)
{
	node *r = T->raiz;
	if(r.n == 2*t-1)
	{
		s = aloca_node(T->t);
		T->raiz = s;
		
		
	}
}


int main(int argc, char* argv[])
{
	arvoreB Btree = cria_arvore(3);
	
	if(Btree.raiz->ch != NULL)
	{
		Btree.raiz->ch[1] = 782;
		printf("%d\n", Btree.raiz->ch[1]);
	}
	
	return 0;
}
