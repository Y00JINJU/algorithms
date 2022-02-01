// 실패!!!!!!!!!!!!!!!!!!!!!! 다음에 다시 풀어본다 ㅠㅠㅠ 몬말이야 대체 

#include <iostream>
#define MAX 31
using namespace std;

int T, N, M;
int DP[MAX][MAX];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 30; ++i){
        DP[i][1] = i;
    }
    
    for (int i = 2; i < 30; ++i){
        for (int j = i; j <= 30; ++j){
            for (int k = j; k >= j; --k){
                DP[i][j] += DP[i-1][k-1];    // DP[3][5] = DP[2][4] + DP[2][3] + DP[2][2]
            }
        }
    }
    
    cin >> T;
    
    for (int i = 0; i < T; ++i){
        cin >> N >> M;        
        cout << DP[N][M] << endl;
    }
}