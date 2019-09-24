#include "ShibaRidesDomains.hpp"
#include <iostream>
#include <string>
using namespace shibarides;

Dominio::Dominio(){
    this->valueSet = false;
    this->value = "";
}


void Dominio::setValue(std::string value) throw (std::invalid_argument){
    this->validate(value);
    this->value = value;
    this->valueSet = true;
}

std::string Dominio::getValue() const throw (std::exception){
    if(this->valueSet) return this->value;
    else throw std::exception();
}

void Dominio::validate(std::string value) throw (std::invalid_argument){}

void Assento::validate(std::string value) throw (std::invalid_argument){
    if(value!="D" && value!="T") throw (std::invalid_argument("Argument must be D or T"));
}

void Duracao::validate(std::string value) throw (std::invalid_argument){
    int tamanho_string = 0;
    int valor = ::atoi(value.c_str());
    for (tamanho_string = 0;tamanho_string < value.length();tamanho_string++){
        if(value[tamanho_string]>57 || value[tamanho_string]<48)
            throw (std::invalid_argument("Argument must be a inter"));
        if(valor>48)
            throw (std::invalid_argument("Argument must be less than 48"));
    }
}

void Vagas::validate(std::string value) throw (std::invalid_argument){
    int tamanho_string = 0;
    if (value.length()>1) throw (std::invalid_argument("Argument must be from 0 to 4"));
    for (tamanho_string = 0;tamanho_string < value.length();tamanho_string++){
        if(value[tamanho_string] < 48 || value[tamanho_string] > 52)
            throw (std::invalid_argument("Argument must be from 0 to 4"));
    }
}

void Bagagem::validate(std::string value) throw (std::invalid_argument){
    int tamanho_string = 0;
    if (value.length()>1) throw (std::invalid_argument("Argument must be from 0 to 4"));
    for (tamanho_string = 0;tamanho_string < value.length();tamanho_string++){
        if(value[tamanho_string] < 48 || value[tamanho_string] > 52)
            throw (std::invalid_argument("Argument must be from 0 to 4"));
    }
}

void Estado::validate(std::string value) throw (std::invalid_argument){
    if (value!="AC"||value!="AL"||value!="AP"||value!="AM"||value!="BA"||value!="CE"||value!="DF"||
        value!="ES"||value!="GO"||value!="MA"||value!="MT"||value!="MS"||value!="MG"||value!="PA"||value!="PB"||
        value!="PR"||value!="PE"||value!="PI"||value!="RJ"||value!="RN"||value!="RS"||value!="RO"||value!="RR"||
        value!="SC"||value!="SP"||value!="SE"||value!="TO") throw (std::invalid_argument("Argument inst a valid state"));
}

void Nome::validate(std::string value) throw (std::invalid_argument){
    int tamanho_string = 0;
    int check_letter = 0;
    if (value.length()>20)throw (std::invalid_argument("Argument must have less than 21 chars"));
    for (tamanho_string = 0;tamanho_string < value.length();tamanho_string++){
        if(value[tamanho_string] < 65 || value[tamanho_string] > 90 || value[tamanho_string] < 97 || value[tamanho_string] > 122 ||
           value[tamanho_string] != 46 || value[tamanho_string] != 32)
            throw (std::invalid_argument("Argument must be letters, comas or spaces"));
        if(value[tamanho_string] == 32 && value[tamanho_string+1] == 32)
            throw (std::invalid_argument("cant have two spaces together"));
        if((value[tamanho_string] > 65 && value[tamanho_string] < 90) || (value[tamanho_string] > 97 && value[tamanho_string] < 122))
            check_letter++;
        if(check_letter == 0)throw (std::invalid_argument("need at least one letter in the name"));

    }
}

void Cidade::validate(std::string value) throw (std::invalid_argument){
    int tamanho_string = 0;
    int check_letter = 0;
    if (value.length()>10)throw (std::invalid_argument("Argument must have less than 11 chars"));
    for (tamanho_string = 0;tamanho_string < value.length();tamanho_string++){
        if(value[tamanho_string] < 65 || value[tamanho_string] > 90 || value[tamanho_string] < 97 || value[tamanho_string] > 122 ||
           value[tamanho_string] != 46 || value[tamanho_string] != 32)
            throw (std::invalid_argument("Argument must be letters, comas or spaces"));
        if(value[tamanho_string] == 32 && value[tamanho_string+1] == 32)
            throw (std::invalid_argument("cant have two spaces together"));
        if((value[tamanho_string] > 65 && value[tamanho_string] < 90) || (value[tamanho_string] > 97 && value[tamanho_string] < 122))
            check_letter++;
        if(check_letter == 0)throw (std::invalid_argument("need at least one letter in the name"));

    }
}

void Preco::validate(std::string value) throw (std::invalid_argument){
    double valor = ::atof(value.c_str());
    if (valor < 0 || valor > 5000) throw (std::invalid_argument("Argument must be bigger than 0,00 and smaller than 5000,01"));
}

void Email::validate(std::string value) throw (std::invalid_argument){
    int tamanho_string = 0;
    int tamanho_nome = 0;
    int tamanho_dominio = 0;
    int check_arroba = 0;
    for (tamanho_string = 0;tamanho_string < value.length();tamanho_string++){
        if(value[tamanho_string] == 64)
            check_arroba++;
        if(check_arroba == 0)throw (std::invalid_argument("need at least one @ in the name"));
        if(check_arroba > 1) throw (std::invalid_argument("cant have more than 1 @"));

        if(value[tamanho_string] == 64){
            tamanho_nome = tamanho_string+1;
            tamanho_dominio = value.length()-tamanho_string+1;
        }
        if(value[tamanho_string] < 64 || value[tamanho_string] > 90 || value[tamanho_string] < 97 || value[tamanho_string] > 122 ||
           value[tamanho_string] != 46)
            throw (std::invalid_argument("Argument must be letters or comas"));
        if(value[tamanho_string] == 46 && value[tamanho_string+1] == 46)
            throw (std::invalid_argument("cant have two comas together"));
    }

    if (tamanho_nome > 10 || tamanho_dominio > 10)throw (std::invalid_argument("Argument must have less than 11 chars"));
}






