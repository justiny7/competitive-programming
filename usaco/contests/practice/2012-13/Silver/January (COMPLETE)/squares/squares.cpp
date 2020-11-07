//This took wayyyy too long to debug (and I because of that I peeked at sol :c)
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

ifstream fin("squares.in");
ofstream fout("squares.out");

const int mxN=5e4+1;
ll n, k;
set<pll> cur;
vector<pll> x;
pll ans;

int main() {
    fin >> n >> k;
    for (int i=0; i<n; ++i) {
        int a, b;
        fin >> a >> b;
        x.pb(mp(a, b));
    }
    sort(x.begin(), x.end());
    bool f=0;
    int i=0, j=0;
    for (; i<x.size(); ++i) {
        while (x[j].fi<=x[i].fi-k)
            cur.erase(mp(x[j].se, j)), ++j;
        auto itr=cur.insert(mp(x[i].se, i)).fi;
        auto itr2=itr;
        if (++itr!=cur.end() && (itr->fi-x[i].se)<k) {
            if (f) {
                fout << "-1\n";
                return 0;
            }
            ans=mp(i, itr->se), f=1;
        }
        if (itr2--!=cur.begin() && (x[i].se-itr2->fi)<k) {
            if (f) {
                fout << "-1\n";
                return 0;
            }
            ans=mp(i, itr2->se), f=1;
        }
    }
    if (!f)
        fout << "0\n";
    else {
        pll a=x[ans.fi], b=x[ans.se];
        fout << (k-abs(a.fi-b.fi))*(k-abs(a.se-b.se)) << '\n';
    }
}

