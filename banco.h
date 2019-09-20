#ifndef BANCO_H
#define BANCO_H

#include <string>

using std::string;

class Banco{
	public:
		nomeBanco(string nome);
		novoCliente();  //recebe de parametro cliente que é uma lista
		novaConta();  //recebe de parametro cliente que é uma lista
		excluiCliente();  //recebe parametro ou CPF ou CNPJ
		excluiConta();  //recebe parametro numero conta
		deposito();	//recebe de parametros numero conta, valor de deposito
		saque();	//recebe de parametros numero conta, valor do saque
		transferencia();	//recebe de parametros numero conta de origem, numero conta de destino,valor da tranferência
		tarifa();
		CPMF();
		saldo();	//recebe parametro numero da conta;
		extratoAtual();	//recebe parametro numero da conta;extrato do mes corrente
		extratoEspecifico();	////recebe parametro numero da conta, e a data especifica;extrato a partir da data colocada
		clientes();	//deve listar todos os clietes
		contas();	//deve listar todos as contas
		grava();	//vai gravar todos os dados em um arquivo
		le();	//vai ler todos os dados de um arquivo
		
	private:
		string nomeBanco;
		string* clientes;
		string* contas;
		
};
#endif  // CONJUNTO_H
