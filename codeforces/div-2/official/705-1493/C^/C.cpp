#include <bits/stdc++.h>
using namespace std;

const int mxC=26;
int n, k, cnt[mxC];
string s;

int contrib(int x) {
    return (k-x%k)%k;
}

void solve() {
    memset(cnt, 0, sizeof(cnt));
    cin >> n >> k >> s;
    if (n%k) {
        cout << "-1\n";
        return;
    }
    for (char c:s)
        ++cnt[c-'a'];
    int need=0;
    for (int i=0; i<mxC; ++i)
        need+=contrib(cnt[i]);
    if (!need) {
        cout << s << '\n';
        return;
    }
    for (int i=n-1; ~i; --i) {
        need-=contrib(cnt[s[i]-'a']--);
        need+=contrib(cnt[s[i]-'a']);
        for (int nxt=(s[i]-'a')+1; nxt<mxC; ++nxt) {
            need-=contrib(cnt[nxt]++);
            need+=contrib(cnt[nxt]);
            if (need<=n-1-i) {
                string add;
                for (char j='a'; j<='z'; ++j) {
                    int t=contrib(cnt[j-'a']);
                    add+=string(t, j);
                }
                while (add.size()<n-1-i)
                    add+='a';
                sort(add.begin(), add.end());
                cout << s.substr(0, i) << char('a'+nxt) << add << '\n';
                return;
            }
            need-=contrib(cnt[nxt]--);
            need+=contrib(cnt[nxt]);
        }
    }
    assert(false);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}

