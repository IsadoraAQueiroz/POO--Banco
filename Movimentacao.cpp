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
    dataMov = localtime(&agora);
    descricao = sobre;
    debitoCredito = tipo;
    valor = quantia;
}

string Movimentacao::hora()
{
    string Hora;
    Hora = Add0(dataMov -> tm_hour) + ":" + Add0(dataMov -> tm_min);
    Hora = Hora + ":" + Add0(dataMov -> tm_sec);
    return Hora;
}

string Movimentacao::data()
{
    string Data;
    Data = Add0(dataMov -> tm_mday) + "/" + Add0(dataMov -> tm_mon) + "/";
    Data = Data + Add0(dataMov -> tm_year + 1900);
    return Data;
}
