#include "ShibaRidesDomains.hpp"
#include <iostream>
#include <vector>
using namespace shibarides;

// Base class
Dominio::Dominio(){
    this->value = "";
}

void Dominio::setValue(std::string value) throw (std::invalid_argument){
    this->validate(value);
    this->value = value;
}

std::string Dominio::getValue() const{
    return this->value;
}

// Domains

// Assento
void Assento::validate(std::string value) throw (std::invalid_argument){
    if(value!="D" && value!="T") throw (std::invalid_argument("Argument must be D or T"));
}

// Bagagem
void Bagagem::validate(std::string value) throw (std::invalid_argument){
    int tamanho_string = 0;

    if (value.length()!=1) throw (std::invalid_argument("Argument must be from 0 to 4"));

    if(value[tamanho_string] - '0' < 0 || value[tamanho_string] - '0' > 4)
        throw (std::invalid_argument("Argument must be from 0 to 4"));

}

// CodDeBanco
void CodDeBanco::validate(std::string value) throw (std::invalid_argument){
    if(value.size()!=3) throw (std::invalid_argument("Argument must have 3 digits"));

    for(int i=0; i<3; i++){
        if(value.at(i)-'0'>9 || value.at(i)-'0'<0) throw(std::invalid_argument("Argument must have all digits 0-9"));
    }
}

// CodDeCarona
void CodDeCarona::validate(std::string value) throw (std::invalid_argument){
    if(value.size()!=4) throw (std::invalid_argument("Argument must have 3 digits"));

    for(int i=0; i<4; i++){
        if(value.at(i)-'0'>9 || value.at(i)-'0'<0) throw(std::invalid_argument("Argument must have all digits 0-9"));
    }
}

// CodDeReserva
void CodDeReserva::validate(std::string value) throw (std::invalid_argument){
    if(value.size()!=5) throw (std::invalid_argument("Argument must have 3 digits"));

    for(int i=0; i<5; i++){
        if(value.at(i)-'0'>9 || value.at(i)-'0'<0) throw(std::invalid_argument("Argument must have all digits 0-9"));
    }
}

// Cidade
void Cidade::validate(std::string value) throw (std::invalid_argument){
    int check_letter = 0;

    if (value.length()>10) throw (std::invalid_argument("Argument must have less than 11 chars"));

    for (int i=0; i < value.length(); i++){
        if( !( (value[i] > 'A' && value[i] <= 'Z') || (value[i] >= 'a' && value[i] <= 'z' ) || value[i] == '.' || value[i] == ' ')){
            throw (std::invalid_argument("Argument must be letters, spaces or comas"));
        }

        if(value[i] == ' ' && value[i+1] == ' ')
            throw (std::invalid_argument("cant have two spaces together"));

        if((value[i] >= 'a' && value[i] <= 'z') || (value[i] >= 'A' && value[i] <= 'Z'))
            check_letter++;

        if(check_letter == 0) throw (std::invalid_argument("need at least one letter in the name"));
    }
}

// CPF
void CPF::validate(std::string value) throw (std::invalid_argument){
    if(value.size()!=14) throw (std::invalid_argument("Argument must have XXX.XXX.XXX-YY format"));

    // Verify string format
    for(int i=0; i<14; i++){
        if(i==3 || i==7){
            if(value.at(i)!='.') throw (std::invalid_argument("Argument must have XXX.XXX.XXX-YY format (with dots and dashes)"));
        }else if(i==11){
            if(value.at(i)!='-') throw (std::invalid_argument("Argument must have XXX.XXX.XXX-YY format (with dots and dashes)"));
        }else{
            if(value.at(i)-'0'<0 || value.at(i)-'0'>9) throw (std::invalid_argument("Argument must have all digits 0-9, dots or dashes"));
        }
    }

    // Save the digits in a vector
    std::vector<int> digits;
    for(int i=0; i<14; i++){
        // Skip dots and dashes
        if(i==3 || i==7 || i==11) continue;

        digits.push_back(value.at(i)-'0');
    }

    // Multiĺy the first digits by a weight, in 10-2, corresponding to its position
    // and sum everything
    int sum = 0;
    for(int i=0; i<9; i++){
        sum += digits.at(i)*(10-i);
    }

   // Verify the first check digit
    if(sum%11>2){
        if(digits.at(9)!=(11-sum%11)) throw (std::invalid_argument("First check digit not correct"));
    }else{
        if(digits.at(9)!=0) throw (std::invalid_argument("First check digit not correct"));
    }
    // Multiĺy the first digits, including the first check digit,
    // by a weight, in 11-2, corresponding to its position
    // and sum everything
    sum = 0;
    for(int i=0; i<10; i++){
        sum += digits.at(i)*(11-i);
    }

    // Verify the second check digit
    if(sum%11>2){
        if(digits.at(10)!=(11-sum%11)) throw (std::invalid_argument("Second check digit not correct"));
    }else{
        if(digits.at(10)!=0) throw (std::invalid_argument("Second check digit not correct"));
    }
}

