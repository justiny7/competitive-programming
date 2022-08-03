#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, d12, d23, d31;
    cin >> n >> d12 >> d23 >> d31;

    int v = 5;
    vector<array<int, 2>> res;
    
    auto gen_path = [&](int st, int en, int len) {
        // cout << "path from " << st << " to " << en << " of length " << len << '\n';
        if (len <= 0)
            return;
        if (len == 1)
            res.push_back({st, en});
        else {
            res.push_back({st, v});
            while (--len > 1)
                res.push_back({v++, v});
            res.push_back({v++, en});
        }
        // cout << "now res size is " << res.size() << '\n';
    };
    auto test = [&](int a, int b, int c, int ab, int bc, int ca) -> bool {
        // try placing c between a and b
        // cout << "trying to place " << c << " between " << a << " and " << b << '\n';
        int need = ca + bc - ab;
        if (need < 0 || need & 1)
            return 0;

        need /= 2;
        // cout << "need: " << need << '\n';

        if (need >= ca || need >= bc)
            return 0;

        int av = ca - need, bv = bc - need, cv = need;
        if (av + bv + cv > n - 1)
            return 0;

        if (need == 0) {
            v = 4;
            gen_path(c, a, ca);
            gen_path(c, b, bc);
        } else {
            gen_path(4, a, av);
            gen_path(4, b, bv);
            gen_path(4, c, cv);
        }

        gen_path(v - 1, n, n - v + 1);

        // cout << res.size() << '\n';
        assert(res.size() == n - 1);

        cout << "YES\n";
        for (auto [u, v] : res)
            cout << u << " " << v << '\n';

        return 1;
    };

    if (!test(1, 2, 3, d12, d23, d31) && !test(1, 3, 2, d31, d23, d12) && !test(2, 3, 1, d23, d31, d12))
        cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

