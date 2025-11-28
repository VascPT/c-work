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
float num1;
float num2;
string op;

int main(){
    clear();
    cout << "Write the first number: ";
    while (!(cin >> num1))
    {
        // reset the status of the stream
        cin.clear();
        // ignore remaining characters in the stream
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        clear();
        cout << "Calc only accepts numbers!" << endl;
        cout << "Write the first number: ";
    }
    clear();
    cout << "What operator you want? (This calc only accepts +, -, *, /): " << endl;
    cin >> op;

    do{
        cout << "Operator chosen: " << op << endl;
    }while(op != "+", "-", "*","/");




    /*while (!(cin >> op))
    {
        // reset the status of the stream
        cin.clear();
        // ignore remaining characters in the stream
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        clear();
        cout << "What operator you want? (This calc only accepts +, -, *, /): ";
    }*/
    

    


    return 0;
}