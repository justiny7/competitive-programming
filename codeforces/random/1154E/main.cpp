#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int mxN=2e5+1;
int n, k;
pair<int, int> a[mxN];
set<int> cur;
string ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    ans.resize(n, '%');
    for (int i=0; i<n; ++i) {
        cin >> a[i].fi, a[i].se=i;
        cur.insert(i);
    }
    sort(a, a+n, greater<pair<int, int>>());
    for (int i=0, f=1; i<n; ++i) {
        if (!cur.count(a[i].se))
            continue;
        int c=0;
        auto it=cur.find(a[i].se),
             it2=it;
        vector<int> rem{a[i].se};
        if (it2!=cur.begin())
            --it2;
        for (++it; c<k && it!=cur.end(); ++it, ++c)
            rem.push_back(*it);
        for (c=0; c<k && it2!=cur.begin(); --it2, ++c)
            rem.push_back(*it2);
        if (it2==cur.begin() && c^k)
            rem.push_back(*it2);
        for (int j:rem) {
            ans[j]=(f?'1':'2');
            cur.erase(j);
        }
        f^=1;
    }
    cout << ans << '\n';
}

