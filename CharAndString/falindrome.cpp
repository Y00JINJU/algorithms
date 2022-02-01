#include <iostream>
#include <string>

bool isOdd(int num){
    if(num % 2 == 0)
        return 0;
    return 1;
}

bool solution(std::string input){
    int inputSize = input.length();
    int half = inputSize/2;
    int end = inputSize-1;
    if (!isOdd(inputSize)){
        for (int start = 0; start <= half; ++start){
            if (input[start] == input[end]){
                end--;
                continue;
            } 
            else return 0;
        }
    }
    else{
        for (int start = 0; start < half; ++start){
            if (input[start] == input[end]){
                end--;
                continue;
            }
            else return 0;
        }
    }
    return 1;
}

int main(void){
    std::string str;
    std::cin >> str;
    std::cout << solution(str) << std::endl;
    return 0;
}