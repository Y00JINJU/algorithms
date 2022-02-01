#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001

using namespace std;

vector<int> v[MAX];
int answer[MAX];
bool visited[MAX];

int N;
int x, y;

void BFS(int start){
    queue<int> q;
    if (visited[start]) return;

    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for (int i = 0; i < v[node].size(); ++i){
            int newNode = v[node][i];
            
            if (!visited[newNode]){
                answer[newNode] = node;
                q.push(newNode);
                visited[newNode] = true;
            }
        }   
    }
}

int main(int argc, const char** argv) {
    cin >> N;

    for (int i = 0; i < N-1; ++i){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    BFS(1);

    for(int i = 2; i <= N; ++i){
        cout << answer[i] << " ";
    }
    cout << endl;
    
    return 0;

}
