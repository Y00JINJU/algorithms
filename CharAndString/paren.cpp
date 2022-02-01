#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
vector<string> v;

int main(void){
    cin >> N;

    for (int i = 0; i < N; ++i){
        string str;
        cin >> str;

        int check = 0;
        for(int j = 0; j < str.size(); ++j){
            if (str[j] == '(') {
                check += 1;
            }
            if (str[j] == ')') {
                check -= 1; 
            }
            if (check == -1) break;
        }

        if(check == 0) v.push_back("YES");
        else v.push_back("NO");

    }

    for (int i = 0; i < v.size(); ++i){
        cout << v[i] << endl;
    }
}