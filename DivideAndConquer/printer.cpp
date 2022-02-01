#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){
    vector<int> priorities;
    int location = 0;
    int answer = 1;

    priorities.push_back(1);
    priorities.push_back(1);
    priorities.push_back(9);
    priorities.push_back(1);
    priorities.push_back(1);
    priorities.push_back(1);

    int out = priorities[location];
    
    for (int i = 0; i < priorities.size(); i++){
        cout << "i:: " << i << endl;

        if (i == location){
            continue;
        }
        if (out >= priorities[i]){
            answer++;
            cout << "answer :: " << answer << endl;
        }
    }
    
    cout << answer << endl; 
    
}