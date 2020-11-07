//USACO Silver January 2017 Problem 2
#include <bits/stdc++.h>
using namespace std;
//nice worked first try as well
ifstream fin("hps.in");
ofstream fout("hps.out");

int n, h[100001], p[100001], s[100001];

int main(void) {
    fin >> n;
    for (int i=1; i<=n; ++i) {
        char c;
        fin >> c;
        h[i]+=h[i-1];
        p[i]+=p[i-1];
        s[i]+=s[i-1];
        if (c=='P')
            p[i]++;
        if (c=='S')
            s[i]++;
        if (c=='H')
            h[i]++;
    }
    int ans=-1;
    for (int i=1; i<=n; ++i) {
        ans=max(h[i]+s[n]-s[i], ans);
        ans=max(h[i]+p[n]-p[i], ans);
        ans=max(s[i]+h[n]-h[i], ans);
        ans=max(s[i]+p[n]-p[i], ans);
        ans=max(p[i]+s[n]-s[i], ans);
        ans=max(p[i]+h[n]-h[i], ans);
    }
    fout << ans << '\n';
}
