#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter); 

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    int count= 0;
    
      for (int i = 0; i < query.size(); i++){
        vector<string> que = split(query[i], ' ');
        for (int j = 0 ; j < info.size(); j++){
            vector<string> inf = split(info[j], ' ');
            cout << "r:: " << j << endl;
            if (que[0] == "-" || que[0] == inf[0]){
                cout << que[0] << ", " << inf[0] << endl;

                if (que[1] == "-" || que[1] == inf[1]){
                    cout << que[1] << ", " << inf[1] << endl;

                    if (que[2] == "-" || que[2] == inf[2]){

                        cout << que[2] << ", " << inf[2] << endl;
                        if (que[3] == "-" || que[3] == inf[3]){

                            cout << que[3] << ", " << inf[3] << endl;
                            
                            if (ssInt(que[4]) <= ssInt(inf[4])){
                                cout << que[4] << ", " << inf[4] << endl;
                                count ++;
                                cout << "count :: " << count << endl;
                            }
                        }
                    }
                }
            } 
        }
        answer.push_back(count);
        count = 0;
        cout << endl;
    }
    
    return answer;
}

vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delimiter)) {
        if (temp != "and"){
             internal.push_back(temp);
        }
    }
 
    return internal;
}

int main(void){
    vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string> query =  {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
    vector<int> out;

    out = solution(info, query);

    cout << "===== answer =======" << endl;
    for (int i = 0; i < out.size(); i++){
        cout << out[i] << " " ;
    }
    cout << endl;
    
}