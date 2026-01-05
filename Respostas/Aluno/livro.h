#ifndef _LIVRO_H
#define _LIVRO_H

#define MAX_TAM_TITULO 150
#define MAX_TAM_EDITORA 40
#define MAX_TAM_AUTOR 100

/**
 * @brief Estrutura de um livro.
 */
typedef struct Livro Livro;

/**
 * @brief Função que cria um novo livro e retorna o ponteiro para ele.
 *
 * @param titulo Título do livro.
 * @param autor Autor do livro.
 * @param editora Editora do livro.
 * @param ano Ano de publicação do livro.
 * @return Ponteiro para o novo livro criado.
 */
Livro *criarLivro(char *titulo, char *autor, char *editora, int ano);

/**
 * @brief Funçaõ que lê os dados de um livro da entrada padrão de acordo com a descrição do trabalho.
 * Dica: veja os casos de teste para entender o formato de entrada.
 *
 * @return Ponteiro para o livro lido.
 */
Livro *lerLivro();

/**
 * @brief Função que compara o autor de um livro com uma chave. Essa chave é recebida como um ponteiro void.
 * Faça a manipulação necessária para comparar o autor do livro com a chave.
 *
 * @param dado Ponteiro para o livro.
 * @param chave Ponteiro para a chave de comparação.
 * @return 1 se o autor do livro corresponde à chave, 0 caso contrário.
 */
int compararAutorLivro(void *dado, void *chave);

/**
 * @brief Função que compara o ano de um livro com uma chave. Essa chave é recebida como um ponteiro void.
 * Faça a manipulação necessária para comparar o ano do livro com a chave.
 *
 * @param dado Ponteiro para o livro.
 * @param chave Ponteiro para a chave de comparação.
 * @return 1 se o ano do livro corresponde à chave, 0 caso contrário.
 */
int compararAnoLivro(void *dado, void *chave);

/**
 * @brief Função que desaloca a memória de um livro.
 *
 * @param dado Ponteiro para o livro a ser desalocado.
 */
void desalocarLivro(void *dado);

/**
 * @brief Função que imprime os dados de um livro.
 * Dica: veja os casos de teste para entender o formato de saída e não perder tempo.
 *
 * @param dado Ponteiro para o livro a ser impresso.
 */
void imprimirLivro(void *dado);

#endif