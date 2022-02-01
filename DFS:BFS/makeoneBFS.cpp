#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 10000001

using namespace std;

int N, result;
queue<pair<int, int>> q;
int visited[MAX];

void bfs(int n){

    q.push(make_pair(n, 0));
    visited[n] = 1;

    while(1){
        int node = q.front().first;
        int value = q.front().second;

        if (node == 1){
            result = q.front().second;
            break;
        }

        q.pop();

        if (!visited[node-1]){
            q.push(make_pair(node-1, value + 1));
            visited[node -1] = 1;
        }

        if (!visited[node / 2] && node % 2 == 0){
            q.push(make_pair(node /2, value + 1));
            visited[node / 2] = 1;
        }

        if (!visited[node / 3] && node % 3 == 0){
            q.push(make_pair(node / 3, value + 1));
            visited[node / 3] = 1;
        }

    }
}


int main(void){
    cin >> N;

    memset(visited, 0, sizeof(visited));

    bfs(N);

    cout << result << endl;
}