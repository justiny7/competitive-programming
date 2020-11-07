//USACO Silver February 2017 Problem 3
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;
//Nice, worked second try b/c forgot to -1 from cow positions xd
ifstream fin("countcross.in");
ofstream fout("countcross.out");

int n, k, r, grp[101][101], kx[]={0, 1, 0, -1}, ky[]={1, 0, -1, 0}, cnt, ans;
map<pair<pii, pii>, bool> road;
pii cows[100001];

bool in(int x, int y) {
    return (x>=0 && y>=0 && x<n && y<n);
}

void dfs(pii p) {
    grp[p.fi][p.se]=cnt;
    for (int i=0; i<4; ++i) {
        int x=p.fi+kx[i], y=p.se+ky[i];
        if (in(x, y) && !grp[x][y] && !road[{p, {x, y}}])
            dfs({x, y});
    }
}

int main(void) {
    fin >> n >> k >> r;
    for (int i=0; i<r; ++i) {
        int a, b, c, d;
        fin >> a >> b >> c >> d;
        --a, --b, --c, --d;
        road[{{a, b}, {c, d}}]=1;
        road[{{c, d}, {a, b}}]=1;
    }
    for (int i=0; i<k; ++i) {
        fin >> cows[i].fi >> cows[i].se;
        --cows[i].fi, --cows[i].se;
    }
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if (!grp[i][j]) {
                ++cnt;
                dfs({i, j});
            }
    for (int i=0; i<k; ++i)
        for (int j=i+1; j<k; ++j)
            if (grp[cows[i].fi][cows[i].se]!=grp[cows[j].fi][cows[j].se])
                ans++;
    fout << ans << '\n';
}
