#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using pii=pair<int, int>;

ifstream fin("fairphoto.in");
ofstream fout("fairphoto.out");

const int mxN=1e5+1;
int n, s, w, ans;
pii cows[mxN];
vector<pii> pref[2]; //for each parity

int main(void) {
    fin >> n;
    for (int i=1; i<=n; ++i) {
        char c;
        fin >> cows[i].fi >> c;
        cows[i].se=((c=='S')?1:-1);
        (c=='S')?++s:++w;
    }
    sort(cows+1, cows+1+n);
    if (!w) {
        fout << "0\n";
        return 0;
    }
    if (w>=s) {
        if (n&1)
            fout << max(cows[n-1].fi-cows[1].fi, cows[n].fi-cows[2].fi) << '\n';
        else
            fout << cows[n].fi-cows[1].fi << '\n';
        return 0;
    }
    int cur=0;
    for (int i=1; i<=n; ++i) {
        int c=cur&1;
        if (pref[c].empty() || pref[c].back().fi<cur)
            pref[c].pb({cur, cows[i].fi});
        cur+=cows[i].se, c=cur&1;
        if (!pref[c].empty() && cur<=pref[c].back().fi) {
            auto it=lower_bound(pref[c].begin(), pref[c].end(), make_pair(cur, -mxN*3));
            ans=max(ans, cows[i].fi-it->se);
        }
    }
    fout << ans << '\n';
}
