#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include "Cliente.h"
#include "Movimentacao.h"
#include "Conta.h"
#include "banco.h"

using std::cout;
using std::cin;
using std::endl;

class Interface
{
    public:
    	//
        inline Interface(){};
        //
        Interface(const &Interface);
        //
        int Menu(&banco);
        //
        void NovoCliente(&banco);
        //
        void NovaConta (&banco);
        //
        void ExcluirCliente(&banco);
        //
        void ExcluirConta(&banco);
        //
        void Deposito(&banco);
        //
        void Saque(&banco);
        //
        void Transferencia(&banco);
        //
        void Tarifa(&banco);
        //
        void CPMF(&banco);
        //
        void Saldo(&banco);
        //
        void Extrato(&banco);
        //
        void Clientes(&banco);
        //
        void Contas(&banco);
        //
        int main();
};

#endif // INTERFACE_H

