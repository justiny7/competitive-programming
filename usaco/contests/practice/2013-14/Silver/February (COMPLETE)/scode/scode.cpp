#include <bits/stdc++.h>
using namespace std;
//Rip took like 4 submissions cuz typos :c
ifstream fin("scode.in");
ofstream fout("scode.out");

const int MOD=2014;
string s;
map<string, int> dp; //to memoize answers

int construct(string x) {
    if (dp.count(x))
        return dp[x];
    int ans=1, n=x.size();
    for (int i=1; 2*i<n; ++i) {
        string beg=x.substr(0, i), rest1=x.substr(i);
        string en=x.substr(n-i), rest2=x.substr(0, n-i);
        string mid1=x.substr(i, i), mid2=x.substr(n-2*i, i);
        if (beg==en) //reproduce from outside ends
            ans=(ans+construct(rest1)+construct(rest2))%MOD;
        if (beg==mid1) //reproduce from inside ends
            ans=(ans+construct(rest1))%MOD;
        if (en==mid2)
            ans=(ans+construct(rest2))%MOD;
    }
    return dp[x]=ans%MOD;
}

int main(void) {
    fin >> s;
    fout << construct(s)-1 << '\n';
}
