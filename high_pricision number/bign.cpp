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
    int i, n;
    for(i=0; i<N; ++i) num[i] = 0;
    n = i;
    for(i=0; c[i]!='\0'; ++i);
    for(; i>-1; --i){
        num[i] = c[n-i-1] - '0';
    }
}

bign::bign(string s){
    num = new int[N];
    int i, n = s.size();
    for(i=n-1; i>-1; --i){
        num[i] = s[n-i-1] - '0';
    }
}

bign::~bign(){
    delete []num;
}

int bign::cmp(const bign &a, const bign &b) const{
    for(int i=N-1; i>-1; --i){
        if(a.num[i] > b.num[i]) return 1;
        else if(a.num[i] < b.num[i]) return -1;
    }
    return 0;
}

bign bign::operator+(const bign& a) const{
    bign ans;
    int i;
    for(i=0; i<N; ++i){
        if(ans.num[i] + a.num[i] + num[i] >= 10){
            ans.num[i] = (ans.num[i] + a.num[i] + num[i]) % 10;
            ans.num[i+1]++;
        }
        else    ans.num[i] += (a.num[i] + num[i]);
    }
    return ans;
}

bign bign::operator-(const bign &a) const{
    bign ans;
    int i;
    if(cmp(*this, a) > 0){  //a > b
        for(i=N-1; i>-1; --i){
            if(num[i] < a.num[i]) {
                ans.num[i] = num[i] + 10 - a.num[i];
                ans.num[i+1]--;
            }
            else    ans.num[i] = num[i] - a.num[i];
        }
    }
    else if(cmp(*this, a) < 0){  //a < b
        for(i=N-1; i>-1; --i){
            if(a.num[i] < num[i]) {
                ans.num[i] = a.num[i] + 10 - num[i];
                ans.num[i+1]--;
            }
            else    ans.num[i] = a.num[i] - num[i];
        }
        for(i=N-1; ans.num[i]==0; --i);
        ans.num[i] *= -1;
    }

    return ans;
}

bign bign::operator*(const bign &a) const{
    bign ans;
    int i, j, n1, n2;
    for(i=N-1; num[i]==0; --i);
    for(j=N-1; a.num[j]==0; --j);
    n1 = i;
    n2 = j;
    for(i=0; i<=n1; ++i){
        for(j=0; j<=n2; ++j){
           ans.num[j+i] += (num[i] * a.num[j]);
        }
    }
    for(i=0; i<=n1+n2; ++i){
        if(ans.num[i] >= 10){
            ans.num[i+1] += (ans.num[i]/10);
            ans.num[i] %= 10;
        }
    }
    return ans;
}

bign bign::operator/(const bign &a) const{
    bign ans, t_this = *this;
    int i, j;
    if(cmp(*this, a) == 0) ans.num[0] = 1;
    else if(cmp(*this, a) > 0){  //a > b
        int t = 0, n1, n2, n;
        for(i=N-1; num[i]==0; --i);
        for(j=N-1; a.num[j]==0; --j);
        n1 = i;
        n2 = j;
        n = i - j;
        //for(i=n; i>-1; --i) t_this.num[i] = this->num[i];   //copy origin number to temporary variable's array
        for(i=n; i>-1; --i){
            bign t;
            for(j = n2; j>-1; --j) {t.num[j+i] = a.num[j];}
            while(true){
                if(cmp(t_this, t) >= 0){
                    ans.num[i] ++;
                    t_this = t_this - t;
                }
                else break;
            }
        }
    }
    return ans;
}

istream& operator>>(istream& is, bign &a){
    string s;
    is >> s;
    a = bign(s);
    return is;
}

ostream& operator<<(ostream& os, const bign &a){
    int i;
    for(i=N-1; a.num[i] == 0; --i);
    for(; i>-1; --i) os << a.num[i];
    return os;
}