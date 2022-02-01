#include <iostream>
#include <cmath>

#define MAX 2147483648

using namespace std;

int A, B, C, BEPoint;

int main(void){
    
    cin >> A >> B >> C;

    if (B > C || (C-B) == 0){
        cout << -1 << endl;
        return 0;
    }
    
    BEPoint = A / (C-B);
    cout << ++BEPoint << endl;
}