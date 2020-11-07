#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, cnt[mxN], l[mxN];
set<int> s, vals;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int ans=0;
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        vals.insert(a);
        if (l[cnt[a]])
            --l[cnt[a]];
        if (cnt[a] && !l[cnt[a]])
            s.erase(cnt[a]);
        ++l[++cnt[a]];
        if (l[cnt[a]]==1)
            s.insert(cnt[a]);
        int x=*s.begin(), y;
        if (s.size()>1)
            y=*s.rbegin();
        if ((s.size()==2 && ((y==x+1 && l[y]==1) || (x==1 && l[x]==1))) ||
            (s.size()==1 && x==1) ||
            vals.size()==1)
            ans=i;
    }
    cout << ans+1 << '\n';
}

