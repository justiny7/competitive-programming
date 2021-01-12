#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3+1, dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
int n, k, st[mxN][mxN], wall[mxN][mxN];
string s[mxN];
bool vis[mxN][mxN];
queue<array<int, 3>> q;
priority_queue<array<int, 3>> pq;

inline bool in(int y, int x) {
    return (x>=0 && y>=0 && x<n && y<n);
}

int main() {
    memset(st, -1, sizeof(st));
    memset(wall, -1, sizeof(wall));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=0; i<n; ++i) {
        cin >> s[i];
        for (int j=0; j<n; ++j)
            if (s[i][j]=='#')
                q.push({i, j, 0});
    }
    while (q.size()) {
        int y=q.front()[0], x=q.front()[1], d=q.front()[2];
        q.pop();
        if (~wall[y][x])
            continue;
        wall[y][x]=d;
        for (int i=0; i<4; ++i) {
            int ny=y+dy[i], nx=x+dx[i];
            if (in(ny, nx) && s[ny][nx]^'#')
                q.push({ny, nx, d+1});
        }
    }
    for (int i=0; i<n; ++i)
        for( int j=0; j<n; ++j)
            if (s[i][j]=='S')
                q.push({i, j, 0});
    while (q.size()) {
        int y=q.front()[0], x=q.front()[1], d=q.front()[2];
        q.pop();
        bool f=(~st[y][x])|((d%k)?(d/k>=wall[y][x]):(d/k>wall[y][x]));
        if (f)
            continue;
        if ((d%k) || ((d/k)^wall[y][x]))
            st[y][x]=d/k;
        else {
            st[y][x]=d/k-1;
            continue;
        }
        for (int i=0; i<4; ++i) {
            int ny=y+dy[i], nx=x+dx[i];
            if (in(ny, nx) && s[ny][nx]^'#')
                q.push({ny, nx, d+1});
        }
    }
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if (~st[i][j])
                pq.push({st[i][j], i, j});
    while (pq.size()) {
        array<int, 3> here=pq.top(); pq.pop();
        int o=here[0], y=here[1], x=here[2];
        if (vis[y][x])
            continue;
        vis[y][x]=1;
        if (o<=0)
            continue;
        for (int i=0; i<4; ++i) {
            int ny=y+dy[i], nx=x+dx[i];
            if (in(ny, nx) && s[ny][nx]^'#' && !vis[ny][nx])
                pq.push({o-1, ny, nx});
        }
    }
    int ans=0;
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            ans+=vis[i][j];
    cout << ans << '\n';
}

