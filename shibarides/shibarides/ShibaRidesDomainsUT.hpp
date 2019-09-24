#ifndef SHIBARIDESDOMAINSUT_HPP_INCLUDED
#define SHIBARIDESDOMAINSUT_HPP_INCLUDED

#include "ShibaRidesDomains.hpp"
#include <vector>

namespace shibarides{

class TUDominio{
public:
    TUDominio();
    const static int SUCCESS = 1, FAIL = 0;
    int run();
protected:
    Dominio *domain;
    int state;

    std::vector<std::string> failValues;
    std::vector<std::string> successValues;
private:

    virtual void genFailValues();
    virtual void genSuccessValues();

    virtual void createDomain();
    void successCase();
    void failCase();
    void destroyDomain();
};

class TUAssento : public TUDominio{
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUDuracao : public TUDominio{
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUVagas : public TUDominio{
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUBagagem : public TUDominio{
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUEstado : public TUDominio{
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUPreco : public TUDominio{
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUNome : public TUDominio{
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUCidade : public TUDominio{
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

class TUEmail : public TUDominio{
private:
    void genFailValues();
    void genSuccessValues();
    void createDomain();
};

};

#endif // SHIBARIDESDOMAINSUT_HPP_INCLUDED
