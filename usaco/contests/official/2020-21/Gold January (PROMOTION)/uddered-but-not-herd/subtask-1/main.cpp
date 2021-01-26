#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pcc=pair<char, char>;

int n, ans=INT_MAX, cnt[26][26], fst[26];
string s, ord;
map<pcc, int> mp;
set<char> ss;

int main() {
    memset(fst, 0x3f, sizeof(fst));
    cin.tie(0)->sync_with_stdio(0);
    cin >> s, n=s.size();
    for (int i=0; i<n; ++i) {
        ss.insert(s[i]);
        if (i)
            ++mp[pcc(s[i-1], s[i])];
    }
    for (char c:ss)
        ord+=c;
    do {
        int cur=1;
        for (auto p:mp) {
            int m=0, f=0, f2=0;
            for (char c:ord) {
                if (c==p.fi.fi)
                    f=1;
                else if (c==p.fi.se) {
                    if (f)
                        f2=1;
                    else {
                        m=1;
                        break;
                    }
                }
            }
            if (!f2)
                m=1;
            cur+=p.se*m;
        }
        //cout << ord << " " << cur << '\n';
        ans=min(ans, cur);
    } while (next_permutation(ord.begin(), ord.end()));
    cout << ans << '\n';
}

