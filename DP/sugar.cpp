#include <iostream>
#include <cstdlib>

#define MAX 5001

using namespace std;

int N;
int div5, div3;

int main(void){
    cin >> N;

    div5 = N / 5;

    while(1){
        if (div5 < 0){
            cout << -1 << endl;
            return 0;
        }
        if ((N - (div5 * 5)) % 3 == 0){
            div3 = (N - (div5 * 5)) / 3;
            break;
        }
        div5--;
    }

    cout << div5+div3 << endl;
    return 0;
}