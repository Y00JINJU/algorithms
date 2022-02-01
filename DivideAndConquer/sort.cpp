#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> boxes) {
    int answer = 0;
    int x, y = 0;
    
    for (int i = 0; i < boxes.size(); i++){
        x = boxes[i][0];
        int j = 0;
        cout << "x:: " << x << endl;
        if (x == boxes[i][1]) continue;
        while (j < boxes.size()){
            cout << "j:: " << j << endl;
            cout << boxes[j][0] << "     " << boxes[j][1] << endl;
            if (i == j) {
                cout << "i, j 같음" << endl;
                j++;
                continue;
            }
            if (x == boxes[j][0] || x == boxes[j][1]){
                cout << "같은 쌍 차즘" << endl;
                break;
            }
            else{
                cout << "목찾음 " << answer << endl; 
                j++;
                answer++;
            }
        }
        
    }
    
    return answer;
}


int main(void){
    vector<vector<int> > v = {{1, 2}, {2, 1}, {3, 3}, {4, 5}, {5, 6}, {7, 8}};
    int answer;

    answer = solution(v);

    cout << answer << endl;

}