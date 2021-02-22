#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=20, mxD=11;
int n;
string s;
ll dp[mxN][mxD][2][2];

ll go(int pos, int cur, bool mx, bool ok) {
    ll &ret=dp[pos][cur][mx][ok];
    if (pos==n)
        return ret=ok;
    if (~ret)
        return ret;
    ret=0;
    int here=(s[pos]-'0');
    for (int i=0; i<10; ++i) {
        if (mx && i>here)
            break;
        if (ok && i==cur)
            continue;
        bool nmx=(i<here?0:mx), nok=(ok || i);
        ret+=go(pos+1, i, nmx, nok);
    }
    return ret;
}

ll solve(ll x) {
    if (x<0)
        return 0;
    memset(dp, -1, sizeof(dp));
    s=to_string(x);
    n=s.size();
    return (go(0, 10, 1, 0)+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll l, r;
    cin >> l >> r;
    cout << solve(r)-solve(l-1) << '\n';
}

