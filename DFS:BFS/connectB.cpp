// 아 이문제는 DFS라서 BFS로 안풀리는 것 같아 


#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

#define MAX 1001

using namespace std;

int N, M, connectB;
vector<int> vec[MAX];
int visited[MAX];

void BFS(int start){
    
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    cout << "start :: " << start << endl;
    connectB++;

    while(q.empty()){
        int node = q.front();
        q.pop();

        for (int i = 0; i < vec[node].size(); ++i){
            int next = vec[node][next];

            if (!visited[next]){
                visited[next] = 1;
                q.push(next);
            }
        }
    }
}

int main(void){
    cin >> N >> M;

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < M; ++i){
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i){
        if (!visited[i])
            BFS(i);
    }

    cout << connectB << endl;
}