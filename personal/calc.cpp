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
string val;

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
    cout << "You entered: " << num1 << endl;
    
    


    return 0;
}