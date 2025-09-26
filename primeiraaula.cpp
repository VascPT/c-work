#include <iostream>
using namespace std;

//cria uma struct ao teu criterio com 2 valores(global)
//cria uma instancia da tua struct com valores(global)
//cria uma funçao <void> que aceita como parametro a struct
//a funçao deve imprimir no ecra os valores instanciados na struct

struct jogador{
    int idade;
    string nome;
};

jogador player1 = {10 , "Ricardo"};

void showPlayer(jogador x){
    cout << x.idade << endl;
    cout << x.nome << endl;
}
int main(){
    showPlayer(player1);
}