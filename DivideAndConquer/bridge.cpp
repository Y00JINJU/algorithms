#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights){
   int answer = 0; 
    queue<pair<int, int> > bridge;
    int next = 0 , w = 0;
    int size = truck_weights.size();
    
    while (1){
        
        if (answer - bridge.front().second == bridge_length){
            w -= bridge.front().first;
            bridge.pop();
        }
        
        if (next < size && w + truck_weights[next] <= weight ){
            bridge.push(make_pair(truck_weights[next], answer));
            w += truck_weights[next];
            next++;
        }
        
        answer ++;
        
        if (next == size && bridge.empty() ){
            break;
        }
        
    }
    
    return answer;

}

int main(void){
    vector<int> truck_weights;
    int weight = 10;
    int bridge_legnth = 2;

    truck_weights.push_back(7);
    truck_weights.push_back(4);
    truck_weights.push_back(5);
    truck_weights.push_back(6);

    cout << solution(bridge_legnth, weight, truck_weights) << endl;;


}