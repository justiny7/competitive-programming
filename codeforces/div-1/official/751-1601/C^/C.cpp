#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e6 + 69;
int n, m, a[N], b[N];
vector<int> add[N];
long long ans;

void dnc(int nl = 1, int nr = n + 1, int ml = 1, int mr = m) {
    if (ml > mr)
        return;

    int targ = ml + mr >> 1;
    
    int inv = 0;
    for (int i = nl; i < nr; ++i)
        if (a[i] < b[targ])
            ++inv;

    int mn = inv, ind = nl;
    for (int i = nl; i < nr; ++i) {
        if (a[i] < b[targ])
            --inv;
        if (a[i] > b[targ])
            ++inv;

        if (mn > inv)
            mn = inv, ind = i + 1;
    }

    add[ind].push_back(b[targ]);
    dnc(nl, ind, ml, targ - 1);
    dnc(ind, nr, targ + 1, mr);
}

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i];

    for (int i = 1; i <= n + 1; ++i)
        add[i].clear();

    sort(b + 1, b + m + 1);

    ans = 0;
    dnc();

    int q = n + 1;
    oset<array<int, 2>> o;
    for (int j : add[n + 1])
        o.insert({j, q++});

    for (int i = n; i; --i) {
        ans += o.order_of_key({a[i], -1});
        for (int j : add[i])
            ans += o.order_of_key({j, -1});

        o.insert({a[i], i});
        for (int j : add[i])
            o.insert({j, q++});
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

