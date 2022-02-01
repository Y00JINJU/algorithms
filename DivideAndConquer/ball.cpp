#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> ball, vector<int> order) {
    vector<int> answer;
    deque<int> dq;
    deque<int>::iterator iter;
    int next = 0;
    vector<vector<int>> priority;
    
    for (int i = 0 ; i < ball.size(); i++){
        dq.push_back(ball[i]);
    }

    for (int i = 0; i < order.size(); i++){
        //cout << order[i] << " " << dq[0] << " " << dq[dq.size()-1] << endl;
       
        if (!priority.empty()){
            for (int k = 0; k < priority.size(); k++){
                if (dq[0] == priority[k][0]){
                    dq.pop_front();
                    answer.push_back(priority[k][0]);
                    cout << order[priority[k][1]] << endl;
                    order.erase(order.begin()+priority[k][1]);
                    i = priority[k][1] -1;
                }
                else if (dq[dq.size()-1] == priority[k][0]){
                    dq.pop_back();
                    answer.push_back(priority[k][0]);
                    cout << order[priority[k][1]] << endl;
                    //order.erase(order.begin()+priority[k][1]);
                    i = priority[k][1]-1;
                }
            }
        }
        
        if (dq[0] == order[i]){
            dq.pop_front();
            answer.push_back(order[i]);
            order.erase(order.begin()+i);
            i--;
            cout << "처음 원소 같아서 지움" << endl;
        }
        else if (dq[dq.size()-1] == order[i]){
            dq.pop_back();
            answer.push_back(order[i]);
            order.erase(order.begin()+i);
            i--;
            cout << "끝 원소 같아서 지움" << endl;
        }
        else{
            vector<int> v = {order[i], i};
            priority.push_back(v);
            cout << "넣음" << endl;
        }
        
    }
    return answer;
}

int main(void){
    vector<int> ball = {11, 2, 9, 13, 24};
    vector<int> order = {9, 2, 13, 24, 11};
    vector<int> answer;

    answer = solution(ball, order);

    for (int i = 0; i < answer.size(); i++){
        cout << answer[i] << " " ;
    }

    cout << endl;


}