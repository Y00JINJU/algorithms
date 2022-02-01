#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans;

  
    if (v[0][0] == v[1][0]) {
        ans.push_back(v[2][0]);
    }
    else if (v[0][0] == v[2][0]){
        ans.push_back(v[1][0]);
    }
    else{
        ans.push_back(v[0][0]);
    }

     if (v[0][1] == v[1][1]) {
        ans.push_back(v[2][1]);
    }
    else if (v[0][1] == v[2][1]){
        ans.push_back(v[1][1]);
    }
    else{
        ans.push_back(v[0][1]);
    }
    

    return ans;
}

int main(void){
    vector<vector<int> > v;
    vector<int> ans;

    v = {{1, 4}, {3, 4}, {3, 10}};

    ans = solution(v);

    for (int i = 0; i < v.size()- 1; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}