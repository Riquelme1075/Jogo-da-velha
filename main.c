#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Função que imprime a matriz tabuleiro
void imprimir_tabuleiro(char tabuleiro[3][3])
{
    int i, j;

    system("cls || clean");

    printf("   1 ");
    printf(" 2 ");
    printf(" 3 \n");

    // Imprimindo as linhas e colunas
    for (i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            printf("A ");
        }
        else if (i == 1)
        {
            printf("B ");
        }
        else
        {
            printf("C ");
        }

        for (j = 0; j < 3; j++)
        {
            printf("|%c|", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int marcar(char tabuleiro[3][3], int jogador_atual, char posicao[5])
{
    char simbolo;
    char linha, coluna;

    // Recebendo linha, a, b ou c
    linha = tolower(posicao[0]);

    // Recebendo coluna, 1, 2, 3
    coluna = tolower(posicao[1]);

    // Dando o simbolo ao jogador que fez a jogada.
    if (jogador_atual == 1)
    {
        simbolo = 'x';
    }
    else
    {
        simbolo = 'O';
    }
    if (linha == 'a')
    {
        if (coluna == '1' && tabuleiro[0][0] == ' ')
        {
            tabuleiro[0][0] = simbolo;
        }
        else if (coluna == '2' && tabuleiro[0][1] == ' ')
        {
            tabuleiro[0][1] = simbolo;
        }
        else if (coluna == '3' && tabuleiro[0][2] == ' ')
        {
            tabuleiro[0][2] = simbolo;
        }
        else
        {
            return 0;
        }
    }
    else if (linha == 'b')
    {
        if (coluna == '1' && tabuleiro[1][0] == ' ')
        {
            tabuleiro[1][0] = simbolo;
        }
        else if (coluna == '2' && tabuleiro[1][1] == ' ')
        {
            tabuleiro[1][1] = simbolo;
        }
        else if (coluna == '3' && tabuleiro[1][2] == ' ')
        {
            tabuleiro[1][2] = simbolo;
        }
        else
        {
            return 0;
        }
    }
    else if (linha == 'c')
    {
        if (coluna == '1' && tabuleiro[2][0] == ' ')
        {
            tabuleiro[2][0] = simbolo;
        }
        else if (coluna == '2' && tabuleiro[2][1] == ' ')
        {
            tabuleiro[2][1] = simbolo;
        }
        else if (coluna == '3' && tabuleiro[2][2] == ' ')
        {
            tabuleiro[2][2] = simbolo;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
    imprimir_tabuleiro(tabuleiro);
    return 1;
}

void verificar_vencedor(char tabuleiro[3][3], int jogador_atual, int *venceu)
{
    int simbolo, i;
    *venceu = 0;

    // Determinando o simbolo do jogador que está jogando
    if (jogador_atual == 1)
    {
        simbolo = 'x';
    }
    else
    {
        simbolo = 'O';
    }

    // Verificando
    for (i = 0; i < 3; i++)
    {
        // Colunas
        if (tabuleiro[0][i] == simbolo && tabuleiro[1][i] == simbolo && tabuleiro[2][i] == simbolo && *venceu == 0)
        {
            *venceu = 1;
        }

        // Linhas
        if (tabuleiro[i][0] == simbolo && tabuleiro[i][1] == simbolo && tabuleiro[i][2] == simbolo && *venceu == 0)
        {
            *venceu = 1;
        }
    }
    // em formato de \ ou /
    if (tabuleiro[0][0] == simbolo && tabuleiro[1][1] == simbolo && tabuleiro[2][2] == simbolo && *venceu == 0)
    {
        *venceu = 1;
    }
    else if (tabuleiro[0][2] == simbolo && tabuleiro[1][1] == simbolo && tabuleiro[2][0] == simbolo && *venceu == 0)
    {
        *venceu = 1;
    }
}

int main()
{
    char jogador_1[50];
    char jogador_2[50];
    char posicao[5];
    int venceu;
    int qtd_jogadas;
    char tabuleiro[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};

    venceu = 0;
    qtd_jogadas = 0;

    system("cls || clean");
    printf("=-=-=-=-=-=-=-=-=-=-=\n");
    printf("    JOGO DA VELHA   \n");
    printf("=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Jogador 1: ");
    fflush(stdin);
    scanf("%[^\n]", jogador_1);

    printf("Jogador 2: ");
    fflush(stdin);
    scanf("%[^\n]", jogador_2);

    system("cls || clean");

    imprimir_tabuleiro(tabuleiro);

    int terminar = 0;
    int jogador_atual = 1;
    int jogada;
    while (terminar == 0)
    {
        if (jogador_atual == 1)
        {
            printf("\n--Escolha a posicao\n");
            printf(" %s:", jogador_1);
            fflush(stdin);
            scanf("%[^\n]", posicao);
            // Se a jogada foi valida retorna 1
            jogada = marcar(tabuleiro, jogador_atual, posicao);
            verificar_vencedor(tabuleiro, jogador_atual, &venceu);
            if (venceu == 1)
            {
                printf("PAREBENS!\n");
                printf("%s venceu a partida.", jogador_1);
                terminar = 1;
            }
            else if (jogada == 0) // Jogada foi falsa, invalida
            {
                system("cls || clean");
                imprimir_tabuleiro(tabuleiro);
                printf("\nJogada invalida!");
                jogador_atual = 1;
            }
            else
            {
                jogador_atual = 2; // Troca para o jogador 2.
                qtd_jogadas ++;
            }
        }else if (jogador_atual == 2)
        {
            printf("\n--Escolha a posicao--\n");
            printf(" %s:", jogador_2);
            fflush(stdin);
            scanf("%[^\n]", posicao);
            jogada = marcar(tabuleiro, jogador_atual, posicao);
            verificar_vencedor(tabuleiro, jogador_atual, &venceu);
            if (venceu == 1)
            {
                printf("PAREBENS!\n");
                printf("%s venceu a partida.", jogador_2);
                terminar = 1;
            }
            else if (jogada == 0) // Jogada foi falsa, invalida
            {
                system("cls || clean");
                imprimir_tabuleiro(tabuleiro);
                printf("\nJogada invalida!");
                jogador_atual = 2;
            }
            else
            {
                jogador_atual = 1; // Troca para o jogador 2.
                qtd_jogadas ++;
            }
        }

        if(qtd_jogadas == 9){
            system("cls || clean");
            imprimir_tabuleiro(tabuleiro);
            printf("\nEmpate!\n");
            terminar = 1;
        }
    }
}