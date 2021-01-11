#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e6+1;
const ll M=1e9+7;
ll q, dp[mxN][6];

/*
0: |_|_|
1: | |_|
2: |_| |
3: |   |
4: |___|
5: | | |
*/

int main() {
    dp[1][0]=dp[1][4]=1;
    for (int i=2; i<mxN; ++i) {
        dp[i][0]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3]+dp[i-1][4]+dp[i-1][5])%M;
        dp[i][1]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][5])%M;
        dp[i][2]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][5])%M;
        dp[i][3]=(dp[i-1][3]+dp[i-1][4])%M;
        dp[i][4]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3]+dp[i-1][4]+dp[i-1][5])%M;
        dp[i][5]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][5])%M;
    }
    cin.tie(0)->sync_with_stdio(0);
    cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << (dp[x][0]+dp[x][1]+dp[x][2]+dp[x][3]+dp[x][4]+dp[x][5])%M << '\n';
    }
}

