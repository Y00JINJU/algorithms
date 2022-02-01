#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int visit[9];
vector<int> a[10];

void dfs(int start){
    if (visit[start]) return;

    visit[start] = true;

    for (int i = 0; i < a[start].size(); i++){
        int x = a[start][i];
        cout << x << endl;
        dfs(x);
    }
}

int main(void){
    //아아 더블 어레이라서 각 인덱스에 연결된 노드들의 인덱스가 담겨있는거임 
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

    fill(visit, visit+10, false);

    dfs(1);

    return 0;

}