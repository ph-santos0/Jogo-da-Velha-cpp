#include <iostream>
#include <windows.h>
#include <limits>

using namespace std;

char tabuleiro[3][3];
string nome1, nome2;
bool jogador = true;
int contador;
int p1win, p2win, empate;

void jogo(), fimjogo();

int main()
{
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);

    system("cls");
    cout << "Jogo da Velha" << endl
         << endl;
    cout << "Esse será o modelo do tabuleiro, utilize a tecla de acordo com a casa desejada." << endl
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

    p1win = 0;
    p2win = 0;
    empate = 0;

    tabuleiro[0][0] = ' ';
    tabuleiro[1][0] = ' ';
    tabuleiro[2][0] = ' ';
    tabuleiro[0][1] = ' ';
    tabuleiro[0][2] = ' ';
    tabuleiro[1][1] = ' ';
    tabuleiro[2][2] = ' ';
    tabuleiro[1][2] = ' ';
    tabuleiro[2][1] = ' ';
    jogo();
}

void jogo()
{
    system("cls");
    cout << "Jogo da Velha" << endl
         << endl;
    cout << "Vitórias de " << nome1 << ": " << p1win << endl;
    cout << "Vitórias de " << nome2 << ": " << p2win << endl;
    cout << "Empates: " << empate << endl
         << endl
         << endl;

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

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.clear();

    char jogada;
    cin >> jogada;

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
    else
    {
        char simbolo;

        if (jogador == true)
        {
            simbolo = 'X';
        }
        else
        {
            simbolo = 'O';
        }

        if (jogada == '1')
        {
            tabuleiro[0][0] = simbolo;
        }
        if (jogada == '2')
        {
            tabuleiro[0][1] = simbolo;
        }
        if (jogada == '3')
        {
            tabuleiro[0][2] = simbolo;
        }
        if (jogada == '4')
        {
            tabuleiro[1][0] = simbolo;
        }
        if (jogada == '5')
        {
            tabuleiro[1][1] = simbolo;
        }
        if (jogada == '6')
        {
            tabuleiro[1][2] = simbolo;
        }
        if (jogada == '7')
        {
            tabuleiro[2][0] = simbolo;
        }
        if (jogada == '8')
        {
            tabuleiro[2][1] = simbolo;
        }
        if (jogada == '9')
        {
            tabuleiro[2][2] = simbolo;
        }
        contador += 1;
        jogador = !jogador;
    }

    system("cls");

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[2][2] != ' ' || tabuleiro[2][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[0][2] && tabuleiro[0][2] != ' ' || tabuleiro[0][0] == tabuleiro[0][1] && tabuleiro[0][1] == tabuleiro[0][2] && tabuleiro[0][2] != ' ' || tabuleiro[1][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[1][2] && tabuleiro[1][2] != ' ' || tabuleiro[2][0] == tabuleiro[2][1] && tabuleiro[2][1] == tabuleiro[2][2] && tabuleiro[2][2] != ' ' || tabuleiro[0][0] == tabuleiro[1][0] && tabuleiro[1][0] == tabuleiro[2][0] && tabuleiro[2][0] != ' ' || tabuleiro[0][1] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][1] && tabuleiro[2][1] != ' ' || tabuleiro[0][2] == tabuleiro[1][2] && tabuleiro[1][2] == tabuleiro[2][2] && tabuleiro[2][2] != ' ')
    {
        contador = 0;
        cout << "---Fim de jogo!!!---" << endl
             << endl;
        if (jogador == false)
        {
            p1win += 1;
            cout << nome1 << " venceu." << endl
                 << endl;
        }
        else
        {
            p2win += 1;
            cout << nome2 << " venceu." << endl;
        }

        fimjogo();
    }

    else if (contador == 9)
    {
        contador = 0;
        empate += 1;
        cout << "---Fim de jogo!!!---" << endl
             << endl;
        cout << "Houve um empate." << endl
             << endl;

        fimjogo();
    }
    else
    {
        jogo();
    }
}

void fimjogo()
{
    int opcao;

    do
    {
        cout << "1 - Jogar novamente." << endl
             << "2 - Reiniciar Tabuleiro com novos jogadores e vitorias zeradas." << endl
             << "3 - Fechar programa." << endl
             << endl
             << "Sua escolha: ";

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.clear();
        cin >> opcao;

        system("cls");

        switch (opcao)
        {
        case 1:
            tabuleiro[0][0] = ' ';
            tabuleiro[1][0] = ' ';
            tabuleiro[2][0] = ' ';
            tabuleiro[0][1] = ' ';
            tabuleiro[0][2] = ' ';
            tabuleiro[1][1] = ' ';
            tabuleiro[2][2] = ' ';
            tabuleiro[1][2] = ' ';
            tabuleiro[2][1] = ' ';
            jogo();
        case 2:
            main();
        case 3:
            system("cls");
            exit(0);
        }
    } while (opcao < 1 || opcao > 3);
}
