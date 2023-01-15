#include"bign.h"
#include<iostream>

using namespace std;

int main(){
    bign a, b;
    cin >> a >> b;
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;

    bign t = a+b;
    cout << "a+b:" << t << endl;

    t = a-b;
    cout << "a-b:" << t << endl;

    t = a*b;
    cout << "a*b:" << t << endl;
    
    t = a/b;
    cout << "a/b:" << t << endl;
    return 0;
}