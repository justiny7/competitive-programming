//USACO Silver January 2017 Problem 3
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//kinda tricky but I got it
ifstream fin("cowcode.in");
ofstream fout("cowcode.out");

ll n, x;
string s;

char find(ll cur) {
    //cout << cur << '\n';
    if (cur<s.length())
        return s[cur];
    x=s.length();
    while (x*2<=cur)
        x*=2;
    if (x==cur) //it's at the end of a flipped substr 
        return find(x-1);
    return find(cur-x-1); //otherwise, find one index lower
} 

int main(void) {
    fin >> s >> n, n--;
    if (n<s.length()) {
        fout << s[n];
        return 0;
    }
    fout << find(n) << '\n';
}
