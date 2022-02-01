#include <iostream>
#define MAX 4001

using namespace std;

int year = 0;

int main(void){
    cin >> year;

    if (year % 4 == 0 && ((year % 100 != 0 || year % 400 == 0))){
        cout << 1 << endl;
    }
    else cout << 0 << endl;
}