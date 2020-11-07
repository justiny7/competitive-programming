#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;
//Yay worked first try except I spent like 20 minutes debugging before realizing
//that I used a variable name twice ._.
ifstream fin("ccski.in");
ofstream fout("ccski.out");

const int mxN=501, kx[]={0,1,0,-1}, ky[]={1,0,-1,0};
int n, m, a[mxN][mxN], wcnt;
pii ck;
bool waypoint[mxN][mxN];

bool in(int y, int x) {
    return (y>=0 && x>=0 && y<n && x<m);
}

bool works(int targ) {
    bool vis[mxN][mxN];
    memset(vis, 0, sizeof(vis));
    queue<pii> q;
    q.push(ck);
    vis[ck.fi][ck.se]=1;
    int cnt=0;
    while (!q.empty()) {
        int y=q.front().fi, x=q.front().se;
        q.pop();
        if (waypoint[y][x])
            ++cnt;
        for (int i=0; i<4; ++i) {
            int ny=y+ky[i], nx=x+kx[i];
            if (in(ny, nx) && ((abs(a[y][x]-a[ny][nx]))<=targ) && !vis[ny][nx]) {
                vis[ny][nx]=1;
                q.push({ny, nx});
            }
        }
    }
    return (cnt==wcnt);
}

int main(void) {
    fin >> n >> m;
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            fin >> a[i][j];
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j) {
            fin >> waypoint[i][j];
            if (waypoint[i][j])
                ++wcnt, ck={i, j};
        }
    int lo=0, hi=1e9+1, best;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (works(mid)) {
            best=mid;
            hi=mid-1;
        }
        else
            lo=mid+1;
    }
    fout << best << '\n';
}
