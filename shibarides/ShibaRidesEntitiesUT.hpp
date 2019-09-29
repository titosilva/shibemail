#ifndef SHIBARIDESENTITIESUT_HPP_INCLUDED
#define SHIBARIDESENTITIESUT_HPP_INCLUDED

#include "ShibaRidesEntities.hpp"
#include "ShibaRidesDomains.hpp"
#include <vector>

namespace shibarides{

class TUEntidade{
public:
    TUEntidade();
    const static int SUCCESS = 1, FAIL = 0;
    int run();
protected:
    int state;
private:
    virtual void createEntity()=0;
    virtual void testMethods()=0;
    virtual void destroyEntity()=0;
};

class TUUsuario : public TUEntidade{
private:
    Usuario *usuario;
private:
    void createEntity();
    void testMethods();
    void destroyEntity();
};

class TUConta : public TUEntidade{
private:
    Conta *conta;
private:
    void createEntity();
    void testMethods();
    void destroyEntity();
};

class TUReserva : public TUEntidade{
private:
    Reserva *reserva;
private:
    void createEntity();
    void testMethods();
    void destroyEntity();
};

class TUCarona : public TUEntidade{
private:
    Carona *carona;
private:
    void createEntity();
    void testMethods();
    void destroyEntity();
};
};
#endif // SHIBARIDESENTITIES_HPP_INCLUDED
