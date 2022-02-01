#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){
    vector<int> prog;
    vector<int> speeds;
    vector<int> days;
    int remain, speed;

    prog.push_back(95);
    prog.push_back(90);
    prog.push_back(99);
    prog.push_back(99);
    prog.push_back(80);
    prog.push_back(99);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    
    for (int i = 0; i < prog.size(); i++){
        remain = 100 - prog[i];
        speed = speeds[i];

        if ((remain % speed) == 0){
            days.push_back(remain/speed);
        }    
        else{
             days.push_back((remain/speed)+1);
        }
    }

    for (int i = 0 ; i < days.size(); i++){
        cout << "days:: " << days[i] << " " << endl;
    }

    
}