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
vector<int> baralho = {1,2,3,4,5,6,7,8,9,10}; 

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
    baralharB();
    mostrarBaralhado();

    return 0;
}