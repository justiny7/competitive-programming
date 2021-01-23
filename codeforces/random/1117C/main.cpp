#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+1;
int n;
ll sx, sy, ex, ey, dx[mxN], dy[mxN];
map<char, ll> mpx, mpy;
string s;

bool ok(ll x) {
    ll rep=x/n, ovr=x%n,
       cx=sx+dx[n]*rep+dx[ovr], cy=sy+dy[n]*rep+dy[ovr];
    return (abs(cx-ex)+abs(cy-ey)<=x);
}

int main() {
    mpx['U']=mpx['D']=0;
    mpx['L']=-1, mpx['R']=1;
    mpy['L']=mpy['R']=0;
    mpy['D']=-1, mpy['U']=1;
    cin.tie(0)->sync_with_stdio(0);
    cin >> sx >> sy >> ex >> ey >> n >> s;
    for (int i=0; i<n; ++i) {
        dx[i+1]=dx[i]+mpx[s[i]];
        dy[i+1]=dy[i]+mpy[s[i]];
    }
    ll lo=0, hi=1e18, best=-1;
    while (lo<=hi) {
        ll m=lo+hi>>1;
        if (ok(m)) {
            best=m;
            hi=m-1;
        }
        else
            lo=m+1;
    }
    cout << best << '\n';
}

