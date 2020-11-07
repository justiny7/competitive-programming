//Had to peek at solution for hint T-T
#include <bits/stdc++.h>
using namespace std;

ifstream fin("248.in");
ofstream fout("248.out");

const int mxN=248;
int n, a[mxN], dp[mxN][mxN], ans;

int main() {
    fin >> n;
    for (int i=0; i<n; ++i)
        fin >> a[i];
    for (int i=1; i<=n; ++i)
        for (int b=0; b<=n-i; ++b) {
            int e=b+i-1;
            if (i==1)
                dp[b][e]=a[b];
            for (int k=b; k<e; ++k)
                if (dp[b][k] && dp[b][k]==dp[k+1][e])
                    dp[b][e]=max(dp[b][e], dp[b][k]+1);
            ans=max(ans, dp[b][e]);
        }
    fout << ans << '\n';
}
