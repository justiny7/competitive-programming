//USACO Silver US Open 2015 Problem 2
#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) x.begin(), x.end()
using namespace std;
using pii=pair<int, int>;

ifstream fin("trapped.in");
ofstream fout("trapped.out");

int n, b, ans=INT_MAX;
vector<pii> bales;

int main(void) {
    fin >> n >> b;
    bales.resize(n);
    for (int i=0; i<n; ++i)
        fin >> bales[i].se >> bales[i].fi;
    sort(all(bales));
    int r=upper_bound(all(bales), pii(b, 0))-bales.begin(), l=r-1, d=bales[r].fi-bales[l].fi;
    if (d<=bales[l].se && d<=bales[r].se) {
        fout << "0\n";
        return 0;
    }
    int curr=r, curl=l;
    for (; r<n; ++r)
        while (l>=0) {
            d=bales[r].fi-bales[l].fi;
            if (d<=bales[r].se) {
                ans=min(ans, d-bales[l].se);
                --l;
            }
            else
                break;
        }
    r=curr, l=curl;
    for (; l>=0; --l)
        while (r<n) {
            d=bales[r].fi-bales[l].fi;
            if (d<=bales[l].se) {
                ans=min(ans, d-bales[r].se);
                ++r;
            }
            else
                break;
        }
    if (ans==INT_MAX) {
        fout << "-1\n";
        return 0;
    }
    fout << ans << '\n';
}
