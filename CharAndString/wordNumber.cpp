#include <iostream>
#include <string>


using namespace std;

string s;
int result = 1;

int main(void){
    getline(cin, s);

    for (int i = 0; i < s.length(); ++i){
        if (i !=0 && i != s.length()-1 && s[i] == ' ')
            result += 1;
    }

    if (s.length() == 1 && s[0] == ' ') result = 0;

    cout << result << endl;
}
