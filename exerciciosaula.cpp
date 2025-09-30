#include <iostream>
using namespace std;

/*cria uma funcao que aceite como parametro uma estrutura e mostre o seu conteudo
a ter em consideracao:
-a estrutura ao ser passada na funcao ja deve ter dados
-a estrutura tem o seguinte formato:
nome: carro
atributos: string Marca,
string Modelo*/

/*    struct Carro{
        string marca;
        string modelo;
    };
void myFunction(Carro carro){
    
    cout << "Marca: " << carro.marca << ", Modelo: " << carro.modelo << endl;
}

int main(){
    Carro myCar = {"BMW", "chibidibaum"};
    myFunction(myCar);
    return 0;
}*/

struct Escola{
    string nome;
    string morada;
};

struct Aluno{
    string nome;
    int idade;
    string caracteristicas;
    Escola escola;
};

Aluno a1 = {"Roberto", 20, "autista", {"domingos rebelo", "Ponta Delgada"}};

int main() {
    cout << a1.escola.morada;
    return 0;
}