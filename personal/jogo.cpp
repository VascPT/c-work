#include <iostream>
using namespace std;

void jogo(){
   system("clear");
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Bem vindo a loja! (Para sair, selecione um numero diferente de 1,2,3 ou 4)" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << endl << "Selecione um dos produtos para comprar: " << endl;
    cout << "________________________________________________________________________________________________________________________" << endl << endl;
    float valorCarteira = 3;
    cout << "Carteira: " << valorCarteira << endl << endl;

    string prod1 = "Gum";
    string prod2 = "Chips";
    string prod3 = "Wine";
    string prod4 = "steak";

    cout << "1- " << prod1 << " (1 euro)             2- " << prod2 << " (5 euros)              3- " << prod3 << " (50 euros)             4- " << prod4 << " (200 euros)" << endl;
    cout << "________________________________________________________________________________________________________________________" << endl << endl;
    int escolhaProd;
    cin >> escolhaProd;
    float valorprod1 = 1;
    float valorprod2 = 5;
    float valorprod3 = 50;
    float valorprod4 = 200;
    if(escolhaProd > 4 || escolhaProd < 1){
        cout << endl << endl << "Obrigado por fazer compras! Ate a proxima!" << endl << endl << endl;
        exit(0);
    }
    while (true){
   if(valorCarteira >= valorprod2 || valorprod3 || valorprod4){
   
    if(escolhaProd == 1 || 2 || 3 || 4){ 

    switch (escolhaProd){ 

    case 1:
        float valorprod1E;
        valorprod1E = 1; 
         valorCarteira -= 1;
        float valorReceber1E;
        valorReceber1E = valorprod1E * 2;
           valorCarteira += valorReceber1E; 
    cout << endl <<"Obteve: " << valorReceber1E << " euros de volta!" << endl;
    cout << endl << "Fazer mais compras?" << endl;
     cout << "________________________________________________________________________________________________________________________" << endl << endl;
     cout << "Carteira: " << valorCarteira << endl << endl;
        cout << "1- " << prod1 << " (1 euro)             2- " << prod2 << " (5 euros)              3- " << prod3 << " (50 euros)             4- " << prod4 << " (200 euros)" << endl;
        cout << "________________________________________________________________________________________________________________________" << endl << endl;
        cin >> escolhaProd;
    break;
    case 2:
        float valorprod2E;
        valorprod2E = 5;
          valorCarteira -= 5;
        float valorReceber2E;
        valorReceber2E = valorprod2E * 1.4;
           valorCarteira += valorReceber2E;
    cout << endl << "Obteve: " << valorReceber2E << " euros de volta!" << endl;
        cout << endl << "Fazer mais compras?" << endl;
        cout << "________________________________________________________________________________________________________________________" << endl << endl;
        cout << "Carteira: " << valorCarteira << endl << endl;
        cout << "1- " << prod1 << " (1 euro)             2- " << prod2 << " (5 euros)              3- " << prod3 << " (50 euros)             4- " << prod4 << " (200 euros)" << endl;
        cout << "________________________________________________________________________________________________________________________" << endl << endl;
        cin >> escolhaProd;
    break;
    case 3:
       float valorprod3E;
       valorprod3E = 50;
        valorCarteira -= 50;
        float valorReceber3E;
        valorReceber3E = valorprod3E * 1.3;
           valorCarteira += valorReceber3E;
    cout << endl <<"Obteve: " << valorReceber3E << " euros de volta!"  << endl;
        cout << endl << "Fazer mais compras?" << endl;
        cout << "________________________________________________________________________________________________________________________" << endl << endl;
        cout << "Carteira: " << valorCarteira << endl << endl;
        cout << "1- " << prod1 << " (1 euro)             2- " << prod2 << " (5 euros)              3- " << prod3 << " (50 euros)             4- " << prod4 << " (200 euros)" << endl;
        cout << "________________________________________________________________________________________________________________________" << endl << endl;
        cin >> escolhaProd;

    break;
    case 4: 
       float valorprod4E;
        valorprod4E = 200; 
        valorCarteira -= 200;
        float valorReceber4E;
        valorReceber4E = valorprod4E * 1.3;
           valorCarteira += valorReceber4E;
    cout << endl <<"Obteve: " << valorReceber4E << " euros de volta!"  << endl;
        cout << endl << "Fazer mais compras?" << endl;
        cout << "________________________________________________________________________________________________________________________" << endl << endl;
        cout << "Carteira: " << valorCarteira << endl << endl;
        cout << "1- " << prod1 << " (1 euro)             2- " << prod2 << " (5 euros)              3- " << prod3 << " (50 euros)             4- " << prod4 << " (200 euros)" << endl;
        cout << "________________________________________________________________________________________________________________________" << endl << endl;
        cin >> escolhaProd;

    break;
    case 5:
    if(escolhaProd > 4 || escolhaProd < 1){
      cout << endl << endl << "Obrigado por fazer compras! Ate a proxima!" << endl << endl << endl;
      exit(0);
  }
  break;
}
    
}    
}else{
   cout << endl << "Nao tem dinheiro suficiente, experimente comprar algo mais barato!" << endl;
   break;
}
}
}