// Data
void Data::validate(std::string value) throw (std::invalid_argument){
    int tamanho_string = 0;
    int valor = (int)value[9]+(int)value[8]*10;
    if (value.length()!=10)throw (std::invalid_argument("Argument must have 10 chars"));
    if((value[0] >= 48 && value[0] <= 57)||(value[1] >= 48 && value[1] <= 57)||(value[3] >= 48 && value[3] <= 57)||
       (value[4] >= 48 && value[4] <= 57)||(value[6] >= 48 && value[6] <= 57)||(value[7] >= 48 && value[7] <= 57)||
       (value[8] >= 48 && value[8] <= 57)||(value[9] >= 48 && value[9] <= 57) || value[2]=='/' || value[5]=='/'){}
    else{
        throw (std::invalid_argument("Argument must be DD/MM/AAAA"));
    }
    if(value[3] > '1')throw (std::invalid_argument("MM cant be bigger than 12"));
    if(value[3] == '1'){
        if(value[4] > '2')throw (std::invalid_argument("MM cant be bigger than 12"));
    }
    if((value[3]=='0'&&(value[4]=='1'||value[4]=='3'||value[4]=='5'||value[4]=='7'||
       value[4]=='8'))||((value[3]=='1'&&(value[4]=='0'||value[4]=='2')))){
        if(value[0] > '3')throw (std::invalid_argument("DD cant be bigger than 31"));
        if(value[0] == '3'){
        if(value[1] > '1')throw (std::invalid_argument("MM cant be bigger than 31"));
        }
       }
    if((value[3]=='0'&&(value[4]=='4'||value[4]=='6'||value[4]=='9'))||
        ((value[3]=='1'&&(value[4]=='1')))){
        if(value[0] > '3')throw (std::invalid_argument("DD cant be bigger than 30"));
        if(value[0] == '3'){
        if(value[1] > '0')throw (std::invalid_argument("MM cant be bigger than 30"));
        }
       }

    if(value[6]!='2'&&value[7]!='0')throw (std::invalid_argument("AAAA has to be 2000 to 2099"));

    if(valor%4==0){
        if(value[3]=='0'&&value[4]=='2'){
           if(value[0] >'2')throw (std::invalid_argument("DD cant be bigger than 28"));
           if(value[0] =='2' && value[1] > '8')throw (std::invalid_argument("DD cant be bigger than 28"));
           }
    }
    else{
        if(value[3]=='0'&&value[4]=='2'){
           if(value[0] >'2')throw (std::invalid_argument("DD cant be bigger than 27"));
           if(value[0] =='2' && value[1] > '7')throw (std::invalid_argument("DD cant be bigger than 27"));
           }
    }
}

// Duracao
void Duracao::validate(std::string value) throw (std::invalid_argument){
    for(int i=0; i < value.length(); i++){
        if(value[i] > '9' || value[i]< '0')
            throw (std::invalid_argument("Argument must be a number"));
    }

    int valor = std::atoi(value.c_str());

    if(valor<=0 || valor > 48) throw (std::invalid_argument("Argument must be 1 - 48"));
}

// Estado
void Estado::validate(std::string value) throw (std::invalid_argument){
    if (value=="AC" || value=="AL" || value=="AP" || value=="AM" || value=="BA" || value=="CE" || value=="DF" ||
        value=="ES" || value=="GO" || value=="MA" || value=="MT" || value=="MS" || value=="MG" || value=="PA" || value=="PB" ||
        value=="PR" || value=="PE" || value=="PI" || value=="RJ" || value=="RN" || value=="RS" || value=="RO" || value=="RR" ||
        value=="SC" || value=="SP" || value=="SE" || value=="TO"){}
        else{throw (std::invalid_argument("Argument inst a valid state"));}
}

