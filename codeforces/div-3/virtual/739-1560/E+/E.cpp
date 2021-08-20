#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    int n;
    cin >> s, n = s.size();

    set<char> seen;
    string ord;
    for (int i = n - 1; ~i; --i) {
        if (!seen.count(s[i])) {
            seen.insert(s[i]);
            ord += s[i];
        }
    }

    vector<int> cnt(26);
    for (char c : s)
        ++cnt[c - 'a'];

    int sz = ord.size(), cur_sz = 0;
    for (int i = 0; i < sz; ++i) {
        int c = ord[sz - 1 - i] - 'a';
        if (cnt[c] % (i + 1)) {
            cout << "-1\n";
            return;
        }
        
        cur_sz += cnt[c] / (i + 1);
    }

    // cout << ord << " " << cur_sz << '\n';

    string ret_s = s.substr(0, cur_sz), ret_ord = ord;
    reverse(ret_ord.begin(), ret_ord.end());

    int en = cur_sz + 1;
    vector<int> prv(en + 1), nxt(en + 1);
    for (int i = 1; i <= en; ++i) {
        prv[i] = i - 1;
        nxt[i - 1] = i;
    }

    int spos = 0;
    while (cur_sz > 0) {
        int pos = 0;
        while (pos != en) {
            // cout << "> " << pos << " " << spos << '\n';
            if (pos > 0 && s[spos] != s[pos - 1]) {
                assert(pos - 1 < s.size());
                cout << "-1\n";
                return;
            }

            if (pos != 0)
                ++spos;
            pos = nxt[pos];
        }

        pos = 0;
        assert(ord.size());
        char rem = ord.back();
        while (pos != en) {
            if (pos > 0 && s[pos - 1] == rem) {
                assert(pos - 1 < s.size());
                --cur_sz;
                nxt[prv[pos]] = nxt[pos];
                prv[nxt[pos]] = prv[pos];

                // cout << "linked " << prv[pos] << " " << nxt[pos] << '\n';
            }

            // cout << "at pos " << pos << '\n';

            pos = nxt[pos];
        }

        ord.pop_back();
        // cout << "! " << cur_sz << '\n';
    }

    cout << ret_s << " " << ret_ord << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

