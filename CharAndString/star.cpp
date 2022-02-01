#include <iostream>
#include <string>

#define MAX 101;

using namespace std;

int N;

int main(void){
    cin >> N;
    string s;

    for(int i = 1; i <= N; ++i){
        s.append(i, '*');
        cout << s << endl;
        s.clear();
    }
}