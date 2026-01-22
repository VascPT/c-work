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
            cout << "Warning: Price can't be negative! Automatically set to 0." << endl;
        } else {
            prodPrice = p1;  //se não for negativo, usa o valor normal
        }
    }

    float getPrice(){
        return prodPrice;
    }

    virtual void showDetails() {
        cout << "Name: " << prodName << endl;
        cout << "Price: " << prodPrice << " Euros" << endl;
    }
};

class Author: public Product{//classe derivada
    private:
    string author;
    public:
    Author(string a) {
        author = a;
    }
        void showDetails() override {
        //primeiro mostra os detalhes do Produto
        Product::showDetails();
        //depois mostra o autor específico do book
        cout << "Book's author: " << author << endl;
    }
};

class Brand: public Product{
    private:
    string brand;
    public:
    Brand(string m) {
        brand = m;
    }

        void showDetails() override {
        //primeiro mostra os detalhes do Produto
        Product::showDetails();
        //depois mostra a marca específica do phone
        cout << "Phone's Brand: " << brand << endl;
    }
    
};


int main(){
    clear();
    Author book("Joao");
    Brand phone("Xiaomi");
    book.setName("Maias");
    book.setPrice(20);
    phone.setName("Phone x");
    phone.setPrice(400);

    cout << "Store registration below:" << endl;
    cout << "-------------------------------------" << endl;
    book.showDetails();
    cout << "-------------------------------------" << endl;
    phone.showDetails();
    cout << "-------------------------------------" << endl;


}
