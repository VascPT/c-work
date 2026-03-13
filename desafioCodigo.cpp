#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

long temperature = 0;
#define SET_POINT 45

long randomizeTemperature(){
    //automatically randomize temperature between 1-100
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
    //randomize seed
    srand(time(0));
    //delay of 4 seconds, total of 10 times
    for(int i = 0; i < 10; i++){
    randomizeTemperature();
    aC();
    this_thread::sleep_for(chrono::seconds(4));
    }

    return 0;
}