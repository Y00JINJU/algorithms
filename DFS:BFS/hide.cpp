#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 100001

using namespace std;

int N, M;
int result = 0;
int dir[3] = {-1, 1, 2};
queue<pair<int, int>> q;
int visited[MAX];

int bfs(){
    while(!q.empty()){
        int dx;
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visited[x] = true;

        if (x == M) return y;
        
        cout << x << endl;

        for (int i = 0; i < 3; ++i){
            if (i == 2){
                dx = x * dir[i];
            }
            else dx = x + dir[i];

            if (!visited[dx] && x < MAX){
                q.push(make_pair(dx, y+1));
                visited[dx] = true;
            }
        }
    }
}


int main(void){
    scanf("%d %d", &N, &M);

    q.push(make_pair(N, 0));

    cout << bfs() << endl;
}