#ifndef BANCO_H
#define BANCO_H
#include <list>
#include <iostream>
#include <fstream>
#include <string>

class Banco{
	public:
		Banco(string nomeBanco);
		void novoCliente(Cliente& Cliente);  //recebe de parametro cliente
		void novaConta(Cliente& Cliente);  //recebe de parametro cliente 
		void excluiCliente(string cpf_cnpj);  //recebe parametro ou CPF ou CNPJ
		void excluiConta(int numConta);  //recebe parametro numero conta
		void deposito(int numConta,double deposito);	//recebe de parametros numero conta, valor de deposito
		void saque(int numConta,double saque);	//recebe de parametros numero conta, valor do saque
		void transferencia(int numContaOrigem, int numContaDestino,float transfeerencia);	//recebe de parametros numero conta de origem, numero conta de destino,valor da tranferência
		void tarifa();
		void CPMF();
		void saldo(int numConta);	//recebe parametro numero da conta;
		void extratoAtual(int numConta);	//recebe parametro numero da conta;extrato do mes corrente
		void extratoEspecificoInicio(int numConta,string data);	//recebe parametro numero da conta, e a data especifica; extrato a partir da data colocada
		void extratoEspecificoPeriodo(int numConta,string dataInicio,string dataFinal);	//recebe parametro numero da conta, e a data especifica; extrato a partir do periodo colocada
		list<Banco> getClientes;	//deve listar todos os clietes ???
		list<Banco> getContass;	//deve listar todos as contas  ???
		le();
		escreve();
		
	private:
		friend class Cliente;
		friend class conta;
		string nomeBanco;
		list<string> Clientes;
		list<string> Contas;
		
};
#endif  // CONJUNTO_H

