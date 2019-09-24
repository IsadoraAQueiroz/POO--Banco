#ifndef INTERFACE_H
#define INTERFACE_H


class Interface
{
    public:
        Interface();
        Interface(const &Interface);
        Menu();
        NovoCliente();
        NovaConta ();
        ExcluirCliente();
        ExcluirConta();
        Deposito();
        Saque();
        Transferencia();
        Tarifa();
        CPMF();
        Saldo();
        Extrato();
        Clientes();
        Contas();
        int main();
};

#endif // INTERFACE_H
