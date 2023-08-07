#include <iostream>
#include <windows.h>
#include <limits>

using namespace std;

// variaveis
// Utilizamos char para jogada para evitar bug de repetição ao digitar um não número.
char jogada, tabuleiro[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
string nome1, nome2;                  // Nomes dos jogadores
bool jogador = true;                  // bool jogador utilizada para alternar entre jogador 1 (X) e jogador 2 (O)
int contador = 0;                     // Contador de jogadas válidas para executar a função Velha()
int opcao;                            // Utilizado no switch case da tela final (jogar novamente)
int p1win = 0, p2win = 0, empate = 0; // Utilizado para contabilizar vitorias do Jogador 1 e 2

// A função Jogo() é a função principal que exibe o tabuleiro atualizado ao final de cada jogada até que uma das funções (Vitória ou Velha) sejam chamadas.
void jogo()
{
    cout << endl
         << "Jogo da Velha" << endl
         << endl;
    cout << "Vitórias de " << nome1 << ": " << p1win
         << endl;
    cout << "Vitórias de " << nome2 << ": " << p2win
         << endl;
    cout << "Empates: " << empate << endl
         << endl
         << endl;

    // Esse for exibe o tabuleiro atualizado.
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {

            cout << tabuleiro[i][j] << " ";

            if (j < 2)
            {
                cout << "| ";
            }
        }
        cout << endl;
        if (i < 2)
        {
            cout << "---------" << endl;
        }
    }

    // Para alternar as jogadas eu utilizei uma variável booleana, onde o jogador=true é o Jogador 1 (X) e o Jogador 2 (O) é o jogador=false.
    if (jogador)
    {
        cout << endl
             << endl
             << nome1 << ", insira a posição que deseja jogar (1-9): ";
    }
    else
    {
        cout << endl
             << endl
             << nome2 << ", insira a posição que deseja jogar (1-9): ";
    }

    cin >> jogada;

    // Essas são as verificações de jogadas válidas, que checa se voce digitou um numero entre 1 e 9 e se não escolheu uma casa ocupada.
    if (jogada != '1' && jogada != '2' && jogada != '3' && jogada != '4' && jogada != '5' && jogada != '6' && jogada != '7' && jogada != '8' && jogada != '9')
    {
        cout << endl
             << "Jogada inválida, digite um numero entre 1 e 9!" << endl
             << endl;
        system("pause");
        system("cls");
        jogo();
    }
    else if (tabuleiro[0][0] != ' ' && jogada == '1' || tabuleiro[0][1] != ' ' && jogada == '2' || tabuleiro[0][2] != ' ' && jogada == '3' || tabuleiro[1][0] != ' ' && jogada == '4' || tabuleiro[1][1] != ' ' && jogada == '5' || tabuleiro[1][2] != ' ' && jogada == '6' || tabuleiro[2][0] != ' ' && jogada == '7' || tabuleiro[2][1] != ' ' && jogada == '8' || tabuleiro[2][2] != ' ' && jogada == '9')
    {
        cout << endl
             << "Jogada inválida, você escolheu uma casa ocupada!" << endl
             << endl;
        system("pause");
        system("cls");
        jogo();
    }

    // Caso a jogada seja Válida o programa chegará aqui, onde ira preencher (X) ou (O) de acordo com o valor da booleana jogador
    // Ao mesmo tempo cada jogada válida será marcada pelo int contador, para que ao final de 9 jogadas válidas sem nenhum vencedor execulte a função Velha()
    else
    {
        if (jogador == true)
        {
            if (jogada == '1')
            {
                contador += 1;
                tabuleiro[0][0] = 'X';
            }

            if (jogada == '2')
            {
                contador += 1;
                tabuleiro[0][1] = 'X';
            }

            if (jogada == '3')
            {
                contador += 1;
                tabuleiro[0][2] = 'X';
            }

            if (jogada == '4')
            {
                contador += 1;
                tabuleiro[1][0] = 'X';
            }

            if (jogada == '5')
            {
                contador += 1;
                tabuleiro[1][1] = 'X';
            }

            if (jogada == '6')
            {
                contador += 1;
                tabuleiro[1][2] = 'X';
            }
            if (jogada == '7')
            {
                contador += 1;
                tabuleiro[2][0] = 'X';
            }

            if (jogada == '8')
            {
                contador += 1;
                tabuleiro[2][1] = 'X';
            }

            if (jogada == '9')
            {
                contador += 1;
                tabuleiro[2][2] = 'X';
            }
            jogador = false;
        }
        else
        {
            if (jogada == '1')
            {
                contador += 1;
                tabuleiro[0][0] = 'O';
            }

            if (jogada == '2')
            {
                contador += 1;
                tabuleiro[0][1] = 'O';
            }

            if (jogada == '3')
            {
                contador += 1;
                tabuleiro[0][2] = 'O';
            }

            if (jogada == '4')
            {
                contador += 1;
                tabuleiro[1][0] = 'O';
            }

            if (jogada == '5')
            {
                contador += 1;
                tabuleiro[1][1] = 'O';
            }

            if (jogada == '6')
            {
                contador += 1;
                tabuleiro[1][2] = 'O';
            }
            if (jogada == '7')
            {
                contador += 1;
                tabuleiro[2][0] = 'O';
            }

            if (jogada == '8')
            {
                contador += 1;
                tabuleiro[2][1] = 'O';
            }

            if (jogada == '9')
            {
                contador += 1;
                tabuleiro[2][2] = 'O';
            }
            jogador = true;
        }
    }

    system("cls");

    // Aqui, ao final das jogadas, são execultadas as verificações de vitoria.
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[2][2] != ' ' || tabuleiro[2][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[0][2] && tabuleiro[0][2] != ' ' || tabuleiro[0][0] == tabuleiro[0][1] && tabuleiro[0][1] == tabuleiro[0][2] && tabuleiro[0][2] != ' ' || tabuleiro[1][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[1][2] && tabuleiro[1][2] != ' ' || tabuleiro[2][0] == tabuleiro[2][1] && tabuleiro[2][1] == tabuleiro[2][2] && tabuleiro[2][2] != ' ' || tabuleiro[0][0] == tabuleiro[1][0] && tabuleiro[1][0] == tabuleiro[2][0] && tabuleiro[2][0] != ' ' || tabuleiro[0][1] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][1] && tabuleiro[2][1] != ' ' || tabuleiro[0][2] == tabuleiro[1][2] && tabuleiro[1][2] == tabuleiro[2][2] && tabuleiro[2][2] != ' ')
    {
        if (jogador == false)
        {
            do
            {
                system("cls");
                cout << "---Fim de jogo!!!---" << endl
                     << endl;
                cout << nome1 << " venceu!!!" << endl
                     << endl;
                cout << "1 - Jogar novamente." << endl
                     << "2 - Reiniciar Tabuleiro com novos jogadores e vitorias zeradas." << endl
                     << "3 - Fechar programa." << endl
                     << endl
                     << "Sua escolha: ";
                cin >> opcao;

                switch (opcao)
                {
                case 1:
                    system("cls");
                    tabuleiro[0][0] = ' ';
                    tabuleiro[1][0] = ' ';
                    tabuleiro[2][0] = ' ';
                    tabuleiro[0][1] = ' ';
                    tabuleiro[0][2] = ' ';
                    tabuleiro[1][1] = ' ';
                    tabuleiro[2][2] = ' ';
                    tabuleiro[1][2] = ' ';
                    tabuleiro[2][1] = ' ';
                    contador = 0;

                    p1win += 1;
                    jogo();
                case 2:
                    p1win = 0;
                    p2win = 0;
                    empate = 0;
                    system("cls");
                    tabuleiro[0][0] = ' ';
                    tabuleiro[1][0] = ' ';
                    tabuleiro[2][0] = ' ';
                    tabuleiro[0][1] = ' ';
                    tabuleiro[0][2] = ' ';
                    tabuleiro[1][1] = ' ';
                    tabuleiro[2][2] = ' ';
                    tabuleiro[1][2] = ' ';
                    tabuleiro[2][1] = ' ';
                    contador = 0;

                    cout << "Jogo da Véia" << endl
                         << endl;
                    cout << "Esse será o modelo do Tabuleiro, utilize a tecla de acordo com a casa desejada." << endl
                         << endl;
                    cout << " 1 | 2 | 3" << endl;
                    cout << "----------" << endl;
                    cout << " 4 | 5 | 6" << endl;
                    cout << "----------" << endl;
                    cout << " 7 | 8 | 9" << endl
                         << endl;
                    cout << "Insira o nome do jogador 1 (X): ";
                    cin >> nome1;
                    cout << "Insira o nome do Jogador 2 (O): ";
                    cin >> nome2;
                    system("cls");
                    jogo();

                case 3:
                    system("cls");
                    exit(0);
                }
            } while (opcao < 1 || opcao > 3);
        }

        else
        {
            do
            {
                system("cls");
                cout << "---Fim de jogo!!!---" << endl
                     << endl;
                cout << nome2 << " venceu!!!" << endl
                     << endl;
                cout << "1 - Jogar novamente." << endl
                     << "2 - Reiniciar Tabuleiro com novos jogadores e vitorias zeradas." << endl
                     << "3 - Fechar programa." << endl
                     << endl
                     << "Sua escolha: ";
                cin >> opcao;

                switch (opcao)
                {
                case 1:
                    system("cls");
                    tabuleiro[0][0] = ' ';
                    tabuleiro[1][0] = ' ';
                    tabuleiro[2][0] = ' ';
                    tabuleiro[0][1] = ' ';
                    tabuleiro[0][2] = ' ';
                    tabuleiro[1][1] = ' ';
                    tabuleiro[2][2] = ' ';
                    tabuleiro[1][2] = ' ';
                    tabuleiro[2][1] = ' ';
                    contador = 0;

                    p2win += 1;
                    jogo();
                case 2:
                    p1win = 0;
                    p2win = 0;
                    empate = 0;
                    system("cls");
                    tabuleiro[0][0] = ' ';
                    tabuleiro[1][0] = ' ';
                    tabuleiro[2][0] = ' ';
                    tabuleiro[0][1] = ' ';
                    tabuleiro[0][2] = ' ';
                    tabuleiro[1][1] = ' ';
                    tabuleiro[2][2] = ' ';
                    tabuleiro[1][2] = ' ';
                    tabuleiro[2][1] = ' ';
                    contador = 0;

                    cout << "Jogo da Véia" << endl
                         << endl;
                    cout << "Esse será o modelo do Tabuleiro, utilize a tecla de acordo com a casa desejada." << endl
                         << endl;
                    cout << " 1 | 2 | 3" << endl;
                    cout << "----------" << endl;
                    cout << " 4 | 5 | 6" << endl;
                    cout << "----------" << endl;
                    cout << " 7 | 8 | 9" << endl
                         << endl;
                    cout << "Insira o nome do jogador 1 (X): ";
                    cin >> nome1;
                    cout << "Insira o nome do Jogador 2 (O): ";
                    cin >> nome2;
                    system("cls");
                    jogo();

                case 3:
                    system("cls");
                    exit(0);
                }
            } while (opcao < 1 || opcao > 3);
        }
    }

    // Aqui, ao final das verificações de vitória, execultamos uma verificação de empate utilizando o int contador
    else if (contador == 9)
    {
        do
        {
            system("cls");
            cout << "---Deu velha!!!---" << endl
                 << endl;
            cout << "Houve um empate." << endl
                 << endl;
            cout << "1 - Jogar novamente." << endl
                 << "2 - Reiniciar Tabuleiro com novos jogadores e vitorias zeradas." << endl
                 << "3 - Fechar programa." << endl
                 << endl
                 << "Sua escolha: ";
            cin >> opcao;

            switch (opcao)
            {
            case 1:
                system("cls");
                tabuleiro[0][0] = ' ';
                tabuleiro[1][0] = ' ';
                tabuleiro[2][0] = ' ';
                tabuleiro[0][1] = ' ';
                tabuleiro[0][2] = ' ';
                tabuleiro[1][1] = ' ';
                tabuleiro[2][2] = ' ';
                tabuleiro[1][2] = ' ';
                tabuleiro[2][1] = ' ';
                contador = 0;

                empate += 1;
                jogo();
            case 2:
                p1win = 0;
                p2win = 0;
                empate = 0;
                system("cls");
                tabuleiro[0][0] = ' ';
                tabuleiro[1][0] = ' ';
                tabuleiro[2][0] = ' ';
                tabuleiro[0][1] = ' ';
                tabuleiro[0][2] = ' ';
                tabuleiro[1][1] = ' ';
                tabuleiro[2][2] = ' ';
                tabuleiro[1][2] = ' ';
                tabuleiro[2][1] = ' ';
                contador = 0;

                cout << "Jogo da Velha" << endl
                     << endl;
                cout << "Esse será o modelo do Tabuleiro, utilize a tecla de acordo com a casa desejada." << endl
                     << endl;
                cout << " 1 | 2 | 3" << endl;
                cout << "----------" << endl;
                cout << " 4 | 5 | 6" << endl;
                cout << "----------" << endl;
                cout << " 7 | 8 | 9" << endl
                     << endl;
                cout << "Insira o nome do jogador 1 (X): ";
                cin >> nome1;
                cout << "Insira o nome do Jogador 2 (O): ";
                cin >> nome2;
                system("cls");
                jogo();

            case 3:
                system("cls");
                exit(0);
            }
        } while (opcao < 1 || opcao > 3);
    }

    // Por final, se nenhuma função de fim de jogo for chamada, retornamos o tabuleiro atualizado, solicitando uma nova jogada
    else
    {
        jogo();
    }
}

// Aqui esta a tela inicial do jogo, onde mostramos o modelo do tabuleiro e pedimos as entradas de nomes dos jogadores.
int main()
{
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);

    cout << "Jogo da Velha" << endl
         << endl;
    cout << "Esse será o modelo do Tabuleiro, utilize a tecla de acordo com a casa desejada." << endl
         << endl;
    cout << " 1 | 2 | 3" << endl;
    cout << "----------" << endl;
    cout << " 4 | 5 | 6" << endl;
    cout << "----------" << endl;
    cout << " 7 | 8 | 9" << endl
         << endl;
    cout << "Insira o nome do jogador 1 (X): ";
    cin >> nome1;
    cout << "Insira o nome do Jogador 2 (O): ";
    cin >> nome2;
    system("cls");
    jogo();
}