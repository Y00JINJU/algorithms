#include <iostream>
#include <vector>
#define N_MAX 101

using namespace std;

int N, M;
int u, v;
vector<int> computer[N_MAX];
int visited[N_MAX] = {0,};
int warm;

void dfs(int start){
    if (visited[start]) return;

    visited[start] = true;
    warm++;

    for(int i = 0; i < computer[start].size(); ++i){
        int node = computer[start][i];
        dfs(node);
    }
}

int main(void){
    scanf("%d", &N);
    scanf("%d", &M);

    for(int i = 0 ; i < M; ++i){
        scanf("%d %d", &u, &v);
        computer[u].push_back(v);
        computer[v].push_back(u);
    }

    dfs(1);

    printf("%d\n", warm-1);
    return 0;
}
