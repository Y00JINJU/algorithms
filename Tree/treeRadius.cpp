#include <iostream>
#include <vector>
#include <queue>

#define MAX 10001

using namespace std;

int N;
vector<pair<int, int>> adj[MAX];
int maxNode, maxValue;

void dijkstra(int start){
    vector<int> dist(N+1, MAX);
    dist[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    maxNode = 0;
    maxValue = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) continue;

        for (int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;

            if (dist[there] > nextDist){
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
                if (dist[there] > maxValue){
                    maxNode = there;
                    maxValue = dist[there];
                }
            }
        }

    }
}

int main(void){
    cin >> N;

    for (int i = 0; i < N-1; i++){
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    dijkstra(3);
    dijkstra(maxNode);

    cout << maxValue << endl;
    
}