#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "livro.h"

#define MAX_TAM_TITULO 150
#define MAX_TAM_EDITORA 40
#define MAX_TAM_AUTOR 100

/**
 * @brief Estrutura de um livro.
 */
struct Livro
{
    char titulo[MAX_TAM_TITULO];
    char autor[MAX_TAM_AUTOR];
    char editora[MAX_TAM_EDITORA];
    int anoPublicacao;
};

/**
 * @brief Função que cria um novo livro e retorna o ponteiro para ele.
 *
 * @param titulo Título do livro.
 * @param autor Autor do livro.
 * @param editora Editora do livro.
 * @param ano Ano de publicação do livro.
 * @return Ponteiro para o novo livro criado.
 */
Livro *criarLivro(char *titulo, char *autor, char *editora, int ano)
{
    Livro *l = (Livro *)calloc(1, sizeof(Livro));
    if (l == NULL)
    {
        printf("Erro ao alocar memoria para o livro.\n");
        exit(1);
    }
    if (l != NULL)
    {
        strcpy(l->titulo, titulo);
        strcpy(l->autor, autor);
        strcpy(l->editora, editora);
        l->anoPublicacao = ano;
    }
    else
    {
        exit(1);
    }

    return l;
}

/**
 * @brief Funçaõ que lê os dados de um livro da entrada padrão de acordo com a descrição do trabalho.
 * Dica: veja os casos de teste para entender o formato de entrada.
 *
 * @return Ponteiro para o livro lido.
 */
Livro *lerLivro()
{
 
    char titulo[MAX_TAM_TITULO];
    char autor[MAX_TAM_AUTOR];
    char editora[MAX_TAM_EDITORA];
    int anoPublicacao;
    scanf("%149[^\n] %99[^\n] %39[^\n] %d", titulo, autor, editora, &anoPublicacao);
    scanf("%*c");
    return criarLivro(titulo, autor, editora, anoPublicacao);
}
/**
 * @brief Função que compara o autor de um livro com uma chave. Essa chave é recebida como um ponteiro void.
 * Faça a manipulação necessária para comparar o autor do livro com a chave.
 *
 * @param dado Ponteiro para o livro.
 * @param chave Ponteiro para a chave de comparação.
 * @return 1 se o autor do livro corresponde à chave, 0 caso contrário.
 */
int compararAutorLivro(void *dado, void *chave)
{
    Livro *l = (Livro *)dado;
    if (strcmp(l->autor, chave) == 0)
    {
        return 1;
    }
    return 0;
}

/**
 * @brief Função que compara o ano de um livro com uma chave. Essa chave é recebida como um ponteiro void.
 * Faça a manipulação necessária para comparar o ano do livro com a chave.
 *
 * @param dado Ponteiro para o livro.
 * @param chave Ponteiro para a chave de comparação.
 * @return 1 se o ano do livro corresponde à chave, 0 caso contrário.
 */
int compararAnoLivro(void *dado, void *chave)
{
    Livro *l = (Livro *)dado;
    int *anoChave = (int *)chave;
    if (l->anoPublicacao == *anoChave)
    {
        return 1;
    }
    return 0;
}

/**
 * @brief Função que desaloca a memória de um livro.
 *
 * @param dado Ponteiro para o livro a ser desalocado.
 */
void desalocarLivro(void *dado)
{
    Livro *l = (Livro *)dado;
    if (l != NULL)
    {
        free(l);
    }
}

/**
 * @brief Função que imprime os dados de um livro.
 * Dica: veja os casos de teste para entender o formato de saída e não perder tempo.
 *
 * @param dado Ponteiro para o livro a ser impresso.
 */
void imprimirLivro(void *dado)
{
    Livro *l = (Livro *)dado;
    if (l == NULL)
    {
        printf("Nenhum livro foi cadastrado.\n");
        exit(1);
    }

    if (l != NULL)
    {
        printf("- - - Livro - - -\n");
        printf("Titulo: %s\n", l->titulo);
        printf("Autor: %s\n", l->autor);
        printf("Editora: %s\n", l->editora);
        printf("Ano: %d\n", l->anoPublicacao);
        printf("- - - - - - - - -\n");
    }
    else
    {
        exit(1);
    }
}