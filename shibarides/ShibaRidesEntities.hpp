#ifndef SHIBARIDESENTITIES_HPP_INCLUDED
#define SHIBARIDESENTITIES_HPP_INCLUDED
#include "ShibaRidesDomains.hpp"


namespace shibarides{

class Usuario{
public:
    // Nome methods
    void setNome(const Nome &nome){
        this->nome = nome;
    }
    Nome getNome() const{
        return this->nome;
    }

    // Telefone methods
    void setTelefone(const Telefone &telefone){
        this->telefone = telefone;
    }
    Telefone getTelefone() const{
        return this->telefone;
    }

    // Email methods
    void setEmail(const Email &email){
        this->email = email;
    }
    Email getEmail() const{
        return this->email;
    }

    // Senha methods
    void setSenha(const Senha &senha){
        this->senha = senha;
    }
    Senha getSenha() const{
        return this->senha;
    }

    // CPF methods
    void setCPF(const CPF &cpf){
        this->cpf = cpf;
    }
    CPF getCPF() const{
        return this->cpf;
    }

private:
    Nome nome;
    Telefone telefone;
    Email email;
    Senha senha;
    CPF cpf;
};

class Reserva{
public:
    // Codigo methods
    void setCodigo(const CodDeReserva &codigo){
        this->codigo = codigo;
    }
    CodDeReserva getCodigo() const{
        return this->codigo;
    }

    // Assento methods
    void setAssento(const Assento &assento){
        this->assento = assento;
    }
    Assento getAssento() const{
        return this->assento;
    }

    // Bagagem methods
    void setBagagem(const Bagagem &bagagem){
        this->bagagem = bagagem;
    }
    Bagagem getBagagem() const{
        return this->bagagem;
    }
private:
    CodDeReserva codigo;
    Assento assento;
    Bagagem bagagem;
};

class Carona{
public:
    // Codigo methods
    void setCodigo(const CodDeCarona &codigo){
        this->codigo = codigo;
    }
    CodDeCarona getCodigo() const{
        return this->codigo;
    }

    // CidadeOrigem methods
    void setCidadeOrigem(const Cidade &cidorigem){
        this->cidorigem = cidorigem;
    }
    Cidade getCidadeOrigem() const{
        return this->cidorigem;
    }

    // EstadoOrigem methods
    void setEstadoOrigem(const Estado &estorigem){
        this->estorigem = estorigem;
    }
    Estado getEstadoOrigem() const{
        return this->estorigem;
    }

    // CidadeDestino methods
    void setCidadeDestino(const Cidade &ciddestino){
        this->ciddestino = ciddestino;
    }
    Cidade getCidadeDestino() const{
        return this->ciddestino;
    }

    // EstadoDestino methods
    void setEstadoDestino(const Estado &estdestino){
        this->estdestino = estdestino;
    }
    Estado getEstadoDestino() const{
        return this->estdestino;
    }

    // Data methods
    void setData(const Data &data){
        this->data = data;
    }
    Data getData() const{
        return this->data;
    }

    // Duracao methods
    void setDuracao(const Duracao &duracao){
        this->duracao = duracao;
    }
    Duracao getDuracao() const{
        return this->duracao;
    }

    // Vagas methods
    void setVagas(const Vagas &vagas){
        this->vagas = vagas;
    }
    Vagas getVagas() const{
        return this->vagas;
    }

    // Preco methods
    void setPreco(const Preco &preco){
        this->preco = preco;
    }
    Preco getPreco() const{
        return this->preco;
    }
private:
    CodDeCarona codigo;
    Cidade cidorigem;
    Estado estorigem;
    Cidade ciddestino;
    Estado estdestino;
    Data data;
    Duracao duracao;
    Vagas vagas;
    Preco preco;
};

class Conta{
public:
    // Banco methods
    void setBanco(const CodDeBanco &banco){
        this->banco = banco;
    }
    CodDeBanco getBanco() const{
        return this->banco;
    }

    // Agencia methods
    void setAgencia(const NumDeAgencia &agencia){
        this->agencia = agencia;
    }
    NumDeAgencia getAgencia() const{
        return this->agencia;
    }

    // Conta methods
    void setConta(const NumDeConta &conta){
        this->conta = conta;
    }
    NumDeConta getConta() const{
        return this->conta;
    }
private:
    CodDeBanco banco;
    NumDeAgencia agencia;
    NumDeConta conta;
};

}

#endif // SHIBARIDESENTITIES_HPP_INCLUDED
