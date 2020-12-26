//Yay worked first try
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e4+1, mxK=1e3+1;
int n, k, a[mxN], dp[mxN][mxK], dpmax[mxN];

int main() {
    ifstream cin("teamwork.in");
    ofstream cout("teamwork.out");
    cin >> n >> k;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    for (int i=1; i<=n; ++i) {
        int mx=0;
        for (int j=1; j<=k; ++j) {
            if (i-j<0)
                break;
            mx=max(mx, a[i-j+1]);
            dp[i][j]=max(dp[i][j], dpmax[i-j]+mx*j);
        }
        for (int j=1; j<=k; ++j)
            dpmax[i]=max(dpmax[i], dp[i][j]);
    }
    cout << dpmax[n] << '\n';
}

