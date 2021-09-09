#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class t> using oset = tree<t, null_type, less<t>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n * 2);
    set<int> have;
    for (int &i : p) {
        cin >> i;
        have.insert(i);
    }

    int cur = n * 2, lst = n * 2;
    vector<int> lens;
    for (int i = n * 2 - 1; ~i; --i) {
        have.erase(p[i]);
        if (p[i] == cur) {
            lens.push_back(lst - i);
            lst = i;
            
            if (have.size())
                cur = *have.rbegin();
            else
                break;
        }
    }

    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int l : lens)
        for (int i = n; ~i; --i)
            if (i - l >= 0)
                dp[i] |= dp[i - l];

    cout << (dp[n] ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

