//Resorted to pbds in the end xd
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
using pii=pair<int, int>;

template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int mxN=2e5+1;
int n, q, a[mxN];
oset<pii> m;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=0; i<n; ++i)
        cin >> a[i], m.insert({a[i], i});
    while (q--) {
        char c; int x, y;
        cin >> c >> x >> y;
        if (c=='!') {
            m.erase(m.find({a[x-1], x-1}));
            m.insert({y, x-1});
            a[x-1]=y;
        }
        else
            cout << m.order_of_key({y+1, 0})-m.order_of_key({x, 0}) << '\n';
    }
}

