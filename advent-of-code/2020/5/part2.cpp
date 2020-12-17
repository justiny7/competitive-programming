#include <bits/stdc++.h>
using namespace std;

const int mxN=2<<10;
bool taken[mxN];

int main() {
    freopen("test.txt", "r", stdin);
    string s;
    int ans=0;
    while (1) {
        getline(cin, s);
        if (s.empty())
            break;
        int lo=0, hi=127, cur;
        for (int i=0; i<7; ++i) {
            int m=lo+hi>>1;
            if (s[i]=='B')
                lo=m+1;
            else
                hi=m;
        }
        cur=lo*8, lo=0, hi=7;
        for (int i=7; i<10; ++i) {
            int m=lo+hi>>1;
            if (s[i]=='R')
                lo=m+1;
            else
                hi=m;
        }
        cur+=lo;
        taken[cur]=1;
    }
    for (int i=1; i<mxN-1; ++i)
        if (taken[i-1] && !taken[i] && taken[i+1])
            return cout << i << '\n', 0;
}

