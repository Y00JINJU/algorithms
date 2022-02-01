#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;

int N, M;
int result;
int tomato[MAX][MAX];
queue<pair<int, int>> q;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if (dx >= 0 && dx < N && dy >= 0 && dy < M){
                if (tomato[dx][dy] == 0){
                    tomato[dx][dy] = tomato[x][y] + 1;
                    q.push(make_pair(dx, dy));
                }
            }
        }
    }
}

int main(void){
    scanf("%d %d", &M, &N);

    for(int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            scanf("%d", &tomato[i][j]);
            if (tomato[i][j] == 1){
                q.push(make_pair(i, j));
            }
        }
    }

    bfs();

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if (tomato[i][j] == 0){
                cout << -1 << endl;
                return 0;
            }
            if (result < tomato[i][j]){
                result = tomato[i][j];
            }
        }
    }
    cout << result-1 << endl;
    return 0;
}
