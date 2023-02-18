#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, c;
    cin >> n >> c;

    vector<int> v(n);
    for(int &i : v)
        cin >> i;

    vector<array<int, 2>> cost(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cost[i] = {v[i] + min(i + 1, n - i), i};
    }

    sort(all(cost));

    for (auto [l, r] : cost)
        cout << l << " " << r << '\n';

    vector<ll> pref(n + 1);
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + cost[i - 1][0];
        a[cost[i - 1][1]] = i;
    }

    auto bin = [&](int x, int l, int r) {
        int lo = l, hi = r, bst = -1;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;

            if(pref[mid] <= x)
                bst = mid, lo = mid + 1;
            else
                hi = mid - 1;
        }

        return bst;
    };

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int cur = bin(c - (v[i] + i + 1), 0, a[i] - 1) + 1;
        cur = max(cur, bin(c + cost[a[i] - 1][0] - (v[i] + i + 1), a[i], n));

        ans = max(ans, cur);
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}



