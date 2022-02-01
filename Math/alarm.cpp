#include <iostream>
#include <cmath>

#define H_MAX 24
#define M_MAX 60

using namespace std;

int H, M;

int main(void){
    cin >> H >> M;

    if (M < 45){
        if (H == 0) H = 23;
        else H = H-1;
        M = (M+60) - 45;
    }
    else{
        M = M - 45;
    }

    cout << H << " " << M << endl;
}