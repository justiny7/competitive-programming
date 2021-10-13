#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class t> using oset = tree<t, null_type, less<t>, rb_tree_tag, tree_order_statistics_node_update>;

int n, k;
oset<int> o;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        o.insert(i);

    int cur = 0;
    for (int t = n; t--; ) {
        int nxt = (cur + k) % o.size();
        auto it = o.find_by_order(nxt);
        cout << *it + 1 << " \n"[t == 0];

        cur = nxt;
        o.erase(it);
    }
}

