#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

long temperature = 0;
#define SET_POINT 45

long randomizeTemperature(){
    temperature = rand() % 100;
    cout << "Temperature: " << temperature << endl;
    
    return temperature;
}

void aC(){
      if(temperature >= SET_POINT){
        cout << "AC on!" << endl;
    }else{
        cout << "AC off!" << endl;
    }
}

int main(){
    srand(time(0));
    //delay of 4 seconds
    for(int i = 0; i < 10; i++){
    randomizeTemperature();
    aC();
    this_thread::sleep_for(chrono::seconds(4));
    }

  
    return 0;
}