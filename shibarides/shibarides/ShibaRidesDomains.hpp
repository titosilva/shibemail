#ifndef SHIBARIDESDOMAINS_HPP_INCLUDED
#define SHIBARIDESDOMAINS_HPP_INCLUDED

#include <stdexcept>
#include <string>

namespace shibarides{

class Dominio{
public:
    Dominio();
    void setValue(std::string) throw (std::invalid_argument);
    std::string getValue() const throw (std::exception);
private:
    virtual void validate(std::string) throw (std::invalid_argument);
    std::string value;
    bool valueSet;
};

class Assento : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Duracao : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Vagas : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Bagagem : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Estado : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Preco : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Nome : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Cidade : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Email : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

};

#endif // SHIBARIDESDOMAINS_HPP_INCLUDED
