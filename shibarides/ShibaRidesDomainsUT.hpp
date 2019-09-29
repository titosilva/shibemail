#ifndef SHIBARIDESDOMAINSUT_HPP_INCLUDED
#define SHIBARIDESDOMAINSUT_HPP_INCLUDED

#include "ShibaRidesDomains.hpp"
#include <vector>

namespace shibarides{

// Base class

class TUDominio{
public:
    const static int SUCCESS = 1, FAIL = 0;
    int run();
protected:
    Dominio *domain;
    int state;

    std::vector<std::string> failValues;
    std::vector<std::string> successValues;
private:

    virtual void genFailValues()=0;
    virtual void genSuccessValues()=0;

    virtual void createDomain()=0;
    void successCase();
    void failCase();
    void destroyDomain();
};

// Domains

class TUAssento : public TUDominio{
public:
    TUAssento();
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUBagagem : public TUDominio{
public:
    TUBagagem();
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUCodDeBanco : public TUDominio{
public:
    TUCodDeBanco();
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUCodDeCarona : public TUDominio{
public:
    TUCodDeCarona();
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUCodDeReserva : public TUDominio{
public:
    TUCodDeReserva();
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUCidade : public TUDominio{
public:
    TUCidade();
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUCPF : public TUDominio{
public:
    TUCPF();
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUData : public TUDominio{
public:
    TUData();
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUDuracao : public TUDominio{
public:
    TUDuracao();
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUEstado : public TUDominio{
public:
    TUEstado();
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUEmail : public TUDominio{
public:
    TUEmail();
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUNome : public TUDominio{
public:
    TUNome();
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUNumDeAgencia : public TUDominio{
public:
    TUNumDeAgencia();
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUNumDeConta : public TUDominio{
public:
    TUNumDeConta();
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUPreco : public TUDominio{
public:
    TUPreco();
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUTelefone : public TUDominio{
public:
    TUTelefone();
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUSenha : public TUDominio{
public:
    TUSenha();
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUVagas : public TUDominio{
public:
    TUVagas();
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

};

#endif // SHIBARIDESDOMAINSUT_HPP_INCLUDED
