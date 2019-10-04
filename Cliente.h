#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>

using std::string;

class Cliente
{
        string nomeCliente;
        string cpf_cnpj;
        string endereco;
        string fone;
    public:
        Cliente();
        Cliente(string nome, string documento, string logradouro, string telefone);
        Cliente(string nome);
        Cliente(string nome, string documento);
        inline string GetnomeCliente() { return nomeCliente; }
        inline void SetnomeCliente(string val) { nomeCliente = val; }
        inline string Getcpf_cnpj() { return cpf_cnpj; }
        inline void Setcpf_cnpj(string val) { cpf_cnpj = val; }
        inline string Getendereco() { return endereco; }
        inline void Setendereco(string val) { endereco = val; }
        inline string Getfone() { return fone; }
        inline void Setfone(string val) { fone = val; }
        bool operator!= (Cliente);
};

#endif // CLIENTE_H
