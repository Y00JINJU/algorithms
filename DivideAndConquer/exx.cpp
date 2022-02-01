#include <iostream>

using namespace std;

void double_by_ptr(int *p){
    *p = *p * *p;
}

void double_by_ref(int& r){
    r *= r;
}

int double_by_val(int v){
    return v * v;
}

int main(void){

    int x = 2, y =3 , z = 4;

    double_by_ptr(&x);
    cout << "X:: " << x << endl;

    double_by_ref(y);
    cout << "y:: " << y << endl;

    z = double_by_val(z);
    cout << "Z :: " << z << endl;
}
