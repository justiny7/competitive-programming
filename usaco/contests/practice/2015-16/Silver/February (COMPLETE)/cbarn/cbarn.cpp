//USACO Silver February 2016 Problem 1
#include <bits/stdc++.h>
using namespace std;
//brute force every possible ending for cow N - yay worked first try
ifstream fin("cbarn.in");
ofstream fout("cbarn.out");

int n, pos[1001], cows[1001], ans=INT_MAX;

int getdist(int curcow, int intendedpos) {
    if (intendedpos>=curcow)
        return intendedpos-curcow;
    else
        return intendedpos+n-curcow;
}

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i)
        fin >> pos[i];
    for (int i=0, j=0; i<n;) {
        while (pos[i]) {
            pos[i]--;
            cows[j]=i;
            ++j;
        }
        while (!pos[i])
            ++i;
    }
    for (int i=0; i<n; ++i) {
        int cur=0;
        for (int j=0; j<n; ++j)
            cur+=getdist(cows[j], (n+i+j)%n)*getdist(cows[j], (n+i+j)%n);
        ans=min(cur, ans);
    }
    fout << ans << '\n';
}
