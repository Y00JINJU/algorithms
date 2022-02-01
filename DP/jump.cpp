#include <iostream>
#include <cstdlib>

using namespace std;

int c;
int n, board[100][100];
int cache[100][100];

int jump(int x, int y){
    if (x >= n || y >= n) return 0;
    if (x == n-1 && y == n-1) return 1;

    int& ret = cache[x][y];
    if (ret != -1) return ret;
    int jumpSize = board[x][y];
    return ret = jump(x + jumpSize, y) || jump(x, y+jumpSize);      // 방문했으면 해당 cache값에 ret값 넣기 
}

int main(void){
    cin >> c;
    for (int i = 0; i < c; ++i){
        cin >> n;
        memset(board, 0, sizeof(board));
        memset(cache, -1, sizeof(cache));

        for (int x = 0; x < n; ++x){
            for (int y = 0; y < n; ++y){
                int num;
                cin >> num;
                board[x][y] = num;
            }
        }

        int result = jump(0, 0);
        if (result == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}