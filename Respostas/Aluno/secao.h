#ifndef _SECAO_H
#define _SECAO_H

/*
    Definição de tipos e protótipos de funções de callback necessárias para manipulação dos itens da seção.
*/
typedef void (*func_ptr_desaloca_item)(void *dado);
typedef void (*func_ptr_imprime_item)(void *dado);
typedef int (*func_ptr_comparar_item)(void *dado, void *chave);

/*
    Definição da estrutura de uma seção.
*/
typedef struct Secao Secao;

/**
 * @brief Função que cria uma nova seção e retorna um ponteiro para ela.
 *
 * @param desaloca Callback para desalocar um item.
 * @return Ponteiro para a nova seção criada.
 */
Secao *criarSecao(func_ptr_desaloca_item desaloca);

/**
 * @brief Função que adiciona um item à seção. É responsável por toda manipulação de memória
 * para que isso aconteça de forma correta
 *
 * @param sec Ponteiro para a seção.
 * @param item Ponteiro para o item a ser adicionado.
 */
void addItemSecao(Secao *sec, void *item);

/**
 * @brief Função que imprime todos os itens da seção.
 *
 * @param sec Ponteiro para a seção.
 * @param imprime Callback para imprimir um item.
 */
void imprimirItensSecao(Secao *sec, func_ptr_imprime_item imprime);

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
void imprimirItensPorChaveSecao(Secao *sec, void *chave, func_ptr_comparar_item compara, func_ptr_imprime_item imprime);

/**
 * @brief Função que desaloca uma a seção.
 *
 * @param sec Ponteiro para a seção a ser desalocada.
 */
void desalocarSecao(Secao *sec);

#endif