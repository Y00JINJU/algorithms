#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, vector<int> v[], bool visited[]){
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << endl;

        for (int i = 0; i < v[node].size(); i++){
            int next = v[node][i];

            if (visited[next] == false){
                q.push(next);
                visited[next] = true;
            }
    }
}

int main(void){
    vector<int> a[10];
    bool visited[9];

    a[1].push_back(2);
    a[2].push_back(1);

    a[1].push_back(3);
    a[3].push_back(1);

    a[2].push_back(3);
    a[3].push_back(2);

    a[2].push_back(4);
    a[4].push_back(2);

    a[2].push_back(5);
    a[5].push_back(2);

    fill(visited, visited+10, false);

    bfs(1, a, visited);

    return 0;
}