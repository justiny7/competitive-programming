//USACO Silver US Open 2020 Problem 1

//Bruh it took me too long to implement the bin search smh
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ifstream fin("socdist.in");
ofstream fout("socdist.out");

int n, m;
pll grass[100001];

bool works(ll x) {
    int cursect = 0, curcow = 1;
    ll curpos = grass[0].fi;
    while (curcow < n && cursect < m) {
        if (curpos+x <= grass[cursect].se) {
            curcow++;
            curpos += x;
        }
        else {
            while (cursect < m && curpos+x > grass[cursect].se)
                cursect++;
            if (cursect == m)
                break;
            curcow++;
            if (curpos+x >= grass[cursect].fi)
                curpos += x;
            else
                curpos = grass[cursect].fi;
        }
    }
    return (curcow == n);
}

int main(void) {
    fin >> n >> m;
    for (int i = 0; i < m; i++)
        fin >> grass[i].fi >> grass[i].se;
    sort(grass, grass+m);
    ll lo = 1, hi = 1e18, best;
    while (lo <= hi) {
        ll mid = lo+(hi-lo+1)/2;
        //cout << mid << '\n';
        if (works(mid)) {
            best = mid;
            lo = mid+1;
        }
        else
            hi = mid-1;
    }
    fout << best << '\n';
    return 0;
}
