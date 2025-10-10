#include <iostream>
#include "jogo.cpp"
using namespace std;

int main(){
    system("clear");
    int escolha;
   do{ 
    cout << "------------------------------------------------------" << endl;
    cout << "Bem-vindo a lojinha virtual! Selecione uma das opcoes:" << endl;
    cout << "------------------------------------------------------" << endl;
    int iniciar;
    cout << endl << "1 - Iniciar " << endl;
    cout << "0 - Sair" << endl;
    
    cin >> escolha;
    if(escolha == 1){
        jogo();
    }else if(escolha == 0){
        cout << endl << "Obrigado por visitar!" << endl;
        return 0;
    }else{
        cout << "Escolha invalida! Escolha uma opcao valida!" << endl;
    }
    }while(escolha != 0);
}