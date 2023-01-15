#include"bign.h"
#include<iostream>

using namespace std;
const int N = 1001;

bign::bign(){
    num = new int[N];
    int i=0;
    for(i=0; i<N; ++i) num[i] = 0;
}

bign::bign(char *c){
    num = new int[N];
    int i;
    for(i=0; i<N; ++i) num[i] = 0;
    for(i=0; c[i]!='\0'; ++i);
    for(; i>-1; --i){
        num[i] = c[i] - '0';
    }
}

bign::bign(string s){
    num = new int[N];
    int i, n = s.size();
    for(i=0; i<n; ++i);
    for(; i>-1; --i){
        num[i] = s[i] - '0';
    }
}

bign bign::operator+(const bign& a) const{
    bign ans;
    int i;
    for(i=0; i<N; ++i){
        if(a.num[i] + num[i] >= 10){
            ans.num[i] = (a.num[i] + num[i]) % 10;
            ans.num[i+1]++;
        }
        else    ans.num[i] = a.num[i] + num[i];
    }
    return ans;
}

bign bign::operator-(const bign &a) const{
    bign ans;

    return ans;
}

bign bign::operator*(const bign &a) const{
    bign ans;
    int i;
    for(i=0; i<N; ++i)  ans.num[i] = a.num[i] * num[i];
    for(i=0; i<N; ++i){
        if(ans.num[i] >= 10){
            ans.num[i+1] += ans.num/10;
            ans.num[i] %= 10;
        }
    }
    return ans;
}

bign bign::operator/(const bign &a) const{
    bign ans;
    
    return ans;
}

istream& operator>>(istream& is, bign &a){
    
}

ostream& operator<<(ostream& os, const bign &a){
    int i;
    for(i=N-1; a.num[i] != 0; --i);
    for(; i>-1; --i) os << a.num[i];
}