// Email
void Email::validate(std::string value) throw (std::invalid_argument){
    int check_arroba = 0;
    // Verify if every character is @, dot or letter
    for(int i=0; i<value.size(); i++)
        if( !(value[i] == '@' || value[i] == '.' || (value[i]>='a' && value[i]<='z') || (value[i]>='A' && value[i]<='Z')) )
            throw (std::invalid_argument("Argument must use only @, dots or letters"));

    // Count the number of @ and verify if it's ok
    for(int i = 0; i < value.size(); i++) if(value[i] == '@') check_arroba++;
    if(check_arroba!=1) throw (std::invalid_argument("Invalid email"));

    // Verify the dots positions
    for(int i=0; i<value.size(); i++){
        if(value[i]=='.'){
            // "Local" started with a dot
            if(i==0) throw (std::invalid_argument("Argument must not start with a dot"));
            // "Local" ended with a dot
            else if(value[i+1]=='@') throw (std::invalid_argument("Argument \'local\' must not end with a dot"));
            // "Dominio" started with a dot
            else if(value[i-1]=='@') throw (std::invalid_argument("Argument \'dominio\' must not start with a dot"));
            // Dots in sequence
            else if(i<value.size()-1 && value[i+1]=='.') throw (std::invalid_argument("Argument must not have dots in sequence"));
        }
    }

    // Find the position of the @ and verify the sizes of "Local" and "Dominio"
    // Once we know that the number of @ here is 1, we do not need to verify it again.
    int posat = value.find('@');
    if(posat>20 || value.size() - posat > 20)
        throw (std::invalid_argument("Argument \'dominio\' and \'local\' must not be larger than 20 letters"));
}

// Nome
void Nome::validate(std::string value) throw (std::invalid_argument){
    int tamanho_string = 0;
    int check_letter = 0;
    if (value.length()>20)throw (std::invalid_argument("Argument must have less than 21 chars"));
    for (tamanho_string = 0;tamanho_string < value.length();tamanho_string++){
        if((value[tamanho_string] >= 64 && value[tamanho_string] <= 90) || (value[tamanho_string] >= 97 && value[tamanho_string] <= 122 )||
           value[tamanho_string] == 46 || value[tamanho_string] == 32){}
            else {throw (std::invalid_argument("Argument must be letters, spaces or comas"));}
        if(value[tamanho_string] == 32 && value[tamanho_string+1] == 32)
            throw (std::invalid_argument("cant have two spaces together"));
        if((value[tamanho_string] > 65 && value[tamanho_string] < 90) || (value[tamanho_string] > 97 && value[tamanho_string] < 122))
            check_letter++;
        if(check_letter == 0)throw (std::invalid_argument("need at least one letter in the name"));

    }
}

// NumDeAgencia
void NumDeAgencia::validate(std::string value) throw (std::invalid_argument){
    // Using Luhn's Algorithm
    if(value.size()!=6) throw(std::invalid_argument("Argument must be XXXX-Y format"));

    for(int i=0; i<6; i++){
        // Verify the dashes
        if(i==4){
            if(value.at(i)!='-') throw (std::invalid_argument("Argument must be XXXX-Y format(with the dashes)"));
        }else if(value.at(i)-'0'<0 || value.at(i)-'0'>9){
            throw (std::invalid_argument("Argument must have all digits 0-9 or dashes"));
        }
    }

    // Luhn's Algorithm to verify the check digit
    std::vector<int> digits;

    // Store the digits in a vector
    for(int i=0; i<6; i++){
        // Skip the dash
        if(i==4) continue;
        digits.push_back(value.at(i)-'0');
    }

    // Double every second digit
    for(unsigned int i=0; i<digits.size()-1; i++){
        if(i%2==1) digits.at(i) = (digits.at(i)*2<10)? digits.at(i)*2 : digits.at(i)*2 - 9;
    }

    // check if the check digit is correct
    int sum = 0;
    for(unsigned int i=0; i<digits.size(); i++){
        sum += digits.at(i);
    }

    if(sum%10!=0) throw (std::invalid_argument("Invalid number"));
}

