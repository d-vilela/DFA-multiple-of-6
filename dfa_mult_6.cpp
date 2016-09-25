/*
 * Atividade: implementação de um autômato finito determinístico que valide a entrada de uma string binária em relação
 * ao fato de ser múltipla de 6, ou não.
 * 
 * Código desenvolvido por: Gabriel Dias e Naiara Pedrozo,
 * Disciplina: Linguagens Formais e Autômatos,
 * Prof.: Ms. Anibal Santos Jukemura
*/


#include <windows.h>
#include <stdlib.h>
#include <clocale>
#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

const int DIM_COLUNA = 3;
const int DIM_LINHA = 5;

bool verificarMult6(const int tabela[][DIM_COLUNA], std::string);
std::string decimalBinario(int);

using namespace std;

int main()
{
    std::setlocale(LC_ALL, "ptb");
    std::string entrada;
    int entradaDecimal;
    std::string opc = "";
    int matriz[DIM_LINHA][DIM_COLUNA] =
    {

        {0, 0, 1},
        {1, 2, 3},
        {2, 4, 2},
        {3, 0, 1},
        {4, 4, 3}

    };

    std::cout<<"Programa: Validar strings binarias com caract. de multplicidade por 6";
    std::cout<<"\n";
    std::cout<<"\n";
    std::cout<<"Digite 'fim' para encerrar o programa!";
    std::cout<<"\n";
    Sleep(1700);
    system("cls");

    while(opc != "fim")
    {
        if(opc == "continue")
        {
            system("cls");
            std::cout<<"Continuando com o programa!";
            std::cout<<"\n";
            Sleep(700);
            system("cls");
        }
        std::cout << "Prefere por binario ou decimal ? ";
        std::cin >> opc;
        Sleep(1000);
        if(opc == "binario")
        {
            system("cls");
            std::cout << "Entre com a string no formato binario: ";
            std::cin >> entrada;
        }
        else
        {
            if(opc == "decimal")
            {
                system("cls");
                std::cout << "Entre com a string no formato decimal: ";
                std::cin >> entradaDecimal;

                system("cls");

                std::cout<<"Numero no formato decimal informado: " << entradaDecimal;
                std::cout<<"\n";
                entrada = decimalBinario(entradaDecimal);
                std::cout<<"Equivalente no formato binario: " << entrada;
                std::cout<<"\n";
            }
            else
            {
                system("cls");
                std::cout<<"Opçao invalida! Informe novamente!";
                std::cout<<"\n";
            }
        }


        //Estados: matriz[n][0]
        //Valores possíveis: matriz[n+1][1] e matriz[n+1][2]
        std::cout<<" ----- TABELA DA FUNCAO PROGRAMA DO AUTOMATO ----- ";
        std::cout<<"\n";
        std::cout << setfill('-') << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << endl;
        std::cout << setfill(' ') << setw(1) << "|" << setw(15) << left << "    Estado" << setw(1) << "|" << setw(15) << left << "   Entrada: 0" << setw(1) << "|"  << setw(15) << left << "   Entrada: 1" << setw(1) << "|" << endl;
        std::cout << setfill('-') << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << endl;
        std::cout << setfill(' ') << setw(1) << "|" << setw(15) << left << "      Q0" << setw(1) << "|" << setw(15) << left << "      Q0" << setw(1) << "|"  << setw(15) << left << "      Q1" << setw(1) << "|" << endl;

        std::cout << setfill('-') << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << endl;

        std::cout << setfill(' ') << setw(1) << "|" << setw(15) << left << "      Q1" << setw(1) << "|" << setw(15) << left << "      Q2" << setw(1) << "|"  << setw(15) << left << "      Q3" << setw(1) << "|" << endl;
        std::cout << setfill('-') << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << endl;

         std::cout << setfill(' ') << setw(1) << "|" << setw(15) << left << "      Q2" << setw(1) << "|" << setw(15) << left << "      Q4" << setw(1) << "|"  << setw(15) << left << "      Q2" << setw(1) << "|" << endl;

        std::cout << setfill('-') << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << endl;

         std::cout << setfill(' ') << setw(1) << "|" << setw(15) << left << "      Q3" << setw(1) << "|" << setw(15) << left << "      Q0" << setw(1) << "|"  << setw(15) << left << "      Q1" << setw(1) << "|" << endl;

        std::cout << setfill('-') << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << endl;

         std::cout << setfill(' ') << setw(1) << "|" << setw(15) << left << "      Q4" << setw(1) << "|" << setw(15) << left << "      Q4" << setw(1) << "|"  << setw(15) << left << "      Q3" << setw(1) << "|" << endl;

        std::cout << setfill('-') << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+" << endl;

        std::cout<<"\n";
        if(verificarMult6(matriz, entrada))
        {
            std::cout<<"\n";
            std::cout<<"\n";
            std::cout<<"Multiplo de 6! \n";
        }
        else
        {
            std::cout<<"\n";
            std::cout<<"\n";
            std::cout<<"Nao multiplo de 6! \n";
        }

        std::cout<<"\n";
        std::cout<<"\n";

        std::cout << "Deseja encerrar o programa? Informe 'fim' caso deseje ou informe 'continue':  ";
        std::cin >> opc;
        std::cout<<"\n";
        Sleep(100);
        system("cls");
    }
}

bool verificarMult6(const int tabela[][DIM_COLUNA], std::string palavra)
{
    //Varia de 0 a 4
    //Me informa a linha atual
    int estado_q = 0;

    //Percorrer as pos. da minha string
    int index = 0;
    int coluna = 1;

    std::cout<<"\n";
    std::cout<<"Estado atual: Q0";
    std::cout<<"\n";

    std::cout<<"------------------------------------------------";

    while(index < palavra.length())
    {
        int estado_anterior = estado_q;
        if(palavra[index] == '0')
        {
            estado_q = tabela[estado_q][coluna];
        }
        else
        {
            estado_q = tabela[estado_q][coluna + 1];
        }
        std::cout<<"\n|Troca de estados: Q"<<estado_anterior << " -> Q"<< estado_q << " | Caractere lido: " << palavra[index] << "|\n";
        index ++;
        std::cout<<"------------------------------------------------";
    }

    if(estado_q  == 0)
        return true;
    return false;
}

std::string decimalBinario(int entrada)
{
    long long remainder;
    long long binary = 0;
    long long i = 1;

    while(entrada != 0) {
        remainder = entrada % 2;
        entrada = entrada /2;
        binary= binary + (remainder*i);
        i = i*10;
    }

    std::cout<<"OLHA O BINARIO AQUI"  << binary;

    std::ostringstream ostr;
    ostr << binary;
    std::string theNumberString = ostr.str();

    return theNumberString;
}
