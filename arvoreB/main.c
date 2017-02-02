#include "arvoreB.h"


int main(int argc, char* argv[])
{
    if(argc == 3 && !strcmp(argv[1], "-t"))
    {
        arvoreB T;

        char *p;
        errno = 0;
        long valor = strtol(argv[2], &p, 10);
        int grau;

        if(errno != 0 || *p != '\0' || valor > INT_MAX)
        {
            printf("Argumentos invalidos\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            grau = valor;
            cria_arvore(&T, grau);

            // Menu
            bool sair = false;
            int opcao = 0;
            int arg;
            node* x;

            while(!sair)
            {
                printf("1 - Insercao\n2 - Busca\n3 - Sair\n");
                scanf("%d", &opcao);

                system("clear");

                if(opcao == 1)
                {
                    printf("Numero a ser inserido: ");
                    scanf("%d", &arg);
                    if(busca(T.raiz, &x, arg) == -1)
                        insere(&T, arg);
                    else
                        printf("Numero ja esta na arvore\n");
                }
                else if(opcao == 2)
                {
                    printf("Numero a ser buscado: ");
                    scanf("%d", &arg);

                    int indice = busca(T.raiz, &x, arg);

                    if(indice != -1)
                        printf("Elemento no no %p\nIndice: %d\n", x, indice);
                    else
                        printf("Chave nao encontrada\n");
                }
                else if(opcao == 3)
                    sair = true;
                else
                    printf("Opcao invalida\n");
                printf("\n\n\n");
            }

        }
    }
    else
        printf("Argumentos invalidos\n");

    return 0;
}
