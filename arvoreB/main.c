#include "arvoreB.h"


int main(int argc, char* argv[])
{
    arvoreB a;
    cria_arvore(&a, 2);

    insere(&a, 10);

    printf("raiz.n = %d\n", a.raiz->n);

    return 0;
}
