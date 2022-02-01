#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int> > board, vector<int> moves) {
    int answer = 0;
    int m_next = 0;
    int b_next = 0;
    int ele = 0;
    stack<int> basket;
    
    while(true){
        
        // 해당하는거 바구니에 넣기
        // 맨처음이 0일 수도 있어서 그걸 처리해줘야함 

       if (board[b_next][moves[m_next]-1] == 0 && b_next < board.size()){
           cout << "b_next:: " << b_next << endl;
           b_next++;
       }
       else{
           ele = board[b_next][moves[m_next]-1];
           cout << "ele:: " << ele << endl;

           if (!basket.empty() && basket.top() == ele){
                cout << "top:: " << basket.top() << endl;
                cout << "pop" << endl;
                basket.pop();
                cout << "pop후 top:: " << basket.top() << endl;
                answer += 2;
                cout << "answer:: " << answer << endl;
            }

           basket.push(ele); 
           board[b_next][moves[m_next]-1] = 0;
           b_next = 0; m_next ++;
           cout << "m_next:: " << m_next << endl;
       }
        
        if (m_next > moves.size()){
            return answer;
        }
    }
    
    
  
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