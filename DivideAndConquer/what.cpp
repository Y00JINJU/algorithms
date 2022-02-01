#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> atmos) {
    int answer = -1;
    int maskCount = 0;
    
    for (int i = 0; i < atmos.size(); i++){
        //둘다안좋을때
        if (atmos[i][0] > 150 && atmos[i][1] > 75){
            answer ++;
            maskCount =0;
        }
        else if( atmos[i][0] < 81 && atmos[i][1] < 36){
            if (maskCount > 0){
                maskCount++;
            }
            if (maskCount == 3){
                maskCount = 0;
            }
        }
        else{
            if (maskCount == 0){
                answer++;
                maskCount++;
            }
            else maskCount ++;
            
        }
    }
    
    if (answer == -1) return 0;   
    return answer;
}

int main(void){
    vector<vector<int>> atmos;

    cin
}