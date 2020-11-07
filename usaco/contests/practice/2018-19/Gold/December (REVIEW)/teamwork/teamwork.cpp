#include <bits/stdc++.h>
using namespace std;

ifstream fin("teamwork.in");
ofstream fout("teamwork.out");

const int mxN=1e4+1;
int n, k, a[mxN], dp[mxN];

int main() {
    fin >> n >> k;
    for (int i=1; i<=n; ++i)
        fin >> a[i];
    dp[1]=a[1];
    for (int i=2; i<=n; ++i) {
        int cur=a[i];
        for (int j=i; j && i-j+1<=k; --j)
            cur=max(cur, a[j]), dp[i]=max(dp[i], dp[j-1]+cur*(i-j+1));
    }
    fout << dp[n] << '\n';
}
