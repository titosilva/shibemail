#ifndef SHIBARIDESDOMAINS_HPP_INCLUDED
#define SHIBARIDESDOMAINS_HPP_INCLUDED

#include <stdexcept>
#include <string>

namespace shibarides{

// Base class
/** @brief Classe abstrata que serve de base para os domínios

  @details Classe da qual todos os dominios são herdados. Implementa as funçoes setValue e getValue, que servem
           para definir o valor armazenado em um dominio ou retornar esse valor. Todos os valores para os
           dominios sao armazenados na string value.
           É exigida a implementação da função abstrata pura validate em todos os dominios. Essa função
           define as regras pelas quais valores serao aceitos ou recusados pelo dominio.
*/
class Dominio{
public:
    /// @brief Construtor da classe Dominio
    /// @details Apenas define o campo value como string vazia ("")
    Dominio();
    /** @brief Armazena o valor passado, caso este seja valido para o dominio em questão.

        @details A funçao setValue invoca o metodo validate do dominio, com o intuito de verificar
                 se o valor passado é valido. Em caso positivo, o valor é armazenado no campo value do objeto.
                 Em caso negativo, é lançada uma excessão do tipo std::invalid_argument.

        @param string Valor a ser armazenado
    */
    void setValue(std::string) throw (std::invalid_argument);

    /** @brief Retorna o valor armazenado no campo value.

        @details A funçao getValue retorna o valor armazenado pelo dominio. Se o valor ainda nao tiver sido modificado,
                 é retornada uma string vazia.

        @return string Valor armazenado pelo dominio
    */
    std::string getValue() const;
private:
    /** @brief Função privada que define as regras de validação para o dominio.

        @details Função pura abstrata, que é sobrescrita nos domínios e define o comportamento de cada
                 domínio. Caso o valor passado nao seja valido, é lançada uma excessão std::invalid_argument.

        @param string Valor a ser validado.
    */
    virtual void validate(std::string) throw (std::invalid_argument)=0;
    /// @brief Armazena valores (todos os valores sao strings)
    std::string value;
};

// Domains
class Assento : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Bagagem : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class CodDeBanco : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class CodDeCarona : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class CodDeReserva : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Cidade : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class CPF : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Data : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Duracao : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Estado : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Email : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Nome : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class NumDeAgencia : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class NumDeConta : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Preco : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Telefone : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Senha : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

class Vagas : public Dominio{
private:
    void validate(std::string) throw (std::invalid_argument);
};

};

#endif // SHIBARIDESDOMAINS_HPP_INCLUDED
