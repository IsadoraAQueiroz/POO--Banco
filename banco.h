#ifndef BANCO_H
#define BANCO_H
#include <list>
#include <iostream>
#include <fstream>
#include <string>

using std::string;

class Banco{
	public:
		Banco(string nomeBanco);
		void novoCliente(list<string> &Clientes;);  //recebe de parametro cliente que é uma lista
		void novaConta(list<string> &Contas);  //recebe de parametro cliente que é uma lista
		void excluiCliente(string cpf_cnpj);  //recebe parametro ou CPF ou CNPJ
		void excluiConta(int numConta);  //recebe parametro numero conta
		void deposito(int numConta,float deposito);	//recebe de parametros numero conta, valor de deposito
		void saque(int numConta,float saque);	//recebe de parametros numero conta, valor do saque
		void transferencia(int numContaOrigem, int numContaDestino,float transfeerencia);	//recebe de parametros numero conta de origem, numero conta de destino,valor da tranferência
		void tarifa();
		void CPMF();
		void saldo(int numConta);	//recebe parametro numero da conta;
		void extratoAtual(int numConta);	//recebe parametro numero da conta;extrato do mes corrente
		void extratoEspecifico(int numConta,int data);	//recebe parametro numero da conta, e a data especifica; extrato a partir da data colocada
		list<Banco> getClientes;	//deve listar todos os clietes ???
		list<Banco> getContass;	//deve listar todos as contas  ???
		le();
		escreve();
		
	private:
		string nomeBanco;
		list<string> Clientes;
		list<string> Contas;
		
};
#endif  // CONJUNTO_H

