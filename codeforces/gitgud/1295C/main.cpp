#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;
        {
            set<char> st;
            for (char c:s)
                st.insert(c);
            bool f=1;
            for (char c:t)
                f&=bool(st.count(c));
            if (!f) {
                cout << "-1\n";
                continue;
            }
        }
        int ans=1;
        map<char, set<int>> mp;
        for (int i=0; i<s.size(); ++i)
            mp[s[i]].insert(i);
        for (int i=0, j=-1; i<t.size(); ++i) {
            char c=t[i];
            auto it=mp[c].upper_bound(j);
            if (it==mp[c].end())
                ++ans, j=*mp[c].begin();
            else
                j=*it;
        }
        cout << ans << '\n';
    }
}

