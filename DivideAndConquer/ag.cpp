#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int> > board, vector<int> moves) {
    int answer = 0;
    int next = 0;
    int top = 0;
    stack<int> basket;

    for (int i = 0; i < moves.size(); i++){
        cout << endl;
        cout << "i: " << i << endl;
        cout << endl;
        while(true){
            if (next == board.size()) break; 
            if (board[next][moves[i]-1] == 0) next++;
            else{
                cout << "move: " << moves[i]-1 << "  next: " << next << endl; 
                cout << "board: " << board[next][moves[i]-1] << endl;
                if (!basket.empty()){
                    top = basket.top();
                    cout << "이전 top: " << top << endl;
                }

                basket.push(board[next][moves[i]-1]);
                cout << "현재 top: " << basket.top() << endl;

                if (!basket.empty() && basket.top() == top){
                    basket.pop();
                    cout << "pop1: " << basket.top() << endl;
                    basket.pop();
                    cout << "pop2: " << basket.top() << endl;

                    answer += 2;
                    
                    cout << "answer:: " << answer << endl;
                }
                board[next][moves[i]-1] = 0;
                next = 0;
                break;
            }
        }
    }
    return answer;
  
}

int main(void){
    vector<vector<int> > board;
    vector<int> moves;
    
    vector<int> b1;
    vector<int> b2;
    vector<int> b3;
    vector<int> b4;
    vector<int> b5;

    b1.push_back(0);
    b1.push_back(0);
    b1.push_back(0);
    b1.push_back(0);
    b1.push_back(0);
    
    b2.push_back(0);
    b2.push_back(0);
    b2.push_back(1);
    b2.push_back(0);
    b2.push_back(3);
    
    b3.push_back(0);
    b3.push_back(2);
    b3.push_back(5);
    b3.push_back(0);
    b3.push_back(1);
    
    b4.push_back(4);
    b4.push_back(2);
    b4.push_back(4);
    b4.push_back(4);
    b4.push_back(2);
    
    b5.push_back(3);
    b5.push_back(5);
    b5.push_back(1);
    b5.push_back(3);
    b5.push_back(1);

    board.push_back(b1);
    board.push_back(b2);
    board.push_back(b3);
    board.push_back(b4);
    board.push_back(b5);
    
    moves.push_back(1);
    moves.push_back(5);
    moves.push_back(3);
    moves.push_back(5);
    moves.push_back(1);
    moves.push_back(2);
    moves.push_back(1);
    moves.push_back(4);

    cout << "=====   v e c t o r ==== " << endl;
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board.size(); j++){
            cout << board[i][j] << " " ;
        }
        cout << endl;
    }

    int a;
    a = solution(board, moves);
 
    cout << "답:: " << a << endl;

    return 0;
}