#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

typedef struct node
{
	int n; // N�mero de chaves
	int* ch; // Chaves
	struct node** filhos;
	bool folha;
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

/**Busca**/
int busca(node*, node*, int);

/** Inser��o*/
void divide_filho(arvoreB, node*, int);
void insere_nao_cheio(node*, int);
void insere(arvoreB*, int);

#endif // ARVOREB_H_INCLUDED
