#include <iostream>
using namespace std;

//cria uma funcao que aceite como parametro uma estrutura e mostre o seu conteudo
//a ter em consideracao:
//-a estrutura ao ser passada na funcao ja deve ter dados
//-a estrutura tem o seguinte formato:
//nome: carro
//atributos: string Marca,
 //  string Modelo

    struct carro{
        string marca;
        string modelo;
    };
void myFunction(carro c){
    cout << "Marca: " << c.marca << ", Modelo: " << c.modelo << endl;
}

int main(){
    carro myCar = {"BMW", "chibidibaum"};
    myFunction(myCar);
    return 0;
}