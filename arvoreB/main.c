#include "arvoreB.h"


int main(int argc, char* argv[])
{
    arvoreB a;
    cria_arvore(&a, 2);

    insere(&a, 10);
    insere(&a, 20);
    insere(&a, 30);
    insere(&a, 40);
    insere(&a, 50);

    return 0;
}
