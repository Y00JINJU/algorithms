#include <iostream>
#include <string>

using namespace std;

int N;
int result;


int main(void){
    cin >> N;
    int nums[101] = {0,};

    for(int i = 0; i < N; ++i){
        scanf("%1d", &nums[i]);
        result += nums[i];
    }
  
    cout << result << endl;
}