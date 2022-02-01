#include <iostream>
#include <deque>

#define MAX 101

using namespace std;

int N,M;
int visited[MAX][MAX];
int algospot[MAX][MAX];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
 
int BFS(int x, int y){
    deque<pair<pair<int, int>, int>> dq;
    dq.push_front(make_pair(make_pair(x, y), 0));
    visited[x][y] = 1;

    while(!dq.empty()){
        int dx = dq.front().first.first;
        int dy = dq.front().first.second;
        int isWall = dq.front().second;

        dq.pop_front();

        if (dx == M-1 && dy == N-1) return isWall;

        for(int i = 0; i < 4; ++i){
            int nx = dx + dir[i][0];
            int ny = dy + dir[i][1];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N){
                if (algospot[nx][ny] == 0 && !visited[nx][ny]){
                    visited[nx][ny] = 1;
                    dq.push_front(make_pair(make_pair(nx, ny), isWall));
                }

                if (algospot[nx][ny] == 1 && !visited[nx][ny]){
                    visited[nx][ny] = 1;
                    dq.push_back(make_pair(make_pair(nx, ny), isWall+1));
                }
            }
        }
    }
    return 0;
}

int main(void){
    cin >> N >> M;
    
    for (int i = 0; i < M; ++i){
        string wall;
        cin >> wall;
        for (int j = 0; j < N; ++j){
            if (wall[j] == '0'){
                 algospot[i][j] = 0;
            }
            if (wall[j] == '1'){
                algospot[i][j] = 1;
            }
        }
    }

    cout << BFS(0, 0) << endl;
}