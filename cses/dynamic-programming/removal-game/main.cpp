#include <bits/stdc++.h>
using namespace std;

long long n, board[5001], dp[5001][5001];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> dp[i][i];
        board[i]=board[i-1]+dp[i][i];
    }
    for (int i=1; i<=n; ++i)
        for (int j=1; j+i<=n; ++j)
            dp[i+j][j]=board[i+j]-board[j-1]-min(dp[j+i-1][j], dp[j+i][j+1]);
    cout << dp[n][1] << '\n';
}
