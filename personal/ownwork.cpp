#include <iostream>
#include <unistd.h>
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
    float age;
    cout << "What is your age? ";
    cin >> age;
    sleep(1);
    clear();
    cout << "Oh, you are " << age << " years old?" << endl;
    sleep(1);
    while (age != 67 || 69 || 21 || 41){
        cout << "Wrong! Try again! " << endl;
    }
}