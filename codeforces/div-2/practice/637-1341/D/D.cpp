#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int n, k, times[2001][10], dp[2001][2001];
string ans, s[2001], digs[]={"1110111", "0010010", "1011101", "1011011",
    "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int works(int cur, int dig) {
    int cnt=0;
    for (int i=0; i<7; ++i) {
        if (digs[dig][i]=='0' && s[cur][i]=='1')
            return -1;
        else if (digs[dig][i]=='1' && s[cur][i]=='0')
            cnt++;
    }
    return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i=0; i<n; ++i) {
        cin >> s[i];
        for (int j=0; j<10; ++j)
            times[i][j]=works(i, j);
    }
    dp[n][0]=1;
    for (int i=n; i>0; --i)
        for (int j=0; j<=k; ++j)
            if (dp[i][j])
                for (int l=0; l<10; ++l)
                    if (times[i-1][l]>=0 && j+times[i-1][l]<=k)
                        dp[i-1][j+times[i-1][l]]=1;
    if (dp[0][k]==0) {
        cout << "-1\n";
        return 0;
    }
    for (int i=0; i<n; ++i) {
        for (int j=9; j>=0; --j)
            if (times[i][j]>=0 && times[i][j]<=k && dp[i+1][k-times[i][j]]) {
                k-=times[i][j];
                cout << j;
                break;
            }
    }
    cout << '\n';
}
