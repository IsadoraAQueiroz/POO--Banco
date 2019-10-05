#ifndef BANCO_H
#define BANCO_H
#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include "conta.h"
using std::string;
using std::to_string;

class Banco{
	public:
		Banco(string nomebanco);
		void novoCliente(Cliente& cliente);  //recebe de parametro cliente
		void novaConta(Cliente& cliente);  //recebe de parametro cliente
		void excluiCliente(string cpf_cnpj);  //recebe parametro ou CPF ou CNPJ
		void excluiConta(int numConta);  //recebe parametro numero conta
		void deposito(int numConta,float deposito);	//recebe de parametros numero conta, valor de deposito
		void saque(int numConta,float saque);	//recebe de parametros numero conta, valor do saque
		void transferencia(int numContaOrigem, int numContaDestino,float transfeerencia);	//recebe de parametros numero conta de origem, numero conta de destino,valor da tranfer�ncia
		void tarifa();
		void CPMF();
		double saldo(int numConta);	//recebe parametro numero da conta;
		void extratoAtual(int numConta);	//recebe parametro numero da conta;extrato do mes corrente
		void extratoEspecifico(int numConta,int data);	//recebe parametro numero da conta, e a data especifica; extrato a partir da data colocada
		list<Cliente> getClientes;	//deve listar todos os clietes ???
		list<conta> getContass;	//deve listar todos as contas  ???
		//void le();
		void escreve(string x);

	private:
		friend class Cliente;
		friend class conta;
		string nomeBanco;
		list<Cliente> Clientes;
		list<conta> Contas;

};
#endif  // CONJUNTO_H

