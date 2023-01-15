#pragma once
#include<string>
#include<iostream>
using namespace std;

class bign{
private:
    string data;
    int *num;

public:
    bign();
    bign(char *c);
    bign(string s);
    ~bign();
    int cmp(const bign&a, const bign &b) const;
    bign operator+(const bign& a) const;
    bign operator-(const bign& a) const;
    bign operator*(const bign& a) const;
    bign operator/(const bign& a) const;
    friend istream& operator>>(istream& is, bign &a);
    friend ostream& operator<<(ostream& os, const bign &a);
};