#include <iostream>
#include <cstdlib>

using namespace std;

int C, N;
string W, S;
int cached[101][101];

int matchedMemorized(int w, int s){
    
    int& ret = cached[w][s];
    if (ret != -1) return ret;

    while(s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])){
        return ret = matchedMemorized(w+1, s+1);
    }

    if (W[w] == '*'){
        if (matchedMemorized(w+1, s) || (s < S.size() && matchedMemorized(w, s+1)))
            return ret = 1;
    }

    return ret = 0;
}

int main(void){
    cin >> C;
    
    for (int i = 0; i < C; ++i){
        cin >> W;
        cin >> N;
        for (int j = 0; j < N; ++j){
            cin >> S;
            int result = matchedMemorized(0, 0);
            if (result == 1) cout << S << endl;
        }
    }
       
}