#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;

int n, k;
map<int, int> mp;
map<int, multiset<int, greater<int>>> segs;
map<int, pii> segid;
vector<int> ans;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n; ++i) {
        int a, b;
        cin >> a >> b, b++;
        segid[i]={a, b};
        segs[a].insert(b);
        mp[a]++;
        mp[b]--;
    }
    int c=0;
    for (auto& p : mp) {
        if (c+p.se>k) {
            int d=c+p.se-k;
            c=k;
            while (d--) {
                int cmax=-1, cbeg;
                for (auto& p2 : mp)
                    if (*segs[p2.fi].begin()>max(p.fi, cmax) && p2.fi<=p.fi) {
                        cmax=*segs[p2.fi].begin();
                        cbeg=p2.fi;
                    }
                segs[cbeg].erase(segs[cbeg].begin());
                for (auto it=segid.begin(); it!=segid.end(); ++it)
                    if (it->se==make_pair(cbeg, cmax)) {
                        ans.push_back(it->fi);
                        segid.erase(it);
                        break;
                    }
                mp[cmax]++;
            }
        }
        else
            c+=p.se;
    }
    cout << ans.size() << '\n';
    for (int i=0; i<ans.size(); ++i) {
        if (i>0)
            cout << " ";
        cout << ans[i];
    }
    cout << '\n';
}
