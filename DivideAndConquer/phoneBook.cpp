#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book){
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());
    string phone = phone_book[0];

    
    for (int i = 1; i < phone_book.size(); i++){

        for (int j = 0; j < phone_book[i].length(); j++){
            string prefix = phone_book[i].substr(0, phone.length());

            if (phone == prefix) return false;
        }
    }
    
    return answer;
}

int main(void){
    vector<string> phoneBook1 = {"119", "97674223", "1195524421"};
    vector<string> phoneBook2 = {"123", "456", "789"};
    vector<string> phoneBook3 = {"12","123","1235","567","88"};

    cout << solution(phoneBook1) << endl;
    cout << solution(phoneBook2) << endl;
    cout << solution(phoneBook3) << endl;
}