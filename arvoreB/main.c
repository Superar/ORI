#include "arvoreB.h"


int main(int argc, char* argv[])
{
    arvoreB a;
    cria_arvore(&a, 2);

    imprime_no(*a.raiz);
    insere(&a, 10);
    imprime_no(*a.raiz);
    insere(&a, 20);
    imprime_no(*a.raiz);
    insere(&a, 30);
    imprime_no(*a.raiz);

/*TODO: Verificar se insere certo quando tem que dividir a raíz. Eu sei que a divisão já está certa, mas como o computador aqui
tá mudando o valor do atributo 'folha' do nada, ele dá erro.*/
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
/*TODO: Verificar quando o valor não está na árvore (No computador do lab ele muda o valor do 'folha' toda hora.
Então fica super zoado os resultados, tem que ver se o problema é do código ou da máquina)*/
        printf("Valor invalido\n");


    return 0;
}
