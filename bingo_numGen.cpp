#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#ifdef WIN32_
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
//track numbers that have been drawn
bool drawn[TOTAL_NUMS + 1] = {false};
//store up to 5 numbers
int recentNumbers[5];
//how many numbers are currently stored
int recentCount = 0;

void showNumbers(){
    //shows all the 100 nums
    for(int i=1; i<=TOTAL_NUMS; i++){
       if (drawn[i]) {
            //drawn nums
            cout << YELLOW << i << " ";
        } else {
            //regular nums
            cout << CYAN << i << " ";
        }
        //Makes lines of 20
        if (i % PER_LINE == 0){
        cout << "\n";
    }
    }
}
void addtoRecent(int num) {
    //shift all numbers to the left making room at the end
    //removes the oldest number
    for (int i = 0; i < 4; i++) {
        recentNumbers[i] = recentNumbers[i + 1];
    }
    //add new number at the end (most recent)
    recentNumbers[4] = num;
    //update count (max at 5)
    if (recentCount < 5) {
        recentCount++;
    }
}

void showRecentNumbers() {
    if (recentCount == 0) {
        cout << PURPLE << "Recent numbers (last 5): None yet" << RESET;
        return;
    }
    
    cout << PURPLE << "Recent numbers (last 5): ";
    
    //only show the actual numbers we have
    int startIndex = 5 - recentCount;//show from where we have valid data
    for (int i = startIndex; i < 5; i++) {
        cout << recentNumbers[i];
        if (i < 4) {
            cout << ", ";
        }
    }
    cout << RESET;
}

int drawrandNum(){
    vector<int> pool;
    //list of nums that have not been drawn yet
     for (int i = 1; i <= TOTAL_NUMS; i++) {
        if (!drawn[i]) {
            pool.push_back(i);
        }
    }

    if (pool.empty())
        return -1; //no more nums left

    int index = rand() % pool.size();
    int num = pool[index];

    drawn[num] = true; //mark number as drawn (yellow)
    addtoRecent(num);
    return num;
}

int main(){
    srand(time(NULL));
    clear();
    cout << endl << "Welcome to BINGO! Here is the table of numbers. Good luck!" << endl << endl;
    showNumbers();
    //initialize recent numbers array
    for (int i = 0; i < 5; i++) {
        recentNumbers[i] = 0;  //0 means empty slot
    }
    cout << RESET << "Press enter to rool a number ";
    //press enter to continue
    cin.ignore();
     while (true) {
        clear();

        int num = drawrandNum();

        if (num == -1) {
            cout << YELLOW << "\nAll numbers have been drawn!" << RESET << endl;
            break;
        }

        cout << "Number drawn: " << YELLOW << num << RESET << "\n\n";

        showNumbers();
        cout << "\n";
        showRecentNumbers();
        cout << RESET << "\nPress ENTER to draw again ";
        cin.ignore();
    }

    return 0;
}