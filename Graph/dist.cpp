#include <iostream>
#include <queue>
#include <vector>

#define MAX_V 100001
#define INF 1e9

using namespace std;

int V, maxNode, maxValue;
vector<pair<int, int>> adj[MAX_V];

vector<int> dijkstra(int src){
    vector<int> dist(V+1, INF);
    dist[src] = 0;
    
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, src));
    maxValue = 0;
    maxNode = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;  // 가장 큰 값을 가장 작은 값을 만들기 위해서 
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) continue;

        cout << "dist[" << here << "]:: " << dist[here] << endl;

        for (int i = 0; i < adj[here].size(); ++i){
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;

            if (dist[there] > nextDist){ // 더 짧은 경로를 발견하면, dist를 갱신하고 우선순위 큐에 넣음 
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there)); // 그러고 다시 가장 작은 값을 큰 값으로 바꿈 
                if (dist[there] > maxValue){
                    maxValue = dist[there];
                    maxNode = there;
                }
            }

        }

    }
    return dist;
}

int main(void){
    cin >> V;

    for(int i = 0; i < V-1; ++i){
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    vector<int> answer;
    vector<int> result;

    answer = dijkstra(1);
    cout << "max node:: " << maxNode << endl;
    result = dijkstra(maxNode);

    for (int i= 1; i <= V; i++){
        cout << answer[i] << " ";
    }
    cout << "\n\n";
    cout << "from max node to far node:: " << endl;

    for (int i= 1; i <= V; i++){
        cout << result[i] << " ";
    }
    cout << endl;

}