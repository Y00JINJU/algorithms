#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

#define MAX 1001

using namespace std;

int N, M;
int visited[MAX][MAX][2]; // 0은 벽 부숨 1은 벽 안 부숨
int wall[MAX][MAX];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int BFS(int x, int y){
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(x, y), 1));
    visited[x][y][1] = 1;

    while(!q.empty()){
        int dx = q.front().first.first;
        int dy = q.front().first.second;
        int brokeCheck = q.front().second;

        q.pop();

        if (dx == N-1 && dy == M-1){
            return visited[N-1][M-1][brokeCheck];
        }

        for(int i = 0; i < 4; ++i){
            int nx = dx + dir[i][0];
            int ny = dy + dir[i][1];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M){
                if (wall[nx][ny] && brokeCheck){
                    visited[nx][ny][brokeCheck-1] = visited[dx][dy][brokeCheck] + 1;
                    q.push(make_pair(make_pair(nx, ny), brokeCheck-1));
                }
                if (!wall[nx][ny] && !visited[nx][ny][brokeCheck]){
                    visited[nx][ny][brokeCheck] = visited[dx][dy][brokeCheck] + 1;
                    q.push(make_pair(make_pair(nx, ny), brokeCheck)); 
                }
            }
        }
    }

    return -1;
}

int main(void){
    cin >> N >> M;

    for (int i = 0; i < N; ++i){
        string input;
        cin >> input;
        for (int j = 0; j < M; ++j){
            if (input[j] == '0')
                wall[i][j] = 0;
            else if (input[j] == '1')
                wall[i][j] = 1;
        }
    }

    cout << BFS(0,0) << endl;

}