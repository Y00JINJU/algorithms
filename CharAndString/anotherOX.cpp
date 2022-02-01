#include <iostream>
#include <string>
#include <cstring>

#define MAX 81

using namespace std;

int N;
int sum, result;

int main(void){
    cin >> N;


    for (int i = 0; i < N; ++i){
        string s;
        sum = 0, result = 0;
        
        cin >> s;

        for(int j = 0; j < s.length(); ++j){
            if (s[j] == 'O'){
                sum += 1;
                result += sum;
            }
            else{
                sum = 0;
            }
        }

        cout << result << endl;
    }

}