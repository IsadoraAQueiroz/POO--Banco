#include "banco.h"

using namespace std;

string Add0 (int num)
{
    string caixa;
    if (num < 10)
        caixa = "0" + to_string(num);
    else
        caixa = to_string(num);
    return caixa;
}



Banco::Banco(string nomebanco){
	nomeBanco = nomebanco;
}

void Banco::novoCliente(Cliente& cliente){
	Clientes.push_back(cliente);
}
void Banco::novaConta(Cliente& cliente){
	conta novaConta(cliente);
	Contas.push_back(novaConta);
}

//Pr�-condi��o: o cliente n�o pode ter uma conta
void Banco::excluiCliente(string cpf_cnpj){
}
/* VERIFICAR FIND_IF
void Banco::excluiConta(int numConta){
	auto it = find_if(Contas.begin(), Contas.end(), [&numConta](const string& obj) {});;
	if (it != Contas.end())
	{
		Contas.erase(it);
	}
}*/

void Banco::deposito(int numConta,float deposito){
}

void Banco::saque(int numConta,float saque){
	for(auto it1:Contas){
        if(it1.getNumConta()==numConta){
            it1.debita(saque, "Saque");
            break;
        }
	}
}

void Banco::transferencia(int numContaOrigem, int numContaDestino, float transferencia){
	for(auto it1:Contas){
        if(it1.getNumConta()==numContaOrigem){
            for(auto it2:Contas){
                if(it2.getNumConta()==numContaDestino){
                    it1.debita(transferencia, "Transferência para conta " + to_string(numContaDestino));
                    it2.credita(transferencia, "Transferência da conta " + to_string(numContaOrigem));
                }
            }
        }
    }
}

void Banco::tarifa(){
	for (auto it : Contas){
		it.debita(15.00, "Cobranca de tarifa");
	}
}
void Banco::CPMF(){
    time_t agora;
    string hj,antes;
    time(&agora);
    struct tm* datahora;
    datahora = localtime(&agora);
    hj = Add0((datahora -> tm_year) + 1900);
    hj = hj + "/" + Add0(datahora -> tm_mon+1) + "/" + Add0(datahora -> tm_mday);
    agora = agora - 604800;
    datahora = localtime(&agora);
    antes = Add0((datahora -> tm_year) + 1900);
    antes = antes + "/" + Add0(datahora -> tm_mon+1) + "/" + Add0(datahora -> tm_mday);
	for (auto it : Contas){
		list<Movimentacao> extrato = it.extratoDias(antes, hj);
		double soma = 0.0;
		for (auto it2 : extrato){
			soma = soma + it2.Getvalor();
		}
		double cpmf = soma * 0.0038;
		it.debita(cpmf, "Cobrança de CPMF");
	}
}

double Banco::saldo(int numConta){
    double s = -1;
	for(auto it1:Contas){
        if(it1.getNumConta()==numConta){
            s = it1.getSaldo();
            break;
        }
	}return s;
}
void Banco::extratoAtual(int numConta){
}
void Banco::extratoEspecifico(int numConta,int data){
}
/*
void Banco::le(string x)
{
	ifstream dados;
	dados.open(x);
	if (dados.is_open()){
		string cli;
		cliente atual;
		char car;
		while (car != '$'){
			car << dados;
			cli = cli + car;
		}
		atual.SetnomeCliente(cli);
		cli.clear();
		while (car != '$'){
			car << dados;
			cli = cli + car;
		}
		atual.Setcpf_cnpj(cli);
		cli.clear();
		while (car != '$'){
			car << dados;
			cli = cli + car;
		}
		atual.Setendereco(cli);
		cli.clear();
		while (car != '$'){
			car << dados;
			cli = cli + car;
		}
		atual.Setfone(cli);
		cli.clear();
		novoCliente(atual);
		novaConta(atual);
	}else{
		cout << "Falha ao abrir arquivo na leitura" << endl;
	}
	//finalizar a leitura de arquivo
	dados.close();
}*/
void Banco::escreve(string x){
	ofstream dados;
	dados.open(x);
	if (dados.is_open()){
		for (auto i : Contas){
			dados << i.getCliente() << ";" << endl;
			list<Movimentacao> movi = i.getMovimentacoes();
			for (auto j : movi){
				dados << j << endl;
			}
			dados << "&" << endl;
		}
	}else{
		cout << "Falha ao abrir arquivo na escrita" << endl;
	}
	dados.close();
}

//A descobrir
//	list<Banco> getClientes;	//deve listar todos os clietes ???
//	list<Banco> getContass;	//deve listar todos as contas  ???
