#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class t> using oset = tree<t, null_type, less<t>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 5e5 + 69;
int n, m, q, cnt[N], ans[N];
ll t, lst;
array<ll, 2> a[N], qu[N];
oset<int> cur;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ++cnt[x];
    }

    for (int i = 1; i <= m; ++i)
        a[i] = {cnt[i], i};
    sort(a + 1, a + m + 1);

    for (int i = 0; i < q; ++i) {
        cin >> qu[i][0];
        qu[i][0] -= n + 1, qu[i][1] = i;
    }
    sort(qu, qu + q);

    for (int i = 1, p = 0; i <= m || p < q; ++i) {
        while (p < q && qu[p][0] < t) {
            ll pos = (qu[p][0] - lst) % cur.size();
            ans[qu[p][1]] = *cur.find_by_order(pos);
            ++p;
        }

        if (p >= q)
            break;

        int j = i;
        while (j <= m && a[i][0] == a[j][0]) {
            cur.insert(a[j][1]);
            ++j;
        }

        lst = t;
        if (j < m + 1)
            t += (j - 1) * (a[j][0] - a[i][0]);
        else
            t = LLONG_MAX;
        i = j - 1;
    }

    for (int i = 0; i < q; ++i)
        cout << ans[i] << '\n';
}
