#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;
//Yay worked first try
ifstream fin("pogocow.in");
ofstream fout("pogocow.out");

const int mxN=1e3+1;
int n, ans, dp[mxN][mxN]; //dp[i][j]=max pts starting at target i going to target j
pii a[mxN];

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i)
        fin >> a[i].fi >> a[i].se;
    sort(a, a+n);
    for (int i=0; i<n; ++i) {
        int cur=0, cmax=0;
        for (int j=n-1; j>=i; --j) {
            while (cur<i && a[i].fi-a[cur].fi>=a[j].fi-a[i].fi)
                cmax=max(cmax, a[cur].se+dp[cur][i]), ++cur;
            dp[i][j]=cmax;
        }
        ans=max(ans, a[i].se+cmax);
    }
    for (int i=n-1; i>=0; --i) {
        int cur=n-1, cmax=0;
        for (int j=0; j<=i; ++j) {
            while (cur>i && a[cur].fi-a[i].fi>=a[i].fi-a[j].fi)
                cmax=max(cmax, a[cur].se+dp[cur][i]), --cur;
            dp[i][j]=cmax;
        }
        ans=max(ans, a[i].se+cmax);
    }
    fout << ans << '\n';
}
