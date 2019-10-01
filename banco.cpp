#include "banco.h"

using namespace std;

Banco::Banco(){
	nomeBanco=" ";
}

void Banco::novoCliente(Cliente& cliente){
	Clientes.push_front(cliente)
}
void Banco::novaConta(Cliente& cliente){
	conta novaconta(cliente);
	Conta.push_front(novaconta);
	
}

//Pré-condição: o cliente não pode ter uma conta
void Banco::excluiCliente(string cpf_cnpj){
}

void Banco::excluiConta(int numConta){
	auto it = find_if(Contas.begin(), Contas.end(), [&numConta](const string& obj) {});;
	if (it != Contas.end())
	{
		Contas.erase(it);
	}
}

void Banco::deposito(int numConta,float deposito){
}

void Banco::saque(int numConta,float saque){
}

void Banco::extratoAtual(int numConta);{
}

void Banco::extratoEspecifico(int numConta,int data){
}

//A descobrir
//	list<Banco> getClientes;	//deve listar todos os clietes ???
//	list<Banco> getContass;	//deve listar todos as contas  ???
