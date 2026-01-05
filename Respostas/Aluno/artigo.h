#ifndef _ARTIGO_H
#define _ARTIGO_H

#define TAM_TITULO 100
#define AM_AUTOR 100
#define TAM_JORNAL 100

/**
 * @brief Estrutura de um artigo.
 *
 * Um artigo é composto pelas seguintes informações:
 * - Título do artigo
 * - Autor do artigo
 * - Nome do jornal em que foi publicado
 * - Ano de publicação
 * - Número de páginas
 */
typedef struct artigo tArtigo;

/**
 * @brief Função que cria um novo artigo e retorna o ponteiro para ele.
 *
 * @param titulo Título do artigo.
 * @param autor Autor do artigo.
 * @param nome Nome do jornal em que o artigo foi publicado.
 * @param ano Ano de publicação do artigo.
 * @param numPagina Número de páginas do artigo.
 * @return Ponteiro para o novo artigo criado.
 */
tArtigo *criaArtigo(char *titulo, char *autor, char *nome, int ano, int numPagina);

/**
 * @brief Função que lê os dados de um artigo da entrada padrão de acordo com a descrição do trabalho.
 * Dica: veja os casos de teste para entender o formato de entrada.
 *
 * @return Ponteiro para o artigo lido.
 */
tArtigo *leArtigo();

/**
 * @brief Função que compara o autor de um artigo com uma chave.
 * Essa chave é recebida como um ponteiro void.
 * Faça a manipulação necessária para comparar o autor do artigo com a chave.
 *
 * @param dado Ponteiro para o artigo.
 * @param chave Ponteiro para a chave de comparação.
 * @return 1 se o autor do artigo corresponde à chave, 0 caso contrário.
 */
int comparaAutorArtigo(void *dado, void *chave);

/**
 * @brief Função que compara o ano de um artigo com uma chave.
 * Essa chave é recebida como um ponteiro void.
 * Faça a manipulação necessária para comparar o ano do artigo com a chave.
 *
 * @param dado Ponteiro para o artigo.
 * @param chave Ponteiro para a chave de comparação.
 * @return 1 se o ano do artigo corresponde à chave, 0 caso contrário.
 */
int comparaAnoArtigo(void *dado, void *chave);

/**
 * @brief Função que desaloca a memória de um artigo.
 *
 * @param dado Ponteiro para o artigo a ser desalocado.
 */
void desalocaArtigo(void *dado);

/**
 * @brief Função que imprime os dados de um artigo.
 * Dica: veja os casos de teste para entender o formato de saída e não perder tempo.
 *
 * @param dado Ponteiro para o artigo a ser impresso.
 */
void imprimeArtigo(void *dado);

#endif
