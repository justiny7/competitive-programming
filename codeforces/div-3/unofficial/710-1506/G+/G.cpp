#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.size();
    map<char, int> cnt;
    for (char c : s)
        ++cnt[c];
    string ans;
    set<char> have;
    for (int i = 0; i < n; ++i) {
        --cnt[s[i]];
        if (have.count(s[i]))
            continue;
        while (ans.size() && cnt[ans.back()] && ans.back() < s[i]) {
            have.erase(ans.back());
            ans.pop_back();
        }
        have.insert(s[i]);
        ans += s[i];
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
