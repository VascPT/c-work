#include <iostream>
using namespace std;
void clear(){
    #ifdef WIN32
        system("CLS");
    #else
        system("clear");
    #endif
}

class Product{
    private:
    string prodName;
    float prodPrice;

    public:

    void setName(string n1){
        prodName = n1;
    }

    string getName(){
        return prodName;
    }

    void setPrice(double p1){
        if (p1 < 0) {  //verifica se o preço é negativo
            prodPrice = 0;  //define como 0
            cout << "Warning: Price can't be negate! Automatically set to 0." << endl;
        } else {
            prodPrice = p1;  //se não for negativo, usa o valor normal
        }
    }

    float getPrice(){
        return prodPrice;
    }
};

class Author: public Product{//classe derivada
    public:
    string author = "Joao";
};

class Brand: public Product{
    public:
    string brand = "Xiaomi";  
};


int main(){
    clear();
    Author livro;
    Brand phone;
    livro.setName("Maias");
    livro.setPrice(20);
    phone.setName("Phone x");
    phone.setPrice(400);

    cout << "Store registration below:" << endl;
    cout << "-------------------------------------" << endl;
    cout << "\t\t" << livro.getName() << endl;
    cout << "\t\t" << livro.getPrice() << " Euros" << endl;
    cout << "\t" << "Author of book: " << livro.author << endl;
    cout << "-------------------------------------" << endl;
    cout << "\t\t" << phone.getName() << endl;
    cout << "\t\t" << phone.getPrice() << " Euros" << endl;
    cout << "\t" << "Phone's brand: " << phone.brand << endl;
    cout << "-------------------------------------" << endl;

}
