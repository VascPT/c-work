#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

/*struct Trabalhadores{
    string nome;
    int idade;
};*/

/*struct Loja{
    string nomeprodutos;
    int numdecaixas;
    Trabalhadores trabalhadores;
};*/

//Loja lojadetalhes = {"bananas", 4, {"joao", 26}};

/*int main(){
    cout << lojadetalhes.nomeprodutos << endl;
    cout << lojadetalhes.numdecaixas << endl;
    cout << lojadetalhes.trabalhadores.idade << endl;
    cout << lojadetalhes.trabalhadores.nome << endl;
    return 0;
}*/



int main(){
    system("clear");
    int x;
    cout << "How old are you?" << endl;
    cin >> x;
    this_thread::sleep_for(chrono::seconds(1));
    if(x==1){
    cout << endl << "I am " << x << " year old!" << endl;
}else if (x>= 2 || x<= 0){
    cout << endl << "I am " << x << " years old!" << endl;
}
this_thread::sleep_for(chrono::seconds(2));
    if(x==4){
        cout << endl << "You are the youngest person ever!" << endl << endl;
    }else{
        cout << endl << "Fuck you" << endl << endl;
    }
    return 0;
}