// NumDeConta
void NumDeConta::validate(std::string value) throw (std::invalid_argument){
    // Using Luhn's Algorithm
    if(value.size()!=8) throw(std::invalid_argument("Argument must be XXXXXX-Y format"));

    for(int i=0; i<8; i++){
        // Verify the dashes
        if(i==6){
            if(value.at(i)!='-') throw (std::invalid_argument("Argument must be XXXXXX-Y format(with the dashes)"));
        }else if(value.at(i)-'0'<0 || value.at(i)-'0'>9){
            throw (std::invalid_argument("Argument must have all digits 0-9 or dashes"));
        }
    }

    // Luhn's Algorithm to verify the check digit
    std::vector<int> digits;

    // Store the digits in a vector
    for(int i=0; i<8; i++){
        // Skip the dash
        if(i==6) continue;
        digits.push_back(value.at(i)-'0');
    }

    // Double every second digit
    for(unsigned int i=0; i<digits.size()-1; i++){
        if(i%2==1) digits.at(i) = (digits.at(i)*2<10)? digits.at(i)*2 : digits.at(i)*2 - 9;
    }

    // check if the check digit is correct
    int sum = 0;
    for(unsigned int i=0; i<digits.size(); i++){
        sum += digits.at(i);
    }

    if(sum%10!=0) throw (std::invalid_argument("Invalid number"));
}

// Preco
void Preco::validate(std::string value) throw (std::invalid_argument){
    double valor = ::atof(value.c_str());
    int tamanho_string = 0;
    if (valor < 0 || valor > 5000) throw (std::invalid_argument("Argument must be bigger than 0,00 and smaller than 5000,01"));
    for (tamanho_string = 0;tamanho_string < value.size();tamanho_string++){
        if((value[tamanho_string] >= '0' && value[tamanho_string] <= '9') || value[tamanho_string] == '.'){
           }
        else {throw (std::invalid_argument("Argument must be numbers or coma"));}
    }
}

// Telefone
void Telefone::validate(std::string value) throw (std::invalid_argument){
    if(value.size()!=15) throw (std::invalid_argument("Argument must be XX-YY-ZZZZZZZZZ format"));

    for(int i=0; i<15; i++){
        // Verify the dashes
        if(i==2 || i==5){
            if(value.at(i)!='-') throw (std::invalid_argument("Argument must be XX-YY-ZZZZZZZZZ format(with the dashes)"));
        }else if(value.at(i)-'0'<0 || value.at(i)-'0'>9){
            throw (std::invalid_argument("Argument must have all digits 0-9 or dashes"));
        }
    }


    // Verify if there are 00's or a big 000000000
    int XX = std::stoi(value.substr(0,2));
    int YY = std::stoi(value.substr(3,2));
    int Z = std::stoi(value.substr(6,9));
    if(XX==0 || YY==0 || Z==0) throw (std::invalid_argument("Argument can't be zeroes"));
}

// Senha
void Senha::validate(std::string value) throw (std::invalid_argument){
    int tamanho_string = 0;
    int check_repetidas = 0;
    int check_letter = 0;
    int check_num = 0;
    if (value.size() > 5){ throw (std::invalid_argument("Argument must have less than 6 chars"));}
    for (tamanho_string = 0;tamanho_string < value.size();tamanho_string++){
        if((value[tamanho_string] >= 65 && value[tamanho_string] <= 90) || (value[tamanho_string] >= 97 && value[tamanho_string] <= 122 )||
           (value[tamanho_string] >= 48 && value[tamanho_string] <= 57) || (value[tamanho_string] >= 35 && value[tamanho_string] <= 38)){
           }
        else {throw (std::invalid_argument("Argument must be letters,numbers,%,$,# or &"));}

        if((value[tamanho_string] >= 65 && value[tamanho_string] <= 90) || (value[tamanho_string] >= 97 && value[tamanho_string] <= 122 ))
            {check_letter+=1;}


        if((value[tamanho_string] >= 48 && value[tamanho_string] <= 57))
           {check_num+=1;}


        for(check_repetidas = tamanho_string+1; check_repetidas < value.length();check_repetidas++){
            if(value[tamanho_string] == value[check_repetidas])
                throw (std::invalid_argument("cant have two equal chars in the password"));
        }
    }
    if(check_num == 0)throw (std::invalid_argument("need at least one number in the password"));
    if(check_letter == 0)throw (std::invalid_argument("need at least one letter in the password"));
}

// Vagas
void Vagas::validate(std::string value) throw (std::invalid_argument){
    int tamanho_string = 0;
    if (value.length()>1) throw (std::invalid_argument("Argument must be from 0 to 4"));
    for (tamanho_string = 0;tamanho_string < value.length();tamanho_string++){
        if(value[tamanho_string] < 48 || value[tamanho_string] > 52)
            throw (std::invalid_argument("Argument must be from 0 to 4"));
    }
}

