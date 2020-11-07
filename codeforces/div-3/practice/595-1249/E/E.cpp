#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1;
int n, c, a[mxN], b[mxN], dp[mxN][2];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> c;
    for (int i=1; i<n; ++i)
        cin >> a[i];
    for (int i=1; i<n; ++i)
        cin >> b[i];
    cout << "0 ";
    dp[0][1]=c;
    for (int i=1; i<n; ++i) {
        dp[i][0]=min(dp[i-1][0]+a[i], dp[i-1][1]+b[i]);
        dp[i][1]=min(dp[i-1][1]+b[i], dp[i-1][0]+a[i]+c);
        cout << min(dp[i][0], dp[i][1]);
        if (i!=n-1)
            cout << " ";
    }
    cout << '\n';
}

