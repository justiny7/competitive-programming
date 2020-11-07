//USACO Silver February 2020 Problem 2
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;
//YESS finally why did it take so long...4 submissions cuz I messed up mod stuff
ifstream fin("triangles.in");
ofstream fout("triangles.out");

const int MOD=1e9+7;
int n, ans;
map<int, set<int, greater<int>>> x, y;
map<pii, int> xsum1, xsum2, xsum, ysum1, ysum2, ysum;
pii pts[100001];

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i) {
        fin >> pts[i].fi >> pts[i].se;
        x[pts[i].fi].insert(pts[i].se);
        y[pts[i].se].insert(pts[i].fi);
    }
    sort(pts, pts+n);
    for (auto& p : x) {
        int last, k=p.fi, tp, bot, f=1, m=1;
        for (auto it=p.se.begin(); it!=p.se.end(); ++it) {
            if (f) {
                last=tp=*it;
                xsum1[{k, *it}]=0;
                f=0;
                continue;
            }
            xsum1[{k, *it}]=(xsum1[{k, last}]+(last-*it)*m)%MOD;
            m++;
            last=*it;
        }
        f=1, m=1;
        for (auto it=p.se.rbegin(); it!=p.se.rend(); ++it) {
            if (f) {
                last=bot=*it;
                xsum2[{k, *it}]=0;
                f=0;
                continue;
            }
            xsum2[{k, *it}]=(xsum2[{k, last}]+(*it-last)*m)%MOD;
            m++;
            last=*it;
        }
        for (auto it=p.se.begin(); it!=p.se.end(); ++it)
            xsum[{k, *it}]=xsum1[{k, *it}]+xsum2[{k, *it}];
    }
    for (auto& p : y) {
        int last, k=p.fi, tp, bot, f=1, m=1;
        for (auto it=p.se.begin(); it!=p.se.end(); ++it) {
            if (f) {
                last=tp=*it;
                ysum1[{*it, k}]=0;
                f=0;
                continue;
            }
            ysum1[{*it, k}]=(ysum1[{last, k}]+(last-*it)*m)%MOD;
            m++;
            last=*it;
        }
        f=1, m=1;
        for (auto it=p.se.rbegin(); it!=p.se.rend(); ++it) {
            if (f) {
                last=bot=*it;
                ysum2[{*it, k}]=0;
                f=0;
                continue;
            }
            ysum2[{*it, k}]=(ysum2[{last, k}]+(*it-last)*m)%MOD;
            m++;
            last=*it;
        }
        for (auto it=p.se.begin(); it!=p.se.end(); ++it)
            ysum[{*it, k}]=(ysum1[{*it, k}]+ysum2[{*it, k}])%MOD;
    }
    for (int i=0; i<n; ++i)
        ans=(ans+((long long)xsum[pts[i]]*ysum[pts[i]])%MOD)%MOD;
    fout << ans << '\n';
}
