#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "artigo.h"
#include "livro.h"
#include "secao.h"

int main()
{
    char op;
    int n;

    Secao *livros = criarSecao(desalocarLivro);
    Secao *artigos = criarSecao(desalocaArtigo);

   
    scanf("%d", &n);

    while (1)
    {
        scanf("%c\n", &op);

        if (op == 'F')
        {
            break;
        }
        else if (op == 'A')
        {
            tArtigo *a = leArtigo();
            addItemSecao(artigos, a);
        }
        else if (op == 'L')
        {
            Livro *l = lerLivro();
            addItemSecao(livros, l);
        }
        //E indica que uma funcionalidade deve ser executada
        else if (op == 'E')
        {
            char operacao[100];
            scanf(" %99[^\n]", operacao);

            if (strcmp(operacao, "LISTAR ACERVO") == 0)
            {
                printf("- - - LISTA DE TODOS OS ITENS DA BIBLIOTECA - - -\n");
                imprimirItensSecao(livros, imprimirLivro);
                imprimirItensSecao(artigos, imprimeArtigo);
            }
            else if (strcmp(operacao, "LISTAR LIVROS") == 0)
            {
                printf("- - - LISTA DE TODOS OS LIVROS DA BIBLIOTECA - - -\n");
                imprimirItensSecao(livros, imprimirLivro);
            }
            else if (strcmp(operacao, "LISTAR ARTIGOS") == 0)
            {
                printf("- - - LISTA DE TODOS OS ARTIGOS DA BIBLIOTECA - - -\n");
                imprimirItensSecao(artigos, imprimeArtigo);
            }
            else if (strcmp(operacao, "LISTAR AUTOR") == 0)
            {
                char autor[100];
                scanf(" %99[^\n]", autor);

                printf("- - - LISTA DE TODOS OS ITENS DE UM AUTOR - - -\n");
                printf("Nome do autor: %s\n", autor);

                imprimirItensPorChaveSecao(livros, autor, compararAutorLivro, imprimirLivro);
                imprimirItensPorChaveSecao(artigos, autor, comparaAutorArtigo, imprimeArtigo);
            }
            else if (strcmp(operacao, "LISTAR ANO") == 0)
            {
                int ano;
                scanf("%d", &ano);

                printf("- - - LISTA DE TODOS OS ITENS DE UM ANO - - -\n");
                printf("- Ano: %d\n", ano);

                imprimirItensPorChaveSecao(livros, &ano, compararAnoLivro, imprimirLivro);
                imprimirItensPorChaveSecao(artigos, &ano, comparaAnoArtigo, imprimeArtigo);
            }
        }
    }

    desalocarSecao(livros);
    desalocarSecao(artigos);

    return 0;
}
