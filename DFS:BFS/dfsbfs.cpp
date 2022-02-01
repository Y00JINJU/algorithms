#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

#define N_MAX 1001

using namespace std;

vector<int> v[N_MAX];
int visited[N_MAX];
int visited2[N_MAX]; 
queue<int> q;

void dfs(int start){
    visited[start] = true;
    printf("%d ", start);
    for (int i = 0; i < v[start].size(); ++i){
        int node = v[start][i];
        if (visited[node] == false) dfs(node);
    }
}

void bfs(int start){
    visited2[start] = true;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        printf("%d ", node);

        for (int i = 0; i < v[node].size(); ++i){
            int next = v[node][i];
            if (visited2[next] == false){
                visited2[next] = true;
                q.push(next);
            }
        }
    }
}

int main(void){
    int m, n, start;
    int a, b;

    scanf("%d %d %d", &m, &n, &start);

    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    } 

    for(int i = 0; i <= m; ++i){
        sort(v[i].begin(), v[i].end());
    }

    dfs(start);
    cout << endl;

    bfs(start);
    cout << endl;
    return 0;
}