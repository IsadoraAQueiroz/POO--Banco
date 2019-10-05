#include "Interface.h"

int obter_nConta(void)
{
	string resposta;
	cout << "Digite o numero da conta";
	cin >> resposta;
	return stoi(resposta, nullptr);
}

void imprimir_data(string &dataInv)
{
	cout << dataInv.substr(8, 9) << dataInv.substr(4, 6) << "/" << dataInv.substr(0, 3);
}

void inv_data(string &dataInv)
{
	dataInv = dataInv.substr(6, 9) + dataInv.substr(2, 4) + "/" + dataInv.substr(0, 1);
}

void imprimir_extrato(list <Movimentacao> &extrato_)
{
	std::list<Movimentacao>::iterator i = extrato_.begin();
	string data;
	while (i != extrato_.end())
	{
	    data = i->GetdataMov();
		imprimir_data(data);
        cout << "\t" << i->Getdescricao() << "\t";
		switch (i->GetdebitoCredito()){
            case 'C':
                cout << "-";
                break;
            case 'D':
                cout << "+";
                break;
		}
        cout << i->Getvalor() << endl;
		i++;
	}
}

void Imprime_Cliente_Doc(Cliente &x)
{
	cout << x.GetnomeCliente() << "\t" << x.Getcpf_cnpj() << endl;
}

bool Interface::Menu(Banco &aberto)
{
	cout << "Selecione a opcao desejada  digitando a letra correspondente:\n";
	cout << "(a) - Cadastrar novo cliente" << endl
		 << "(b) - Criar uma nova conta" << endl
		 << "(c) - Excluir um cliente" << endl
		 << "(d) - Excluir uma conta" << endl
		 << "(e) - Efetuar depósito" << endl
		 << "(f) - Efetuar saque" << endl
		 << "(g) - Efetuar transferência entre contas" << endl
		 << "(h) - Cobrar tarifa" << endl
		 << "(i) - Cobrar CPMF" << endl
		 << "(j) - Obter saldo" << endl
		 << "(k) - Obter extrato" << endl
		 << "(l) - Listar clientes" << endl
		 << "(m) - Listar contas" << endl
		 << "(*) - Sair do programa" << endl;
	char escolha;
	cin >> escolha;
	switch (escolha)
	{
	case 'a':
		NovoCliente(aberto);
		break;
	case 'A':
		NovoCliente(aberto);
		break;
	case 'b':
		NovaConta(aberto);
		break;
	case 'B':
		NovaConta(aberto);
		break;
	case 'c':
		ExcluirCliente(aberto);
		break;
	case 'C':
		ExcluirCliente(aberto);
		break;
	case 'd':
		ExcluirConta(aberto);
		break;
	case 'D':
		ExcluirConta(aberto);
		break;
	case 'e':
		Deposito(aberto);
		break;
	case 'E':
		Deposito(aberto);
		break;
	case 'f':
		Saque(aberto);
		break;
	case 'F':
		Saque(aberto);
		break;
	case 'g':
		Transferencia(aberto);
		break;
	case 'G':
		Transferencia(aberto);
		break;
	case 'h':
		Tarifa(aberto);
		break;
	case 'H':
		Tarifa(aberto);
		break;
	case 'i':
		CPMF(aberto);
		break;
	case 'I':
		CPMF(aberto);
		break;
	case 'j':
		Saldo(aberto);
		break;
	case 'J':
		Saldo(aberto);
		break;
	case 'k':
		Extrato(aberto);
		break;
	case 'K':
		Extrato(aberto);
		break;
	case 'l':
		Clientes(aberto);
		break;
	case 'L':
		Clientes(aberto);
		break;
	case 'm':
		Contas(aberto);
		break;
	case 'M':
		Contas(aberto);
		break;
	case '*':
		break;
	default:
		cout << "Nao ha nenhuma funcao no menu que conincida com o numero digitado.\nFavor digitar novamente.\n";
	}
	return !(escolha == '*');
}

void Interface::NovoCliente(banco &aberto)
{
	string nome, docum, endereco, tel;
	char resposta[100];
	cout << "Digite o nome do cliente: ";
	cin.getline(resposta, 100);
	nome = resposta;
	cout << "Digite o documento do cliente: ";
	cin.getline(resposta, 100);
	docum = resposta;
	cout << "Digite o endereco do cliente: ";
	cin.getline(resposta, 100);
	endereco = resposta;
	cout << "Digite o telefone do cliente: ";
	cin.getline(resposta, 100);
	tel = resposta;
	Cliente novo(nome, docum, endereco, tel);
	aberto.novoCliente(novo);
}

void Interface::NovaConta(banco &aberto)
{
	list<Cliente> busca;
	string resposta;
	busca = aberto.getClientes();
	std::list<Cliente>::iterator i;
	cout << "Digite o CPF/CNPJ do cliente: ";
	cin >> resposta;
	for (i = busca.begin(); i->Getcpf_cnpj() != resposta || i != busca.end(); i++)
	{
		i++;
	}
	if (i != busca.end())
	{
		aberto.novaConta(*i);
		cout << "Conta criada com sucesso";
	}
	else
		cout << "Nao foi encontrado cliente com CPF/CNPJ digitado." << endl
			 << "E necessario que o cliente seja antes inserido em nosso sistema." << endl
			 << "Retornando ao menu principal.\n"
			 << endl;
}

