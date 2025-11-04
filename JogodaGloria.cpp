//Código feito por Vasco
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


int main(){
    clear();
}