#include <iostream>
#include <string.h>
#include <vector>
#include <stack>

#define MAX 1001

using namespace std;

int N, M, connect;
vector<int> vec[MAX];
int visited[MAX];

void DFS(int start){

    stack<int> s;
    s.push(start);
    visited[start] = 1;

    connect++;
    
    while(!s.empty()){
        int node = s.top();
        s.pop();

        for (int i = 0; i < vec[node].size(); ++i){
            int next = vec[node][i];

            if (!visited[next]){
                visited[next] = 1;
                s.push(node);
                s.push(next);
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
            DFS(i);
    }

    cout << connect << endl;
    
}