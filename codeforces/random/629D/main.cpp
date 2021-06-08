#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const double PI = acos(-1);

const int N = 1e5 + 69;
int n; ll bit[N], v[N], ans;
map<ll, int> mp;

void upd(int i, ll x) {
    for (++i; i < N; i += i & -i)
        bit[i] = max(bit[i], x);
}
ll query(int i) {
    ll ret = 0;
    for (++i; i; i -= i & -i)
        ret = max(ret, bit[i]);
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll r, h; cin >> r >> h;
        v[i] = r * r * h;
        mp[v[i]];
    }

    int c = 1;
    for (auto &[v, x] : mp)
        x = c++;

    for (int i = 0; i < n; ++i) {
        ll here = query(mp[v[i]] - 1) + v[i];
        ans = max(ans, here);
        upd(mp[v[i]], here);
    }

    cout << setprecision(12) << fixed << (double)ans * PI << '\n';
}
