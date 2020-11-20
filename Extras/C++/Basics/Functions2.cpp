#include <iostream>
#include <string>
#include <locale>
#include <math.h>

using namespace std;
void season(int day, int month) {
    string season;
    if (month <= 3)
    {
        season = "Winter";
    }

    else if (month >= 4 && month <= 6)
    {
        season = "Spring";
    }

    else if (month >= 7 && month <= 9)
    {
        season = "Summer";
    }

    else if (month >= 10 && month <= 12)
    {
        season = "Fall";
    }


    if (month == 3  && day >= 19) {
            season = "Spring";
        }

    if(month == 6 && day >= 20){
            season = "Summer";
        }

    if(month == 9 && day >=22){
            season = "Fall";
        }


    if(month == 12 && day >=21){
            season = "Winter";
     }

    std::cout << "It is " << season << "!";
}

int main() {
    int month, day;
    std::cout << "Enter a month: ";
    cin >> month;
    std::cout << "Enter a day: ";
    cin >> day;
    season(day, month);
}