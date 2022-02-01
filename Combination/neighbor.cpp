#include <iostream>
#include <algorithm>
#define MAX 100000

using namespace std;

int apart[MAX][15];
int T, result, a, b;

void solution(int floor, int room){

    apart[floor][room] = apart[floor][room-1] + apart[floor-1][room];
    
    if (room == b) return ;
    else solution(floor, room+1);
}

int main(void){
    cin >> T;

    for (int i = 1; i <= 14; ++i){
        apart[0][i] = i;
    }

    for (int i = 0; i < T; ++i){
        cin >> a >> b;
        fill(&apart[1][0], &apart[a][b], 0);
        for (int j = 1; j <= a; ++j){
            solution(j, 1);
        }
        cout << apart[a][b] << endl;
    }
}