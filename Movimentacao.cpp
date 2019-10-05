#include "Movimentacao.h"

string Add0 (int num)
{
    string caixa;
    if (num < 10)
        caixa = "0" + to_string(num);
    else
        caixa = to_string(num);
    return caixa;
}


Movimentacao::Movimentacao(string sobre, char tipo, double quantia)
{
    time_t agora;
    time(&agora);
    struct tm* datahora;
    datahora = localtime(&agora);
    dataMov = Add0((datahora -> tm_year) + 1900);
    dataMov = dataMov + "/" + Add0(datahora -> tm_mon + 1) + "/" + Add0(datahora -> tm_mday);
    descricao = sobre;
    debitoCredito = tipo;
    valor = quantia;
}
