#include "ShibaRidesEntitiesUT.hpp"
using namespace shibarides;

// Base Class

TUEntidade::TUEntidade(){
    this->state = TUEntidade::SUCCESS;
}

int TUEntidade::run(){
    this->createEntity();
    this->testMethods();
    this->destroyEntity();
    return this->state;
}

// Usuario
void TUUsuario::createEntity(){
    this->usuario = new Usuario();
}

void TUUsuario::testMethods(){
    Nome nome;
    Telefone telefone;
    Email email;
    Senha senha;
    CPF cpf;

    // Set a valid name to nome
    nome.setValue("Teste");
    telefone.setValue("55-61-912345678");
    email.setValue("crash@gmail.com");
    senha.setValue("e34");
    cpf.setValue("072.143.901-24");

    try{
        this->usuario->setNome(nome);

        if(this->usuario->getNome().getValue()!=nome.getValue()) this->state = TUEntidade::FAIL;
    }catch(std::exception e){
        // The entities must not throw exceptions
        // Then, if one throws an exception, the test
        // has failed.
        this->state = TUEntidade::FAIL;
    }

    try{
        this->usuario->setTelefone(telefone);

        if(this->usuario->getTelefone().getValue()!=telefone.getValue()) this->state = TUEntidade::FAIL;
    }catch(std::exception e){
        // The entities must not throw exceptions
        // Then, if one throws an exception, the test
        // has failed.
        this->state = TUEntidade::FAIL;
    }

    try{
        this->usuario->setEmail(email);

        if(this->usuario->getEmail().getValue()!=email.getValue()) this->state = TUEntidade::FAIL;
    }catch(std::exception e){
        // The entities must not throw exceptions
        // Then, if one throws an exception, the test
        // has failed.
        this->state = TUEntidade::FAIL;
    }

    try{
        this->usuario->setSenha(senha);

        if(this->usuario->getSenha().getValue()!=senha.getValue()) this->state = TUEntidade::FAIL;
    }catch(std::exception e){
        // The entities must not throw exceptions
        // Then, if one throws an exception, the test
        // has failed.
        this->state = TUEntidade::FAIL;
    }

    try{
        this->usuario->setCPF(cpf);

        if(this->usuario->getCPF().getValue()!=cpf.getValue()) this->state = TUEntidade::FAIL;
    }catch(std::exception e){
        // The entities must not throw exceptions
        // Then, if one throws an exception, the test
        // has failed.
        this->state = TUEntidade::FAIL;
    }
}

void TUUsuario::destroyEntity(){
    delete this->usuario;
}

// Reserva
void TUReserva::createEntity(){
    this->reserva = new Reserva();
}

void TUReserva::testMethods(){
    CodDeReserva codigo;
    Assento assento;
    Bagagem bagagem;

    codigo.setValue("99999");
    assento.setValue("D");
    bagagem.setValue("0");

    try{
        this->reserva->setCodigo(codigo);

        if(this->reserva->getCodigo().getValue()!=codigo.getValue()) this->state = TUEntidade::FAIL;
    }catch(std::exception e){
        // The entities must not throw exceptions
        // Then, if one throws an exception, the test
        // has failed.
        this->state = TUEntidade::FAIL;
    }

    try{
        this->reserva->setAssento(assento);

        if(this->reserva->getAssento().getValue()!=assento.getValue()) this->state = TUEntidade::FAIL;
    }catch(std::exception e){
        // The entities must not throw exceptions
        // Then, if one throws an exception, the test
        // has failed.
        this->state = TUEntidade::FAIL;
    }

    try{
        this->reserva->setBagagem(bagagem);

        if(this->reserva->getBagagem().getValue()!=bagagem.getValue()) this->state = TUEntidade::FAIL;
    }catch(std::exception e){
        // The entities must not throw exceptions
        // Then, if one throws an exception, the test
        // has failed.
        this->state = TUEntidade::FAIL;
    }


}

void TUReserva::destroyEntity(){
    delete this->reserva;
}

// Carona
void TUCarona::createEntity(){
    this->carona = new Carona();
}

