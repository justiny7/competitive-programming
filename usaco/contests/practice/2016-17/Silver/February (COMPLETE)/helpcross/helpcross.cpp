//USACO Silver February 2017 Problem 1
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

ifstream fin("helpcross.in");
ofstream fout("helpcross.out");

int n, c, ans;
pair<int, int> cows[20001];
multiset<int> chickens;

bool sortM(pair<int, int> a, pair<int, int> b) {
    if (a.se!=b.se)
        return a.se<b.se;
    return a.fi<b.fi;
}

int main(void) {
    fin >> c >> n;
    for (int i=0; i<c; ++i) {
        int a;
        fin >> a;
        chickens.insert(a);
    }
    for (int i=0; i<n; ++i)
        fin >> cows[i].fi >> cows[i].se;
    sort(cows, cows+n, sortM);
    for (int i=0; i<n; ++i) {
        auto u=chickens.lower_bound(cows[i].fi);
        if (u==chickens.end())
            continue;
        if (*u<=cows[i].se) {
            ans++;
            chickens.erase(u);
        }
    }
    fout << ans << '\n';
}
