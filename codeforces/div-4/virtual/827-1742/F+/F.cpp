#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;

    map<char, long long> mp[2];
    mp[0]['a'] = mp[1]['a'] = 1;

    while (q--) {
        int t, x;
        string s;
        cin >> t >> x >> s, --t;

        for (char c : s)
            mp[t][c] += x;

        char fst = mp[0].begin()->first,
             lst = prev(mp[1].end())->first;

        if (fst < lst)
            cout << "yes\n";
        else {
            assert(mp[1].size() == 1);

            if (mp[0]['a'] < mp[1]['a'] && mp[0].size() == 1)
                cout << "yes\n";
            else
                cout << "no\n";
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

