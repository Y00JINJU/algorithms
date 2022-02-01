 #include <iostream>
 #include <string>
 #include <cstdlib>
 
 using namespace std;

string N, str1, sum;
int result = 0;

int main(void){
    cin >> N;

    if (N == "0"){
        cout << "1" << endl;
        return 0;
    }

    if (N.length() < 2){
        N.insert(0, "0");
    }

    str1 = N;

    while(1){
        sum = to_string(str1[0] - '0' + str1[1] - '0');
        if (sum.length() < 2){
            sum.insert(0, "0");
        }
        string newStr = str1;
        str1 = "";
        str1 = to_string(newStr[1]-'0') + to_string(sum[1]-'0');
        result++;
        if (str1 == N){
            break;
        }
    }

    cout << result << endl;
}