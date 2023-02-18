#include <bits/stdc++.h>
using namespace std;

int get(int x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

void solve() {
    int n, q;
    cin >> n >> q;

    set<int> have;
    for (int i = 0; i < n; ++i)
        have.insert(i);

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int l, r;
            cin >> l >> r, --l, --r;

            vector<int> rem;
            auto it = have.lower_bound(l);
            while (it != have.end() && *it <= r) {
                // cout << "> " << *it << " " << a[*it] << '\n';
                a[*it] = get(a[*it]);
                if (get(a[*it]) == a[*it])
                    rem.push_back(*it);
                ++it;
            }

            for (int i : rem)
                have.erase(i);
        } else {
            int x;
            cin >> x, --x;
            cout << a[x] << '\n';
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

