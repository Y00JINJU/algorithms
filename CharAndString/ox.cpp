#include <iostream>
#include <string>
#include <vector>

#define MAX 100

using namespace std;

int N;
vector<string> v;
int answer[MAX][MAX] = {0, };
int sum = 0;

void solution(){
    for(int i =0; i < N; ++i){
        for (int j = 0; j < v[i].size(); ++j){
            if (v[i][j] == 'O'){
                if (j == 0){
                    answer[i][j] = 1;
                }
                else{
                    answer[i][j] = answer[i][j-1] + 1;

                }
            }
            else {
                answer[i][j] = 0;
            }
        }
    }
}

int main(void){
    cin >> N;

    for (int i = 0; i < N; ++i){
        string s;
        cin >> s;
        v.push_back(s);
    }

    solution();

    for (int i = 0; i < N; ++i){
        sum = 0;
        for (int j = 0; j < v[i].size(); ++j){
            sum += answer[i][j];
        }
        cout << sum << endl;
    }
}