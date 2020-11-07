#include <bits/stdc++.h>
using namespace std;
using ll=long long;
//Why do I suck at dp T-T - had to look at solution for this one
ifstream fin("cowrun.in");
ofstream fout("cowrun.out");

template<class T> bool ckmin(T& a, const T& b) {
    return (a>b)?a=b, 1:0;
}

const int mxN=1010;
int n, dp[mxN][mxN][2], cows[mxN];

int main(void) {
    memset(dp, 0x3f, sizeof(dp));
    fin >> n;
    for (int i=1; i<=n; ++i)
        fin >> cows[i];
    cows[++n]=0;
    sort(cows+1, cows+n+1);
    int a=lower_bound(cows+1, cows+n+1, 0)-cows;
    dp[a][1][0]=0;
    for (int l=1; l<n; ++l) {
        int cnt=n-l;
        for (int i=1; i+l<=n+1; ++i) {
            ckmin(dp[i-1][l+1][0], dp[i][l][0]+cnt*(cows[i]-cows[i-1])); //decrease left bound on left side
            ckmin(dp[i-1][l+1][0], dp[i][l][1]+cnt*(cows[i+l-1]-cows[i-1])); //increase right bound on left side
            ckmin(dp[i][l+1][1], dp[i][l][0]+cnt*(cows[i+l]-cows[i])); //decrease left bound on right side
            ckmin(dp[i][l+1][1], dp[i][l][1]+cnt*(cows[i+l]-cows[i+l-1])); //increase right bound on right side
        }
    }
    fout << min(dp[1][n][0], dp[1][n][1]) << '\n';
}
