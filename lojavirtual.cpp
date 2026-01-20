#include <iostream>
using namespace std;

class Attribute{
    private:
    int prodName;
    float prodPrice;

    public:

    void setPrice(double p){
        if (p < 0) {  //verifica se o preço é negativo
            prodPrice = 0;  //define como 0
            //avisar o usuário
            cout << "Atenção: Preço negativo não permitido! Definido como 0." << endl;
        } else {
            prodPrice = p;  //se não for negativo, usa o valor normal
        }
    }

    float getPrice(){
        return prodPrice;
    }
};

int main(){
    Attribute product1;
    product1.setPrice(20);
    cout << product1.getPrice() << endl;

}