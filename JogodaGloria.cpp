//Código feito por Vasco Franco
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;
void clear(){
    #ifdef WIN32
        system("CLS");
    #else
        system("clear");
    #endif
}
const int N = 30;
const int Perde_Jogada = 4; //casa 4
const int Volta_tres_casas = 10; //casa 10
const int Avanca_tres_casas = 5; //casa 5
const int Joga_novament = 15; //casa 15
const int Espera_passg = 20; // casa 20

string nomeP1;
string nomeP2;

void iniciarCasas(string casas[N]){
    for (int i=0; i<N; i++)
        casas[i] = '-';
    casas[Perde_Jogada] = "PJ"; //Perde a vez
    casas[Volta_tres_casas] = "V3"; //Volta 3 casas
    casas[Avanca_tres_casas] = "A3"; //Avança 3 casas
    casas[Joga_novament] = "JN"; //Joga novamente
    casas[Espera_passg] = "EP"; //Espera passagem do próximo jogador
}

void imprimirCasas(string casas[N]){
    //linha dos números (1...30)
    for(int i=0 ; i<N;i++){ 
        cout<<(i+1<10?" ":"")<<i+1<<" ";
    }
    cout << "\n";

    for(int i=0; i<N; i++){
        string cell = casas[i];
    }

}
void dado(){
    std::srand(std::time(nullptr)); // inicializa o gerador com o tempo atual
    int numero = std::rand() % 6 + 1; // número entre 1 e 6 (como um dado)
    std::cout << "Saiu o número: " << numero << std::endl;
}

int main(){
    clear();
}