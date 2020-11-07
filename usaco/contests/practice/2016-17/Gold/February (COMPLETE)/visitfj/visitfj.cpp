#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;
//After first attempt TLE'd, I peeked at sol to get hint on implementation
ifstream fin("visitfj.in");
ofstream fout("visitfj.out");

const int mxN=101,
    ky[]={0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 0, -1},
    kx[]={3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2, 1, 0, -1, 0};
ll n, t, a[mxN][mxN], cost[mxN][mxN], ans=LLONG_MAX;
priority_queue<pll, vector<pll>, greater<pll>> pq;

pll get(ll a) {
    return {a/n, a%n};
}

ll go(pll a) {
    return a.fi*n+a.se;
}

bool in(ll y, ll x) {
    return (y>=0 && x>=0 && y<n && x<n);
}

int main() {
    fin >> n >> t;
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            fin >> a[i][j];
    memset(cost, 0x3f, sizeof(cost));
    pq.push({0, 0});
    cost[0][0]=0;
    while (!pq.empty()) {
        ll d_v=pq.top().fi, v=pq.top().se;
        pq.pop();
        ll y=get(v).fi, x=get(v).se;
        if (cost[y][x]!=d_v)
            continue;
        ll d_goal=abs(n-1-y)+abs(n-1-x);
        if (d_goal<3)
            ans=min(ans, d_goal*t+cost[y][x]);
        for (int i=0; i<16; ++i) {
            ll ny=y+ky[i], nx=x+kx[i];
            if (!in(ny, nx))
                continue;
            if (cost[ny][nx]>cost[y][x]+t*3+a[ny][nx]) {
                cost[ny][nx]=cost[y][x]+t*3+a[ny][nx];
                pq.push({cost[ny][nx], go({ny, nx})});
            }
        }
    }
    fout << ans << '\n';
}
