#include "Cliente.h"

Cliente::Cliente()
{
    nomeCliente = "";
    cpf_cnpj = "";
    endereco = "";
    fone = "";
}

Cliente::Cliente(const Cliente &x)
{
    nomeCliente = x.nomeCliente;
    cpf_cnpj = x.cpf_cnpj;
    endereco = x.endereco;
    fone = x.fone;
}

Cliente::Cliente(string nome, string documento, string logradouro, string telefone)
{
    nomeCliente = nome;
    cpf_cnpj = documento;
    endereco = logradouro;
    fone = telefone;
}


bool Cliente::operator!= (Cliente x)
{
    if(x.nomeCliente != nomeCliente || x.cpf_cnpj != cpf_cnpj || x.fone != fone || x.endereco != endereco)
        return true;
    else
        return false;
}

void Cliente::operator=(Cliente &x)
{
    nomeCliente = x.nomeCliente;
    cpf_cnpj = x.cpf_cnpj;
    endereco = x.endereco;
    fone = x.fone;
}

void Cliente::escreve_arq(ofstream &doc){
    doc << nomeCliente << '$';
    doc << cpf_cnpj << '$';
    doc << endereco << '$';
    doc << fone << '$' << "\n";
}

void Cliente::le_arq(ifstream &doc){
    string cli, cli2, cli3, cli4;
	char car;
	do
    {
		doc.get(car);
		if(car!='$'){
            cli = cli + car;
		}
	}while (car != '$');
	SetnomeCliente(cli);
	do
    {
		doc.get(car);
		if(car!='$'){
            cli2 = cli2 + car;
		}
	}while (car != '$');
	Setcpf_cnpj(cli2);
	do{
        doc.get(car);
        if(car!='$'){
            cli3 = cli3 + car;
		}
	}while (car != '$');
	Setendereco(cli3);
	do{
        doc.get(car);
        if(car!='$'){
            cli4 = cli4 + car;
		}
	}
	while (car != '$');
	Setfone(cli4);
}
