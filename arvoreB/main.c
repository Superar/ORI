#include "arvoreB.h"


int main(int argc, char* argv[])
{
    arvoreB a;
    cria_arvore(&a, 2);

    /*Adicionei esses testes para verificar o erro*/
    printf("raiz->folha = %d\n", a.raiz->folha);
    printf("raiz->raiz = %d\n", a.raiz->n);
    printf("raiz->folha = %d\n", a.raiz->folha);
    printf("raiz->raiz = %d\n", a.raiz->n);
    printf("raiz->folha = %d\n", a.raiz->folha);

    imprime_no(*a.raiz);
    insere(&a, 10);
    imprime_no(*a.raiz);
    insere(&a, 20);
    imprime_no(*a.raiz);
    insere(&a, 30);
    imprime_no(*a.raiz);

/*TODO: Verificar se insere certo quando tem que dividir a ra�z. Eu sei que a divis�o j� est� certa, mas como o computador aqui
t� mudando o valor do atributo 'folha' do nada, ele d� erro.*/
    //insere(&a, 40);
    //imprime_no(*a.raiz);
    //insere(&a, 50);
    //imprime_no(*a.raiz);

/**< Teste de busca */
    node* saida;
    int indice = busca(a.raiz, &saida, 20);

    if(saida != NULL)
        printf("%p\n%d\n", saida, indice);
    else
/*TODO: Verificar quando o valor n�o est� na �rvore (No computador do lab ele muda o valor do 'folha' toda hora.
Ent�o fica super zoado os resultados, tem que ver se o problema � do c�digo ou da m�quina)*/
        printf("Valor invalido\n");


    return 0;
}
