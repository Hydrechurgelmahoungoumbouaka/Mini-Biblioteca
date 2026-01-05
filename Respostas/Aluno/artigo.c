#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "artigo.h"

#define TAM_TITULO 100
#define TAM_AUTOR 100
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
struct artigo
{
    char titulo[TAM_TITULO];
    char autor[TAM_AUTOR];
    char nomeJornal[TAM_JORNAL];
    int anoPublicacao;
    int numPaginas;
};

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
tArtigo *criaArtigo(char *titulo, char *autor, char *nome, int ano, int numPagina)
{
    tArtigo *a = (tArtigo *)calloc(1, sizeof(tArtigo));
    if (a == NULL)
    {
        printf("Erro ao alocar memoria para artigo.\n");
        exit(1);
    }
    if (a != NULL)
    {
        strcpy(a->titulo, titulo);
        strcpy(a->autor, autor);
        strcpy(a->nomeJornal, nome);

        a->anoPublicacao = ano;
        a->numPaginas = numPagina;
    }
    else
    {
        exit(1);
    }

    return a;
}

/**
 * @brief Função que lê os dados de um artigo da entrada padrão de acordo com a descrição do trabalho.
 * Dica: veja os casos de teste para entender o formato de entrada.
 *
 * @return Ponteiro para o artigo lido.
 */
tArtigo *leArtigo()
{

    char titulo[TAM_TITULO];
    char autor[TAM_AUTOR];
    char nomeJornal[TAM_JORNAL];
    int anoPublicacao;
    int numPaginas;
    scanf("%99[^\n] %99[^\n] %99[^\n] %d %d", titulo, autor, nomeJornal, &anoPublicacao, &numPaginas);
    scanf("%*c");
    return criaArtigo(titulo, autor, nomeJornal, anoPublicacao, numPaginas);
}

/**
 * @brief Função que compara o autor de um artigo com uma chave.
 * Essa chave é recebida como um ponteiro void.
 * Faça a manipulação necessária para comparar o autor do artigo com a chave.
 *
 * @param dado Ponteiro para o artigo.
 * @param chave Ponteiro para a chave de comparação.
 * @return 1 se o autor do artigo corresponde à chave, 0 caso contrário.
 */
int comparaAutorArtigo(void *dado, void *chave)
{
    tArtigo *a = (tArtigo *)dado;
    if (strcmp(a->autor, chave) == 0)
    {
        return 1;
    }
    return 0;
}

/**
 * @brief Função que compara o ano de um artigo com uma chave.
 * Essa chave é recebida como um ponteiro void.
 * Faça a manipulação necessária para comparar o ano do artigo com a chave.
 *
 * @param dado Ponteiro para o artigo.
 * @param chave Ponteiro para a chave de comparação.
 * @return 1 se o ano do artigo corresponde à chave, 0 caso contrário.
 */
int comparaAnoArtigo(void *dado, void *chave)
{
    tArtigo *a = (tArtigo *)dado;
    int *anoChave;
    anoChave = (int *)chave;
    if (a->anoPublicacao == *anoChave)
    {
        return 1;
    }
    return 0;
}

/**
 * @brief Função que desaloca a memória de um artigo.
 *
 * @param dado Ponteiro para o artigo a ser desalocado.
 */
void desalocaArtigo(void *dado)
{
    tArtigo *a = (tArtigo *)dado;
    if (a != NULL)
    {
        free(a);
    }
}

/**
 * @brief Função que imprime os dados de um artigo.
 * Dica: veja os casos de teste para entender o formato de saída e não perder tempo.
 *
 * @param dado Ponteiro para o artigo a ser impresso.
 */
void imprimeArtigo(void *dado)
{
    tArtigo *a = (tArtigo *)dado;
    if (a == NULL)
    {
        printf("Nenhum artigo foi cadastrado.\n");
        exit(1);
    }

    if (a != NULL)
    {
        printf("- - - Artigo - - -\n");
        printf("Titulo: %s\n", a->titulo);
        printf("Autor: %s\n", a->autor);
        printf("Jornal: %s\n", a->nomeJornal);
        printf("Ano: %d\n", a->anoPublicacao);
        printf("Num. Paginas: %d\n", a->numPaginas);
        printf("- - - - - - - - -\n");
    }
    else
    {
        exit(1);
    }
}
