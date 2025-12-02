#include <iostream>
#ifdef WIN32
        #include <windows.h>
    #else
        #include <unistd.h>
    #endif
using namespace std;
#define TOTAL_NUMS 100
#define PER_LINE 20
//colors for numbers
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

void showNumbers(){
    //shows all the 100 nums
    for(int i=1; i<=TOTAL_NUMS; i++){
        cout << CYAN << i << " ";
        //Makes lines of 20
        if (i % PER_LINE == 0){
        cout << "\n";
    }
    }
}


int main(){
    clear();
    cout << endl << "Welcome to BINGO! Here is the table of numbers. Good luck!" << endl << endl;
    showNumbers();
    cout << RESET << "Press enter to contnue" << endl;
    //press enter to continue
    cin.ignore();

    return 0;
}