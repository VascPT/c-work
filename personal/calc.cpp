#include <iostream>
#include <limits>
using namespace std;
#define RESET "\033[0m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define WHITE "\033[37m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define PURPLE "\e[0;35m"
void clear(){
    #ifdef WIN32
        system("CLS");
    #else
        system("clear");
    #endif
}

float num1;
float num2;
char op;

int main(){
    clear();
    cout << BLUE << "Write the first number: " << RESET;
    while (!(cin >> num1))
    {
        // reset the status of the stream
        cin.clear();
        // ignore remaining characters in the stream
        cin.ignore();
        clear();
        cout << RED << "Calc only accepts numbers!" << RESET << endl;
        cout << BLUE << "Write the first number: " << RESET;
    }
    clear();
    cout << BLUE << "What operator you want? (This calc only accepts +, -, *, /): " << RESET << endl;
    cin >> op;

    while(op != '+' && op != '-' && op != '*' && op != '/'){
    clear();
    cout << RED << "This isn't an operator! Write a valid one(+, -, *, /): " << RESET;
    cin >> op;
    }
    clear();
    cout << BLUE << "Write the second number: " << RESET;
    while (!(cin >> num2))
    {
        // reset the status of the stream
        cin.clear();
        // ignore remaining characters in the stream
        cin.ignore();
        clear();
        cout << RED << "Calc only accepts numbers!" << RESET << endl;
        cout << BLUE << "Write the first number: " << RESET;
    }

    float result;
    switch(op){
        case '+':
            result = num1 + num2;
        break;
        case '-':
            result = num1 - num2;
        break;
        case '*':
            result = num1 * num2;
        break;
        case '/':
            result = num1 / num2;
        break;

    }

    cout << PURPLE << "The result is " << YELLOW << result << RESET << endl;

    return 0;
}