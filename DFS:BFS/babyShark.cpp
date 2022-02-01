#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX 21
using namespace std;

int N;
int sea[MAX][MAX];
int visited[MAX][MAX];
int sharkX, sharkY;
int sharkSize = 2;
int cnt = 0;
int result = 0;
bool ateCheck = false;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void BFS(){
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;
    q.push(make_pair(sharkX, sharkY));
    visited[sharkX][sharkY] = 1;
    ateCheck = false;

    while(!q.empty()){
        int qSize = q.size();
        while(qSize--){
            int nx = q.front().first;
            int ny = q.front().second;

            q.pop();

            for (int i = 0; i < 4; ++i){
                int mx = nx + dir[i][0];
                int my = ny + dir[i][1];
                
                if (mx >= 0 && mx < N && my >= 0 && my < N && visited[mx][my] == 0){
                    
                    if (sea[mx][my] == 0 || sea[mx][my] == sharkSize){    // 상어 이동할 수 있는 범위
                        q.push(make_pair(mx, my));
                        visited[mx][my] = visited[nx][ny] + 1;
                    }                
                    else if (sea[mx][my] < sharkSize){   // 물고기 먹을 수 있을 경우
                        v.push_back(make_pair(mx, my));
                        visited[mx][my] = visited[nx][ny] + 1;
                    }
                }
            }
        }
        // 먹을 수 있는 상어가 여러마리 있을 경우 
        if (v.size() >= 1){   
            ateCheck = true;
            sort(v.begin(), v.end());
            sharkX = v[0].first;
            sharkY = v[0].second;
            sea[sharkX][sharkY] = 0;
            cnt++;
            result += visited[sharkX][sharkY] - 1;
            break;
        }   
    }
}

int main(void){
    cin >> N;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            cin >> sea[i][j];
            if (sea[i][j] == 9){
                sharkX = i; sharkY = j;
                sea[sharkX][sharkY] = 0;
            }
        }
    }

    while(1){
        BFS();
        memset(visited, 0, sizeof(visited));

        if (ateCheck == false) break;
        else if (cnt == sharkSize){ // 상어사이즈만큼 먹으면 1씩 상어크기는 자람 
            cnt = 0;
            sharkSize += 1;
        }
        
    }

    cout << result << endl;
}
