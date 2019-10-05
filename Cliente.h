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
        //construtor padrão da classe
        Cliente();
        //inicialiiza um objeto cliente definindo os 4 atributos
        Cliente(string nome, string documento, string logradouro,string fone); 
        //permite acesso ao atributo nome
        inline string GetnomeCliente() { return nomeCliente; }
        //altera atributo nome
        inline void SetnomeCliente(string val) { nomeCliente = val; }
        //permite acesso ao atributo cpf/cnpj
        inline string Getcpf_cnpj() { return cpf_cnpj; }
        //altera atriubto cpf/cnpj
        inline void Setcpf_cnpj(string val) { cpf_cnpj = val; }
        //permite acesso ao atributo endereço
        inline string Getendereco() { return endereco; }
        //altera atributo endereço
        inline void Setendereco(string val) { endereco = val; }
        //permite acesso ao atributo fone
        inline string Getfone() { return fone; }
        //altera atributo fone
        inline void Setfone(string val) { fone = val; }
        //retorna se o cliente corrente é igual ao parâmetro
        bool operator!= (Cliente);
};

#endif // CLIENTE_H
