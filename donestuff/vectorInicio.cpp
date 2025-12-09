#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void clear(){
    #ifdef WIN32
        system("CLS");
    #else
        system("clear");
    #endif
}

#define MAX_NUMEROS 60
vector<int> baralho; 

void gerarSequencia(){
    baralho.clear();
    for (int i=1; i <= MAX_NUMEROS; i++){
        baralho.push_back(i);
    }
}

void baralharB(){
    random_shuffle(baralho.begin(), baralho.end());
}

void mostrarBaralhado(){
    while(!baralho.empty()){
        int numeroSorteado = baralho.back();
        baralho.pop_back();
        cout << "Numero sorteado: " << numeroSorteado << endl;
    }
}

int main(){
    clear();
    gerarSequencia();
    baralharB();
    mostrarBaralhado();

    return 0;
}