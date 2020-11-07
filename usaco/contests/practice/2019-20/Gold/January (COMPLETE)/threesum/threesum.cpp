//Looked at solution
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=5e3+1, mxV=1e6;
ll n, q, a[mxN], dp[mxN][mxN];
int cnt[mxV*2+1];

int main() {
    ifstream cin("threesum.in");
    ofstream cout("threesum.out");
    cin >> n >> q;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    for (int i=n-1; ~i; --i) {
        for (int j=i+1; j<n; ++j) {
            int k=mxV-a[i]-a[j];
            if (k>=0 && k<=2*mxV)
                dp[i][j]=cnt[k];
            ++cnt[mxV+a[j]];
        }
        for (int j=i+1; j<n; ++j)
            --cnt[mxV+a[j]];
    }
    for (int i=n-1; ~i; --i)
        for (int j=i+1; j<n; ++j)
            dp[i][j]+=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << dp[l-1][r-1] << '\n';
    }
}