void TUCarona::testMethods(){
    CodDeCarona codigo;
    Cidade cidorigem;
    Estado estorigem;
    Cidade ciddestino;
    Estado estdestino;
    Data data;
    Duracao duracao;
    Vagas vagas;
    Preco preco;

    // Set a valid name to nome
    codigo.setValue("9999");
    cidorigem.setValue("P.O.");
    estorigem.setValue("MG");
    ciddestino.setValue("Df");
    estdestino.setValue("DF");
    data.setValue("06/06/2006");
    duracao.setValue("06");
    vagas.setValue("1");
    preco.setValue("400.40");

    try{
        this->carona->setCodigo(codigo);

        if(this->carona->getCodigo().getValue()!=codigo.getValue()) this->state = TUEntidade::FAIL;
    }catch(std::exception e){
        // The entities must not throw exceptions
        // Then, if one throws an exception, the test
        // has failed.
        this->state = TUEntidade::FAIL;
    }

    try{
        this->carona->setCidadeOrigem(cidorigem);

        if(this->carona->getCidadeOrigem().getValue()!=cidorigem.getValue()) this->state = TUEntidade::FAIL;
    }catch(std::exception e){
        // The entities must not throw exceptions
        // Then, if one throws an exception, the test
        // has failed.
        this->state = TUEntidade::FAIL;
    }

    try{
        this->carona->setEstadoOrigem(estorigem);

        if(this->carona->getEstadoOrigem().getValue()!=estorigem.getValue()) this->state = TUEntidade::FAIL;
    }catch(std::exception e){
        // The entities must not throw exceptions
        // Then, if one throws an exception, the test
        // has failed.
        this->state = TUEntidade::FAIL;
    }

    try{
        this->carona->setCidadeDestino(ciddestino);

        if(this->carona->getCidadeDestino().getValue()!=ciddestino.getValue()) this->state = TUEntidade::FAIL;
    }catch(std::exception e){
        // The entities must not throw exceptions
        // Then, if one throws an exception, the test
        // has failed.
        this->state = TUEntidade::FAIL;
    }

    try{
        this->carona->setEstadoDestino(estdestino);

        if(this->carona->getEstadoDestino().getValue()!=estdestino.getValue()) this->state = TUEntidade::FAIL;
    }catch(std::exception e){
        // The entities must not throw exceptions
        // Then, if one throws an exception, the test
        // has failed.
        this->state = TUEntidade::FAIL;
    }

    try{
        this->carona->setData(data);

        if(this->carona->getData().getValue()!=data.getValue()) this->state = TUEntidade::FAIL;
    }catch(std::exception e){
        // The entities must not throw exceptions
        // Then, if one throws an exception, the test
        // has failed.
        this->state = TUEntidade::FAIL;
    }

    try{
        this->carona->setDuracao(duracao);

        if(this->carona->getDuracao().getValue()!=duracao.getValue()) this->state = TUEntidade::FAIL;
    }catch(std::exception e){
        // The entities must not throw exceptions
        // Then, if one throws an exception, the test
        // has failed.
        this->state = TUEntidade::FAIL;
    }

    try{
        this->carona->setVagas(vagas);

        if(this->carona->getVagas().getValue()!=vagas.getValue()) this->state = TUEntidade::FAIL;
    }catch(std::exception e){
        // The entities must not throw exceptions
        // Then, if one throws an exception, the test
        // has failed.
        this->state = TUEntidade::FAIL;
    }

    try{
        this->carona->setPreco(preco);

        if(this->carona->getPreco().getValue()!=preco.getValue()) this->state = TUEntidade::FAIL;
    }catch(std::exception e){
        // The entities must not throw exceptions
        // Then, if one throws an exception, the test
        // has failed.
        this->state = TUEntidade::FAIL;
    }

}

void TUCarona::destroyEntity(){
    delete this->carona;
}

// Conta
void TUConta::createEntity(){
    this->conta = new Conta();
}

void TUConta::testMethods(){
    CodDeBanco banco;
    NumDeAgencia agencia;
    NumDeConta conta;

    banco.setValue("999");
    agencia.setValue("9999-4");
    conta.setValue("999999-6");

    try{
        this->conta->setBanco(banco);

        if(this->conta->getBanco().getValue()!=banco.getValue()) this->state = TUEntidade::FAIL;
    }catch(std::exception e){
        // The entities must not throw exceptions
        // Then, if one throws an exception, the test
        // has failed.
        this->state = TUEntidade::FAIL;
    }

    try{
        this->conta->setAgencia(agencia);

        if(this->conta->getAgencia().getValue()!=agencia.getValue()) this->state = TUEntidade::FAIL;
    }catch(std::exception e){
        // The entities must not throw exceptions
        // Then, if one throws an exception, the test
        // has failed.
        this->state = TUEntidade::FAIL;
    }

    try{
        this->conta->setConta(conta);

        if(this->conta->getConta().getValue()!=conta.getValue()) this->state = TUEntidade::FAIL;
    }catch(std::exception e){
        // The entities must not throw exceptions
        // Then, if one throws an exception, the test
        // has failed.
        this->state = TUEntidade::FAIL;
    }


}

void TUConta::destroyEntity(){
    delete this->conta;
}



