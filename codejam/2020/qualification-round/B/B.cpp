#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, ans; cin >> s;
    int n=s.size(), dep=0;
    for (int i=0; i<n; ++i) {
        while (dep<(s[i]-'0')) {
            ans+='(';
            ++dep;
        }
        while (dep>(s[i]-'0')) {
            ans+=')';
            --dep;
        }
        ans+=s[i];
    }
    while (dep>0)
        ans+=')', --dep;
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int tc=1; tc<=t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

