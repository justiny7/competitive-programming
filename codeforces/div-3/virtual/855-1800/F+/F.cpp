#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<string> v(n);
    for (string &s : v)
        cin >> s;

    ll res = 0;
    for (char no = 'a'; no <= 'z'; ++no) {
        map<int, ll> mp;
        for (string s : v) {
            if (!count(s.begin(), s.end(), no)) {
                int cur = 0;
                for (char c : s)
                    cur ^= (1 << (c - 'a'));

                int need = 0;
                for (int i = 0; i < 26; ++i) {
                    if (i == (no - 'a'))
                        continue;

                    if (!(cur & (1 << i)))
                        need ^= (1 << i);
                }

                res += mp[need];
                ++mp[cur];
            }
        }
    }

    cout << res << '\n';
}