void Interface::ExcluirCliente(banco &aberto)
{
	list<Cliente> busca;
	list<conta> busca2;
	string resposta;
	busca = aberto.getClientes();
	busca2 = aberto.getContas();
	std::list<Cliente>::iterator i = busca.begin();
	std::list<conta>::iterator j = busca2.begin();
	cout << "Digite o CPF/CNPJ do cliente: ";
	cin >> resposta;
	while (i->Getcpf_cnpj() != resposta || i != busca.end())
		i++;
	if (i != busca.end())
	{
		while (j->getCliente() != *i || j != busca2.end())
			j++;
		if (j == busca2.end())
		{
			aberto.excluiCliente(resposta);
			cout << "Cliente excluido com sucesso\n";
		}
		else
			cout << "Cliente nao pode ser excluido por possuir conta. E necessario excluir todas as contas primeiro.";
	}
	else
		cout << "Cliente nao se encontra no banco de dados.\n";
}

void Interface::ExcluirConta(banco &aberto)
{
	cout << "a ser excluida: " aberto.excluiConta(obter_nConta());
}

void Interface::Deposito(banco &aberto)
{
	cout << "a ser depositada: " nConta = obter_nConta;
	cout << "Digite o valor do deposito (somente numero): R$ ";
	cin >> valor;
	aberto.deposito(nConta, valor);
}

void Interface::Saque(banco &aberto)
{
	int nConta;
	double valor;
	cout << "a ser sacada: " nConta = obter_nConta;
	cout << "Digite o valor do saque (somente numero): R$  ";
	cin >> valor;
	aberto.saque(nConta, valor);
}

void Interface::Transferencia(banco &aberto)
{
	int remetente, destinatario;
	double valor;
	cout << "a ser debitada: ";
	remetente = obter_nConta();
	cout << "a ser creditada: ";
	destinatario = obter_nConta();
	cout << "Digite o valor da transferencia (somente numero): R$  ";
	cin >> valor;
	aberto.transferencia(remetente, destinatario, valor);
}

void Interface::Tarifa(banco &aberto)
{
	aberto.tarifa()
}

void Interface::CPMF(banco &aberto)
{
	aberto.CPMF();
}

void Interface::Saldo(banco &aberto)
{
	double saldo_;
	saldo_ = aberto.saldo(obter_nConta());
	cout << "O saldo da conta é de : R$ " << saldo_ << endl;
}

void Interface::Extrato(banco &aberto)
{

	int escolha, nConta;
	nConta = obter_nConta();
	list<Movimentacao> extrato_;
	cout << "Escolha as opcoes de periodo para exibicao do extrato: \n"
		 << "(1) Entre duas datas\t(2) A partir de uma data\n(3) Do mes corrente\t(4) Sair do Extrato" << endl;
	cin >> escolha;
	switch (escolha)
	{
	case 1:
		string inicio, fim;
		cout << "Digite a data inicial(formato dd/mm/aaaa): " cin >> inicio;
		cout << "Digite a data final(formato dd/mm/aaaa): " cin >> fim;
		inv_data(inicio);
		inv_data(fim);
		aberto.extratoEspecifico(nConta, inicio, fim);
		break;
	case 2:
		string inicio;
		cout << "Digite a data inicial(formato dd/mm/aaaa): " cin >> inicio;
		inv_data(inicio);
		aberto.extratoInicial(nConta, inicio);
		break;
	case 3:
		aberto.extratoAtual(nConta);
		break;
	case 4:
		break;
	default:
		cout << "Voce nao digitou um numero que corresponda ao menu. Digite novamente." << endl;
		Extrato(aberto);
		break;
	}

	void Interface::Clientes(Banco & aberto)
	{
		list<Cliente> lista_clientes;
		lista_clientes = aberto.getClietes();
		std::list<Cliente>::iterator i = lista_clientes.begin();
		while (i != lista_clientes.end())
		{
			Imprime_Cliente_Doc(*i);
			cout << "\tTel: " << i->Getfone() << endl
				 << i->Getendereco() << endl;
		}
	}

	void Interface::Contas(Banco & aberto)
	{
		list<conta> lista_contas;
		lista_contas = aberto.getContas();
		std::list<conta>::iterator i = lista_contas.begin();
		while (i != lista_contas.end())
		{
			Imprime_Cliente_Doc(i->getCliente());
			cout << "Conta: " << i->getNumConta() << "\t"
				 << "Saldo: " << i->getSaldo()
		}
	}

	int Interface::main()
	{
		size_t antes, dpois, npos = -1;
		string nome;
		antes = diretorio.find_last_of("\\");
		dpois = diretorio.find_last_of(".");
		nome = diretorio.substr(antes + 1, dpois - 1);
		Banco aberto(nome);
		aberto.le(diretorio);
		cout << "Bem vindo a Interface gerenciadora de Banco! Para comecar, sera exposto um menu\n";
		while (Menu(aberto))
			cout << "A operacao foi finalizada. O menu sera apresentado novamente. Para sair do programa, selecione a opcao "
					"sair do programa"
					" no menu. \n";
		aberto.escreve(diretorio);
		return 0;
	}
