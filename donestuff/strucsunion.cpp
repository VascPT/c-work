#include <iostream>
using namespace std;

union Comida{
    char bolo;
    char pudim;
};

struct Cozinha{
    int idade;
    string nomeCozinheiro;
};

Comida sabor;

Cozinha cozinheiro;

int main(){
    system("clear");
    
    return 0;
}