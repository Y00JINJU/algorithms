#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string new_id) {
    string answer = "";
    cout << endl;
    cout << endl;
    
    for (int i = 0; i < new_id.size(); i++){   
        new_id[i] = tolower(new_id[i]);
    }

    for (int i = 0; i < new_id.size(); i++){
          if (!isdigit(new_id[i]) && !isalpha(new_id[i]) && new_id[i] != '_' && new_id[i] != '.' && new_id[i] != '-'){
            new_id.erase(i, 1); i--;
        }
    }
    
    for (int i = 0; i < new_id.size(); i++){
    
        cout <<"i :: " << i << "          " << new_id[i] << endl;
        if (new_id[i] == '.' && new_id[i+1] == '.'){
            if (new_id[i+2] == '.'){
                new_id.erase(i, 1);
            }
            else{
                new_id.erase(i, 1);
            }

            cout << new_id << endl;
        }
        
        if (new_id[0] == '.'){
            new_id.erase(0, 1);
            cout << new_id << endl;
        }

        cout << new_id[new_id.size()-1] << endl;
        if (new_id[new_id.size()-1] == '.'){
            new_id.erase(new_id.size()-1 , 1);
        }
        
        if (new_id.empty()){
            new_id.append(1, 'a');
            cout << "aapend:: " << new_id << endl;
        }
        
        if (new_id.size() >= 16){
            new_id.erase(new_id.size()-1);
        }
        
        if (new_id[new_id.size()-1] == '.'){
            new_id.erase(new_id.size()-1, 1);
            cout << new_id << endl;
        }
    }

    if (new_id.size() < 3) {
        while(new_id.size() <3){
            new_id.append(1, new_id[new_id.size()-1]);
        }
    }
    
    return new_id;
}

int main(void){
    string s = "a.................";
    string b = ".a";
    string c = "a.";
    cout << "answer::   "  << endl;
    cout << solution(s) << endl;
}

// if (new_id[i] == '~' || new_id[i] == '~!' || new_id[i] == '@' || new_id[i] == '#' ||
// new_id[i] == '$' || new_id[i] == '%' || new_id[i] == '^' || new_id[i] == '&' || 
// new_id[i] == '(' || new_id[i] == ')' ||new_id[i] == '=' ||new_id[i] == '+' ||
// new_id[i] == '[' || new_id[i] == '{'  ||new_id[i] == '}' || new_id[i] == ']' 
// || new_id[i] == ':' || new_id[i] == '?' || new_id[i] == ',' || new_id[i] == '< '||
// new_id[i] == '>')