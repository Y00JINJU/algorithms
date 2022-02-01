#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int m1 = min(x, y);
    int m2 = min(w-x, h-y);
    cout << min(m1, m2) << endl;
}