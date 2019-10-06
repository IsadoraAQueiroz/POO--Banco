#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H
#include <ctime>
#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::to_string;
using std::ofstream;
using std::ifstream;


class Movimentacao
{
	//data no formato aaaa/mm/dd
        string dataMov;
        string descricao;
        char debitoCredito;
        double valor;
    public:
        // Construtor com argumentos contendo descrição, tipo ('d' ou 'c') e o valor;
        Movimentacao(string, char, double);
        Movimentacao();
        //retorna data e hora da transação em formato aaaa/mm/dd
        inline string GetdataMov() { return dataMov; }
        //retorna a descrição da movimentação
        inline string Getdescricao() { return descricao; }
        //retorna o tipo da movimentação ('c' para credito e 'd' para debito)
        inline char GetdebitoCredito() { return debitoCredito; }
        //retorna o valor da movimentação
        inline double Getvalor() { return valor; }
        void escreve_arquivo(ofstream &doc);
        void le_arquivo(ifstream &doc);
};

#endif // MOVIMENTACAO_H
