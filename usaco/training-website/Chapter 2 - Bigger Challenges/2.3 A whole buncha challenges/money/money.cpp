/*
ID: justiny7
LANG: C++
TASK: money
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll v, n, c[26], dp[100001];

int main(void) {
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    cin >> v >> n;
    dp[0]=1;
    for (int i=0; i<v; ++i)
        cin >> c[i];
    for (int i=0; i<v; ++i)
        for (int j=1; j<=n; ++j)
            if (j-c[i]>=0)
                dp[j]+=dp[j-c[i]];
    cout << dp[n] << '\n';
} 
