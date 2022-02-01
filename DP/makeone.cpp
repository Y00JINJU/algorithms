#include <iostream>
#include <cstdlib>
#include <algorithm>

#define MAX 10000001

using namespace std;

int N;
int DP[MAX];

int main(void){
    cin >> N;

//    memset(DP, 0, sizeof(DP));
    DP[1] = 0;
    
    for (int i = 2; i <= N; ++i){
        DP[i] = DP[i-1] + 1;

        if (i % 2 == 0)
            DP[i] = min(DP[i / 2] + 1, DP[i]);

        if (i % 3 == 0)
            DP[i] = min(DP[i / 3] + 1, DP[i]);
    }

    cout << DP[N] << endl;

}