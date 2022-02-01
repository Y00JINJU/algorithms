#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define N_MAX 25

using namespace std;

int N;
int house[N_MAX][N_MAX];
int visited[N_MAX][N_MAX];
int address;
vector<int> houseNumber;
queue<pair<int, int>> q;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(int u, int v){
    int dx, dy;
    q.push(make_pair(u, v));
    visited[u][v] = 1;
    address += house[u][v];

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; ++i){

            dx = x + dir[i][0];
            dy = y + dir[i][1];

            if (dx >= 0 && dx < N && dy >= 0 && dy < N){
                if (!visited[dx][dy] && house[dx][dy]){
                    visited[dx][dy] = 1;
                    address += 1;
                    q.push(make_pair(dx, dy));
                }
            }
        }
    }
}


int main(void){
    scanf("%d", &N);

    for(int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            scanf("%1d", &house[i][j]);
        }
    }

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            if (!visited[i][j] && house[i][j]){
                bfs(i, j);
                houseNumber.push_back(address);
                address = 0;
            }
        }
    }

    printf("%lu\n", houseNumber.size());
    sort(houseNumber.begin(), houseNumber.end());

    for(int i = 0; i < houseNumber.size(); ++i){
        printf("%d\n", houseNumber[i]);
    }
}