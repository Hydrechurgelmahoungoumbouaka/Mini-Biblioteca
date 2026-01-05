#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "secao.h"
/*
    Definição de tipos e protótipos de funções de callback necessárias para manipulação dos itens da seção.
*/
typedef void (*func_ptr_desaloca_item)(void *dado);
typedef void (*func_ptr_imprime_item)(void *dado);
typedef int (*func_ptr_comparar_item)(void *dado, void *chave);

/*
    Definição da estrutura de uma seção.
*/
struct Secao
{
    func_ptr_desaloca_item ptr_desaloca;
    func_ptr_imprime_item ptr_imprime;
    func_ptr_comparar_item ptr_comparar;
    void **dados;
    int qtdSecao;
    int qtdMaxSecao;
};

/**
 * @brief Função que cria uma nova seção e retorna um ponteiro para ela.
 *
 * @param desaloca Callback para desalocar um item.
 * @return Ponteiro para a nova seção criada.
 */
Secao *criarSecao(func_ptr_desaloca_item desaloca)
{
    Secao *s = (Secao *)calloc(1, sizeof(Secao));
    if (s == NULL)
    {
        printf("Erro ao alocar memoria para secao.\n");
        exit(1);
    }

    if (s != NULL)
    {
        s->ptr_desaloca = desaloca;
        s->ptr_imprime = 0;
        s->ptr_comparar = 0;
        s->ptr_imprime == 0;
        s->qtdSecao = 0;
        s->qtdMaxSecao = 2;
        s->dados = malloc(s->qtdMaxSecao * sizeof(void *));
        if (s->dados == NULL)
        {
            printf("Erro ao alocar memoria para secao.\n");
            exit(1);
        }
    }
    else
    {
        exit(1);
    }

    return s;
}

/**
 * @brief Função que adiciona um item à seção. É responsável por toda manipulação de memória
 * para que isso aconteça de forma correta
 *
 * @param sec Ponteiro para a seção.
 * @param item Ponteiro para o item a ser adicionado.
 */
void addItemSecao(Secao *sec, void *item)
{
    if (sec->qtdSecao == sec->qtdMaxSecao)
    {
        sec->qtdMaxSecao *= 2;
        sec->dados = (void **)realloc(sec->dados, sizeof(void *) * sec->qtdMaxSecao);
        if (sec->dados == NULL)
        {
            printf("Erro ao realocar memoria para secao.\n");
            exit(1);
        }
    }

    sec->dados[sec->qtdSecao] = item;
    sec->qtdSecao++;
}

/**
 * @brief Função que imprime todos os itens da seção.
 *
 * @param sec Ponteiro para a seção.
 * @param imprime Callback para imprimir um item.
 */
void imprimirItensSecao(Secao *sec, func_ptr_imprime_item imprime)
{
    for (int i = 0; i < sec->qtdSecao; i++)
    {
        imprime(sec->dados[i]);
    }
}

/**
 * @brief Função que imprime item(ns) da seção de acordo com uma chave de comparação.
 * Dentro dessa função, é feita a comparação entre a chave e o item de acordo com a função de callback comparação.
 * Para imprimir o item, é utilizada a função de callback imprime.
 *
 * @param sec Ponteiro para a seção.
 * @param chave Ponteiro para a chave de comparação. Observe que é um ponteiro void, ou seja, pode ser qualquer tipo de dado.
 * @param compara Função de callback para comparar um item com a chave informada.
 * @param imprime Função de callback para imprimir um item.
 */
void imprimirItensPorChaveSecao(Secao *sec, void *chave, func_ptr_comparar_item compara, func_ptr_imprime_item imprime)
{
    for (int i = 0; i < sec->qtdSecao; i++)
    {
        if (compara(sec->dados[i], chave) == 1)
        {
            imprime(sec->dados[i]);
        }
    }
}

/**
 * @brief Função que desaloca uma a seção.
 *
 * @param sec Ponteiro para a seção a ser desalocada.
 */
void desalocarSecao(Secao *sec)
{
    for (int i = 0; i < sec->qtdSecao; i++)
    {
        sec->ptr_desaloca(sec->dados[i]);
    }
    free(sec->dados);
    free(sec);
}