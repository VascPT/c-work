//Código feito por Vasco Franco
#include <iostream>
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
const int Volta_tres_casas = 6; //casa 6
const int Avanca_tres_casas = 2; //casa 2
const int Joga_novament = 14; //casa 14
const int Espera_passg = 23; // casa 23

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
    for(int i=0 ; i<N;i++){
        cout<<(i+1<10?" ":"")<<i+1<<" ";
    }

}


int main(){
    clear();
}