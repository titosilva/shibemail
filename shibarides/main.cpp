#include <iostream>
#include "ShibaRidesDomains.hpp"
#include "ShibaRidesDomainsUT.hpp"
#include "ShibaRidesEntities.hpp"
#include "ShibaRidesEntitiesUT.hpp"

using namespace std;
using namespace shibarides;

template<class TUBase, class TU>
void runTest(string label){
    TU tu;

    cout << "Testing: " << label << endl;
    cout << "> Result: ";

    int r = tu.run();

    switch(r){
    case TUBase::SUCCESS:
        cout << "SUCCESS" <<  endl;
        break;
    case TUBase::FAIL:
        cout << "FAIL" <<  endl;
        break;
    }

}

int main(){
    cout<<  "===== DOMAINS =====" <<  endl;

    runTest<TUDominio,TUAssento>("Assento");
    runTest<TUDominio,TUBagagem>("Bagagem");
    runTest<TUDominio,TUCodDeBanco>("CodDeBanco");
    runTest<TUDominio,TUCodDeCarona>("CodDeCarona");
    runTest<TUDominio,TUCodDeReserva>("CodDeReserva");
    runTest<TUDominio,TUCidade>("Cidade");
    runTest<TUDominio,TUCPF>("CPF");
    runTest<TUDominio,TUData>("Data");
    runTest<TUDominio,TUDuracao>("Duracao");
    runTest<TUDominio,TUEstado>("Estado");
    runTest<TUDominio,TUEmail>("Email");
    runTest<TUDominio,TUNome>("Nome");
    runTest<TUDominio,TUNumDeAgencia>("NumDeAgencia");
    runTest<TUDominio,TUNumDeConta>("NumDeConta");
    runTest<TUDominio,TUPreco>("Preco");
    runTest<TUDominio,TUTelefone>("Telefone");
    runTest<TUDominio,TUSenha>("Senha");
    runTest<TUDominio,TUVagas>("Vagas");

    cout<< endl << "===== ENTITIES =====" <<  endl;

    runTest<TUEntidade, TUUsuario>("Usuario");
    runTest<TUEntidade, TUConta>("Conta");
    runTest<TUEntidade, TUReserva>("Usuario");
    runTest<TUEntidade, TUUsuario>("Usuario");


    return 0;
}
