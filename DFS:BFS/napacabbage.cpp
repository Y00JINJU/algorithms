#include <iostream>
#include <vector>
#include <string.h>
#define MAX 50

using namespace std;

int T, M, N, K;
int answer;
int arr[MAX][MAX];
int visited[MAX][MAX];
int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

void dfs(int y, int x){

    for (int i = 0; i < 4; i++){
        int dy = y + dir[i][0];
        int dx = x + dir[i][1];

        if (dy < 0 || dy > N-1 || dx < 0 || dx > M-1) continue;

        if(arr[dy][dx] == 1 && !visited[dy][dx]){
            visited[dy][dx] = 1;
            dfs(dy, dx);
        }
    }
}

int main(void){
    scanf("%d", &T);

    for (int i = 0; i < T; ++i){

        scanf("%d %d %d", &M, &N, &K);
        
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));

        answer = 0;

        for (int j = 0; j < K; ++j){
            int x, y;
            scanf("%d %d", &x, &y);
            arr[y][x] = 1;
        }

        for (int start = 0; start < N; ++start){
            for (int end = 0; end < M; ++end){
               // cout << arr[start][end] << " ";
                if (arr[start][end] == 1 && !visited[start][end]){
                    answer++;
                    visited[start][end] = 1;
                    dfs(start, end);
                }
            }
           // cout << endl;
        }

        printf("%d\n", answer);
    }

}