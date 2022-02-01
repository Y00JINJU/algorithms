#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int start, vector<int> v[], bool visited[]){
    
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty()){

        //현재 노드 stack에 넣어주기
        int node = s.top();
        cout << node << endl;
        s.pop();

        for (int i = 0 ; i < v[node].size(); i++){
            // 다음 노드 가져오기 
            int next = v[node][i];

            if (visited[next] == false){
                visited[next] = true;
                // pop 해줘서 현재 노드도 Push해줘야함 
                s.push(node);
                s.push(next);
                break;
            }
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

    dfs(1, a, visited);

    return 0;
}