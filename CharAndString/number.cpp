#include <iostream>
#include <string>
#include <vector>

#define MAX 1001

using namespace std;

int A, B, C;
int mul;
string str;
int answer[10];

int main(void){
    cin >> A >> B >> C;

    mul = A * B * C;


    str = to_string(mul);


    for(int i = 0; i <= 9; ++i){
        char check = '0' + i;
        for (int j = 0; j < str.length(); ++j){
            if (check == str[j]){
                int put = answer[i] += 1;
                answer[i] = put;
            }
        }
    }

    for (int i = 0 ; i < 10; ++i){
        cout << answer[i] << endl;
    }

}