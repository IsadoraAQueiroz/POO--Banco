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
    dataMov = dataMov + "/" + Add0(datahora -> tm_mon+1) + "/" + Add0(datahora -> tm_mday);
    descricao = sobre;
    debitoCredito = tipo;
    valor = quantia;
}

Movimentacao::Movimentacao()
{
    dataMov = "";
    descricao = "";
    valor = 0;
    debitoCredito = '0';
}

void Movimentacao::escreve_arquivo(ofstream &doc){
    doc << dataMov << '#';
    doc << descricao << '#';
    doc << debitoCredito << '#';
    doc << valor ;
}

void Movimentacao::le_arquivo(ifstream &doc){
    string mov1, mov2;
    char car, tipo;
    double val;
    do
    {
        doc.get(car);
        if(car!='#'){
            mov1 = mov1 + car;
        }
    }while (car != '#');
    dataMov = mov1;
    mov1.erase();
    do
    {
        doc.get(car);
        if(car!='#'){
            mov2 = mov2 + car;
        }
    }while(car!='#');
    descricao = mov2;
    mov2.erase();
    doc.get(car);
    if(car!='#')
        tipo = car;
    doc.get(car);
    debitoCredito = tipo;
    doc >> val;
    valor = val;
}
