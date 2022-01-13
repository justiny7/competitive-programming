#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    map<char, int> mp;
    for (char c : s)
        ++mp[c];

    int odds = 0, evens = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (mp.count(c)) {
            evens += mp[c] / 2;
            if (mp[c] & 1)
                ++odds;
        }
    }

    int cur = (evens / k) * 2;
    int leftover = evens % k;

    odds += leftover * 2;
    if (odds >= k)
        ++cur;

    cout << cur << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

