#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+5;
int n, ans, b[mxN], e[mxN], pref[mxN], suff[mxN];
bool taken[mxN];

int main() {
    ifstream cin("cardgame.in");
    ofstream cout("cardgame.out");
    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> e[i];
        taken[e[i]]=1;
    }
    for (int i=1, j=1; i<=n*2; ++i)
        if (!taken[i])
            b[j++]=i;
    { //pref
        set<int> s;
        for (int i=1; i<=n; ++i)
            s.insert(b[i]);
        for (int i=1; i<=n; ++i) {
            auto it=s.upper_bound(e[i]);
            if (it!=s.end()) {
                ++pref[i];
                s.erase(it);
            }
            pref[i]+=pref[i-1];
        }
    }
    { //suff
        set<int> s;
        for (int i=1; i<=n; ++i)
            s.insert(b[i]);
        for (int i=n; i; --i) {
            auto it=s.lower_bound(e[i]);
            if (it!=s.begin()) {
                --it;
                ++suff[i];
                s.erase(it);
            }
            suff[i]+=suff[i+1];
        }
    }
    for (int i=0; i<=n; ++i)
        ans=max(ans, pref[i]+suff[i+1]);
    cout << ans << '\n';
}

