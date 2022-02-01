#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>

#define MAX 1000001

using namespace std;

string str;
int big;
char answer;
map<char, int> m;

int main(void){
    cin >> str;
    
    for (int i = 65; i < 91; ++i){
        m.insert(make_pair(char(i), 0));
    }

    for (int i = 0; i < str.length(); ++i){        
        for (auto it = m.begin(); it!=m.end(); ++it){
            if (str[i] == it->first || str[i] == (char)tolower(it->first)){
                it->second++;
            }
        }
    }

    for (auto it = m.begin(); it!= m.end(); ++it){
        if (big != it->second){
            if (big < it->second){
                answer = it->first;
                big = it->second;
            }
        }
        else{
            answer = '?';
        }
    }

    cout << answer << endl;
}