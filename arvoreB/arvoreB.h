#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int n; // N�mero de filhos
	int* ch; // Chaves
	struct node** filhos;
	int folha; // Bool
}
node;

typedef struct arvoreB
{
	node* raiz; //Ponteiro da ra�z
	int t; //Grau
}
arvoreB;

/** Inicializa��o*/
void aloca_node(node*, int);
void cria_arvore(arvoreB*, int);

/** Inser��o*/
void insere_nao_cheio(node*, int);
void insere(arvoreB*, int);

#endif // ARVOREB_H_INCLUDED
