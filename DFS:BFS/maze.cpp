#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define N_MAX 101

int n, m, in;
int maze[N_MAX][N_MAX];
int visited[N_MAX][N_MAX];
queue<pair<int, int>> q;
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; // 북남동서
int answer[N_MAX][N_MAX];

void bfs(){
    q.push(make_pair(0, 0));
    visited[0][0] = 1;
    answer[0][0] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        if (x == n-1 && y == m-1) break;

        q.pop();

        for (int i = 0; i < 4; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            
            if (dx >= 0 && dx < n && dy >= 0 && dy < m){
                if (visited[dx][dy] == 0 && maze[dx][dy] == 1){
                    visited[dx][dy] = 1;
                    answer[dx][dy] = answer[x][y] + 1;
                    q.push(make_pair(dx, dy));
                }
            }
        }   
    }
}


int main(void){

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            scanf("%1d", &maze[i][j]);
        }
    }
    
    bfs(); 

    cout << answer[n-1][m-1] << endl;
}