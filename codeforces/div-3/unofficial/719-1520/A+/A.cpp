#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; string s, ret;
        cin >> n >> s;
        ret += s[0];
        for (int i = 1; i < n; ++i)
            if (s[i] != s[i - 1])
                ret += s[i];
        set<char> ss;
        bool f = 0;
        for (char c : ret) {
            if (ss.count(c))
                f = 1;
            else
                ss.insert(c);
        }
        cout << (f ? "NO" : "YES") << '\n';
    }
}
