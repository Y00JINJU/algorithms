#include <iostream>
#include <vector>

using namespace std;

int keySize, lockSize, boardSize;

void rotation(vector<vector<int> > &key){
    vector<vector<int> > rot (keySize, vector<int> (keySize));

    for(int j = keySize -1; j >= 0; j--){
        for (int i = 0; i < keySize; i++){
            rot[i][j] = key[keySize -j - 1][i];
        }
    }

    key = rot;
}

bool insert(int i, int j, vector<vector<int> > board, vector<vector<int> > key){

    for (int x = i; x < i + keySize; x++){
        for (int y = j; y < j + keySize; y++){
            board[x][y] += key[x-i][y-j];
        }
    }

    for (int i = keySize-1; i <= boardSize - keySize; i++){
        for (int j = keySize-1; j<=boardSize - keySize; j++){
            if (board[i][j] == 1) continue;

            return false;
        }
    }

    return true;
}

bool soultion(vector<vector<int> > key, vector<vector<int> > lock){
    bool answer = false;
    keySize = key.size();
    lockSize = lock.size();
    boardSize = lockSize + (keySize-1) *2;
    vector<vector<int> > board(boardSize, vector<int>(boardSize, 0));

    for (int i = keySize-1; i < boardSize - keySize; i++){
        for (int j = keySize-1; j < boardSize - keySize; j++){
            board[i][j] = lock[i-keySize+1][j-keySize+1];
        }
    }
    

    for (int k = 0; k < 4; k++){

        for (int i = 0; i < boardSize - keySize; i++){
            for (int j = 0; j < boardSize - keySize; j++){
                if (insert(i, j, board, key)){
                    answer = true;
                    return answer;
                }


            }
        }

        rotation(key);
    }

    return answer;

} 

int main(void){
    bool result;

    vector<vector <int> > key = { {0,0,1}, {1,0,0}, {0,1,1} };
    vector<vector <int> > lock = { {1,1,1}, {1,1,0}, {1,0,1} };


    result = soultion(key, lock);

    cout << result << endl;    
}