#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e5 + 1;
int n, h[N];
ll b[N], dp[N];

//Segtree {{{
ll t[N << 1];

void upd(int i, ll x) {
    for (t[i += n] = x; i > 1; i >>= 1)
        t[i >> 1] = max(t[i], t[i ^ 1]);
}
ll query(int l, int r) {
    ll ret = LLONG_MIN;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            ret = max(ret, t[l++]);
        if (r & 1)
            ret = max(ret, t[--r]);
    }
    return ret;
}
//}}}

int main() {
    memset(t, 0xc0, sizeof(t));
    memset(dp, 0xc0, sizeof(dp));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    upd(0, 0);
    stack<pair<int, int>> st;
    for (int i = 1; i <= n; ++i) {
        while (!st.empty() && h[i] < st.top().first)
            st.pop();
        int l = 0;
        if (st.size()) {
            l = st.top().second;
            dp[i] = dp[l];
        }
        dp[i] = max(dp[i], b[i] + query(l, i - 1));
        upd(i, dp[i]);
        st.emplace(h[i], i);
    }
    cout << dp[n] << '\n';
}
