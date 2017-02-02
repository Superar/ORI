#include "arvoreB.h"

/** Inicialização*/
void aloca_node(node** x, int grau)
{
    *x = (node*)malloc(sizeof(node));
    (*x)->folha = true;
    (*x)->n = 0;
    (*x)->ch = (int*)calloc(2 * grau - 1, sizeof(int));
    for(int i = 0; i < 2*grau-1; i++)
        (*x)->ch[i] = INT_MAX;
    (*x)->filhos = (node**)calloc(2 * grau, sizeof(node));
}

void cria_arvore(arvoreB* T, int grau)
{
    aloca_node(&T->raiz, grau);
    T->t = grau;
}

/** Busca*/
int busca(node* T, node** x, int k)
{
    int i = 0;
    while(i < T->n && k > T->ch[i])
        i++;
    if(i < T->n && k == T->ch[i])
    {
        *x = T;
        return i;
    }
    else
    {
        if(T->folha)
        {
            *x = NULL;
            return -1;
        }
        else
            return busca(T->filhos[i], x, k);
    }
}

/** Inserção*/
void divide_filho(arvoreB T, node* x, int i)
{
    node *z;
    aloca_node(&z, T.t);
    node* y = x->filhos[i];

    printf("Divide no %p\n", y);
    imprime_no(*x);

    //Copia metade superior do nó cheio para um novo nó
    z->folha = y->folha;
    z->n = T.t-1;

    for(int j = 0; j < T.t-1; j++)
    {
        z->ch[j] = y->ch[j+T.t];
    }

    if(!y->folha)
    {
        for(int j = 0; j < T.t; j++)
        {
            z->filhos[j] = y->filhos[j+T.t];
        }
    }

    y->n = T.t-1;

    //Coloca z como filho de x
    for(int j = x->n+1; j > i; j--)
    {
        x->filhos[j+1] = x->filhos[j];
    }
    x->filhos[i+1] = z;

    //Atualiza chaves
    for(int j = x->n; j >= i; j--)
    {
        x->ch[j+1] = x->ch[j];
    }
    x->ch[i] = y->ch[T.t-1];
    x->n++;
}

void insere_nao_cheio(arvoreB T, node* x, int k)
{
    int i = x->n;
    int t = T.t;

    printf("No inserido: %p\n", x);
    //Nó é folha
    if(x->folha)
    {
        //"Abre espaço" para inserir o novo valor
        while(i >= 0 && k < x->ch[i])
        {
            x->ch[i+1] = x->ch[i];
            i--;
        }

        x->ch[i+1] = k;
        x->n++;

        printf("Indice: %d\n", i+1);
    }
    //Nó não é folha
    else
    {
        //Procura filho para inserir
        while(i >= 0 && k < x->ch[i])
            i--;
        i++;

        //Verifica se o filho em que vai inserir está cheio
        if(x->filhos[i]->n == 2*t - 1)
        {
            divide_filho(T, x, i);

            //Verifica se a chave a ser inserida é maior que a chave que "subiu"
            if(k > x->ch[i])
                i++;
        }
        insere_nao_cheio(T, x->filhos[i], k);
    }
}

void insere(arvoreB* T, int k)
{
    node* r = T->raiz;

    //Raíz cheia. Cresce a árvore
    if(r->n == 2 * T->t - 1)
    {
        node* s;
        aloca_node(&s, T->t);
        T->raiz = s;
        s->folha = false;
        s->n = 0;
        s->filhos[0] = r;
        divide_filho(*T, s, 0);
        insere_nao_cheio(*T, s, k);

    }
    else
    {
        insere_nao_cheio(*T, T->raiz, k);
    }
}

/** Print*/
void imprime_no(node x)
{
    for(int i = 0; i < x.n; i++)
    {
        printf("%d ", x.ch[i]);
    }
    printf("\n");
}

void imprime_filhos(node x)
{
    for(int i = 0; i < x.n+1; i++)
    {
        printf("Filhos[%d] = %p\n", i, x.filhos[i]);
    }
    printf("\n");
}
