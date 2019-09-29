#include "ShibaRidesDomainsUT.hpp"
using namespace shibarides;

int TUDominio::run(){
    this->createDomain();
    this->successCase();
    this->failCase();
    this->destroyDomain();
    return this->state;
}

void TUDominio::successCase(){
    for(unsigned int i=0; i<this->successValues.size(); i++){
        std::string val = this->successValues.at(i);
        try{
            this->domain->setValue(val);
            if(this->domain->getValue() != val) this->state = TUDominio::FAIL;
        }catch(std::exception e){
            this->state = TUDominio::FAIL;
        }
    }
}

void TUDominio::failCase(){
    for(unsigned int i=0; i<this->failValues.size(); i++){
        std::string val = this->failValues.at(i);
        try{
            this->domain->setValue(val);
            this->state = TUDominio::FAIL;
        }catch(std::exception e){
            if(this->domain->getValue()==val) this->state = TUDominio::FAIL;
        }
    }
}


void TUDominio::destroyDomain(){
    delete this->domain;
}

// Domains =============================================================

// Assento
TUAssento::TUAssento(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUAssento::createDomain(){
    this->domain = new Assento();
    this->state = TUDominio::SUCCESS;
}

void TUAssento::genFailValues(){
    this->failValues.push_back("A");
    this->failValues.push_back("B");
    this->failValues.push_back("C");
}

void TUAssento::genSuccessValues(){
    this->successValues.push_back("D");
    this->successValues.push_back("T");
}

// Bagagem
TUBagagem::TUBagagem(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUBagagem::createDomain(){
    this->domain = new Bagagem();
    this->state = TUDominio::SUCCESS;
}

void TUBagagem::genFailValues(){
    this->failValues.push_back("5");
    this->failValues.push_back("-1");
    this->failValues.push_back("ABACAXI");
}

void TUBagagem::genSuccessValues(){
    this->successValues.push_back("0");
    this->successValues.push_back("1");
    this->successValues.push_back("2");
    this->successValues.push_back("3");
    this->successValues.push_back("4");
}

// CodDeBanco
TUCodDeBanco::TUCodDeBanco(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUCodDeBanco::createDomain(){
    this->domain = new CodDeBanco();
    this->state = TUDominio::SUCCESS;
}

void TUCodDeBanco::genFailValues(){
    this->failValues.push_back("abcde");
    this->failValues.push_back("_-*#%$");
    this->failValues.push_back("10000");
    this->failValues.push_back("22");
    this->failValues.push_back("");
}

void TUCodDeBanco::genSuccessValues(){
    this->successValues.push_back("999");
    this->successValues.push_back("000");
    this->successValues.push_back("123");
    this->successValues.push_back("456");
    this->successValues.push_back("789");
    this->successValues.push_back("156");
}

// CodDeCarona
TUCodDeCarona::TUCodDeCarona(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUCodDeCarona::createDomain(){
    this->domain = new CodDeCarona();
    this->state = TUDominio::SUCCESS;
}

void TUCodDeCarona::genFailValues(){
    this->failValues.push_back("abcde");
    this->failValues.push_back("_-*#%$");
    this->failValues.push_back("10000");
    this->failValues.push_back("22");
    this->failValues.push_back("023");
    this->failValues.push_back("5");
    this->failValues.push_back("");
}

void TUCodDeCarona::genSuccessValues(){
    this->successValues.push_back("9999");
    this->successValues.push_back("0000");
    this->successValues.push_back("1234");
    this->successValues.push_back("4567");
    this->successValues.push_back("7890");
    this->successValues.push_back("1568");
}

// CodDeReserva
TUCodDeReserva::TUCodDeReserva(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUCodDeReserva::createDomain(){
    this->domain = new CodDeReserva();
    this->state = TUDominio::SUCCESS;
}

void TUCodDeReserva::genFailValues(){
    this->failValues.push_back("abcde");
    this->failValues.push_back("_-*#%$");
    this->failValues.push_back("22");
    this->failValues.push_back("023");
    this->failValues.push_back("2");
    this->failValues.push_back("0235");
    this->failValues.push_back("");
}

void TUCodDeReserva::genSuccessValues(){
    this->successValues.push_back("99999");
    this->successValues.push_back("00000");
    this->successValues.push_back("12345");
    this->successValues.push_back("45678");
    this->successValues.push_back("78901");
    this->successValues.push_back("15674");
}

// Cidade
TUCidade::TUCidade(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUCidade::createDomain(){
    this->domain = new Cidade();
    this->state = TUDominio::SUCCESS;
}

void TUCidade::genFailValues(){
    this->failValues.push_back("Distrito  Federal");
    this->failValues.push_back("-=[pl'=");
    this->failValues.push_back("     ");
    this->failValues.push_back("02,13");
    this->failValues.push_back("......... ....");
    this->failValues.push_back("aaaaaaaaaaa");
}

void TUCidade::genSuccessValues(){
    this->successValues.push_back("Porto V.");
    this->successValues.push_back("P.O.");
    this->successValues.push_back("Df");
}

// CPF
TUCPF::TUCPF(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUCPF::createDomain(){
    this->domain = new CPF();
    this->state = TUDominio::SUCCESS;
}

void TUCPF::genFailValues(){
    this->failValues.push_back("abcde");
    this->failValues.push_back("_-*#%$");
    this->failValues.push_back("07214390124");
    this->failValues.push_back("072a143b901-24");
    this->failValues.push_back("072.143.901-25");
    this->failValues.push_back("072.143.901-14");
    this->failValues.push_back("253.741.146-39");
    this->failValues.push_back("0235");
    this->failValues.push_back("");
}

void TUCPF::genSuccessValues(){
    this->successValues.push_back("072.143.901-24");
    this->successValues.push_back("111.444.777-35");
    this->successValues.push_back("253.741.146-38");
}

// Data
TUData::TUData(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUData::createDomain(){
    this->domain = new Data();
    this->state = TUDominio::SUCCESS;
}

void TUData::genFailValues(){
    this->failValues.push_back("03032000");
    this->failValues.push_back("03/03/1999");
    this->failValues.push_back("29/02/2003");
    this->failValues.push_back("30/13/2000");
    this->failValues.push_back("33/12/2019");
}

void TUData::genSuccessValues(){
    this->successValues.push_back("03/03/2000");
}

// Duracao
TUDuracao::TUDuracao(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUDuracao::createDomain(){
    this->domain = new Duracao();
    this->state = TUDominio::SUCCESS;
}

void TUDuracao::genFailValues(){
    this->failValues.push_back("asdaw");
    this->failValues.push_back("5/*+-");
    this->failValues.push_back("     ");
    this->failValues.push_back("02.13");
    this->failValues.push_back("0");
}

void TUDuracao::genSuccessValues(){
    this->successValues.push_back("48");
    this->successValues.push_back("03");
}

// Estado
TUEstado::TUEstado(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUEstado::createDomain(){
    this->domain = new Estado();
    this->state = TUDominio::SUCCESS;
}

void TUEstado::genFailValues(){
    this->failValues.push_back("qweas");
    this->failValues.push_back("5/*+-");
    this->failValues.push_back("     ");
    this->failValues.push_back("02.13");
    this->failValues.push_back("5");
}

void TUEstado::genSuccessValues(){
    this->successValues.push_back("DF");
    this->successValues.push_back("MG");
    this->successValues.push_back("AC");
}

// Email
TUEmail::TUEmail(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUEmail::createDomain(){
    this->domain = new Email();
    this->state = TUDominio::SUCCESS;
}

void TUEmail::genFailValues(){
    this->failValues.push_back("pedrofernandesspark@gmail..com");
    this->failValues.push_back("@@");
    this->failValues.push_back("  @");
    this->failValues.push_back("pedrofernandessparkmaisque20letras@gmail.com");
    this->failValues.push_back("......... ....");
    this->failValues.push_back("aaaaaaaaaaa");
}

void TUEmail::genSuccessValues(){
    this->successValues.push_back("pedrofernandesspark@gmail.com");
    this->successValues.push_back("crash@shibemail.com");
}

// Nome
TUNome::TUNome(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUNome::createDomain(){
    this->domain = new Nome();
    this->state = TUDominio::SUCCESS;
}

void TUNome::genFailValues(){
    this->failValues.push_back("spark  fernandes");
    this->failValues.push_back("-=[pl'=");
    this->failValues.push_back("     ");
    this->failValues.push_back("02,13");
    this->failValues.push_back("......... ....");
    this->failValues.push_back("aaaaaaaaaaaaaaaaaaaa");
}

void TUNome::genSuccessValues(){
    this->successValues.push_back("Spark Fernances");
    this->successValues.push_back("Spark F.");
    this->successValues.push_back("F. ");
}


// NumDeAgencia
TUNumDeAgencia::TUNumDeAgencia(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUNumDeAgencia::createDomain(){
    this->domain = new NumDeAgencia();
    this->state = TUDominio::SUCCESS;
}

void TUNumDeAgencia::genFailValues(){
    this->failValues.push_back("abc");
    this->failValues.push_back("12344");
    this->failValues.push_back("99994");
    this->failValues.push_back("1234-5");
    this->failValues.push_back("1234-9");
    this->failValues.push_back("9999-0");
    this->failValues.push_back("00000");
}

void TUNumDeAgencia::genSuccessValues(){
    this->successValues.push_back("9999-4");
    this->successValues.push_back("1234-4");
    this->successValues.push_back("0000-0");
    this->successValues.push_back("5643-2");
}

// NumDeConta
TUNumDeConta::TUNumDeConta(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUNumDeConta::createDomain(){
    this->domain = new NumDeConta();
    this->state = TUDominio::SUCCESS;
}

void TUNumDeConta::genFailValues(){
    this->failValues.push_back("abc");
    this->failValues.push_back("12344");
    this->failValues.push_back("99994");
    this->failValues.push_back("56435-2");
    this->failValues.push_back("123456-7");
    this->failValues.push_back("999999-0");
    this->failValues.push_back("00000");
}

void TUNumDeConta::genSuccessValues(){
    this->successValues.push_back("999999-6");
    this->successValues.push_back("123456-6");
    this->successValues.push_back("000000-0");
    this->successValues.push_back("564352-3");
}

// Preco
TUPreco::TUPreco(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUPreco::createDomain(){
    this->domain = new Preco();
    this->state = TUDominio::SUCCESS;
}

void TUPreco::genFailValues(){
    this->failValues.push_back("qweas");
    this->failValues.push_back("5/*+-");
    this->failValues.push_back("     ");
    this->failValues.push_back("02,13");
    this->failValues.push_back("50000");
}

void TUPreco::genSuccessValues(){
    this->successValues.push_back("90.00");
    this->successValues.push_back("5000.00");
}

// Telefone
TUTelefone::TUTelefone(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUTelefone::createDomain(){
    this->domain = new Telefone();
    this->state = TUDominio::SUCCESS;
}

void TUTelefone::genFailValues(){
this->failValues.push_back("5561912345678");
    this->failValues.push_back("ab");
    this->failValues.push_back("55-61912345678");
    this->failValues.push_back("5561-912345678");
    this->failValues.push_back("55 61 912345678");
    this->failValues.push_back("556191234567a");
    this->failValues.push_back("b561912345678");
    this->failValues.push_back("abc");
    this->failValues.push_back("00-61-912345678");
    this->failValues.push_back("55-00-912345678");
    this->failValues.push_back("55-61-000000000");
}

void TUTelefone::genSuccessValues(){
    this->successValues.push_back("55-61-912345678");
    this->successValues.push_back("10-57-982345679");
}

// Senha
TUSenha::TUSenha(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUSenha::createDomain(){
    this->domain = new Senha();
    this->state = TUDominio::SUCCESS;
}

void TUSenha::genFailValues(){
    this->failValues.push_back("1senharcommaischar");
    this->failValues.push_back("inv@");
    this->failValues.push_back("Sspark");
    this->failValues.push_back("123$");
    this->failValues.push_back("aassdd");
}

void TUSenha::genSuccessValues(){
    this->successValues.push_back("e34");
}

// Vagas
TUVagas::TUVagas(){
    this->successValues.clear();
    this->failValues.clear();
    this->genSuccessValues();
    this->genFailValues();
}

void TUVagas::createDomain(){
    this->domain = new Vagas();
    this->state = TUDominio::SUCCESS;
}

void TUVagas::genFailValues(){
    this->failValues.push_back("qweas");
    this->failValues.push_back("5/*+-");
    this->failValues.push_back("     ");
    this->failValues.push_back("02.13");
    this->failValues.push_back("5");
}

void TUVagas::genSuccessValues(){
    this->successValues.push_back("1");
    this->successValues.push_back("0");
}
