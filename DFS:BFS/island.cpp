#include <iostream>
#include <string.h>
#include <vector>

#define MAX 52

using namespace std;

int w, h, answer;
vector<int> answers;
int visited[MAX][MAX];
int island[MAX][MAX];
int dir[8][2] = {{-1, -1}, {0, -1}, {1, -1}, 
                {-1, 0}, {1, 0},
                {-1, 1}, {0, 1}, {1, 1}};

void DFS(int x, int y){
    
    for(int i = 0; i < 8; ++i){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];

        if (dx < 0 || dx >= h || dy < 0 || dy >= w) continue;

        if (!visited[dx][dy] && island[dx][dy]){
            visited[dx][dy] = 1; 
            DFS(dx, dy);
        }
    }
}


int main(void){

    while(1){
        cin >> w >> h;
        
        if (w == 0 && h == 0) break;

        memset(visited, 0, sizeof(visited));
        memset(island, 0, sizeof(island));
        answer = 0;

        for (int i = 0; i < h; ++i){
            for (int j = 0; j < w; ++j){
                int LandOrSea;
                cin >> LandOrSea;
                
                island[i][j] = LandOrSea;
                
            }
        }

        for (int i = 0; i < h; ++i){
            for (int j = 0; j < w; ++j){
                
                if (!visited[i][j] && island[i][j]){
                    answer++;
                    DFS(i, j);
                }
            }
        }
        answers.push_back(answer);

    }

    for (int i = 0; i < answers.size(); ++i){
        cout << answers[i] << endl;
    }
}
