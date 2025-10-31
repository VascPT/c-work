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

float age;

void question(){
    clear();
    do{
    cout << "What is your age? ";
    cin >> age;
    sleep(1);
    clear();
    if (age == 1){
        cout << "Oh, you are " << age << " year old?" << endl; 
    }else{
    cout << "Oh, you are " << age << " years old?" << endl;
}

    sleep(1);
    
    if (age == 67){
        sleep(1);
        clear();
        cout << age << "!!!!!!!!!!!" << endl;
        break;
    }else if (age == 69){
        cout << age << "?" << endl;
        sleep(1);
        cout << "nice";
        break;
    }else if (age == 21){
        sleep (1);
        clear();
        cout << "u stoopid" << endl;
        break;
    }else if (age == 41){
        sleep(1);
        clear();
        cout << "do you also have 41 gold?" << endl;
        break;
    }

    if (age != 67 || 69 || 21 || 41){
        sleep(1);
        clear();        
        cout << "Wrong! Try again!" << endl;
        sleep(1);
    }
}while (age != 67 || 69 || 21 || 41);


}

int main(){
    clear();
    question();

}