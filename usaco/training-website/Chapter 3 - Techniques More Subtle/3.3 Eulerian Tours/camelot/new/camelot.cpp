/*
ID: justiny7
TASK: camelot
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

const int mxN=31, INF=0x3f3f3f3f, dx[]={1,2,2,1,-1,-2,-2,-1}, dy[]={2,1,-1,-2,-2,-1,1,2};
int n, m, kx, ky, d_tot[mxN][mxN], pickup[mxN][mxN], d_cur[2][mxN][mxN];
bool bad[mxN][mxN], f;

inline int k_dist(int cx, int cy) {
    return max(abs(kx-cx), abs(ky-cy));
}
inline bool in(int cx, int cy) {
    return (cx>0 && cx<=n && cy>0 && cy<=m);
}
void bfs(int sx, int sy) {
    d_cur[0][sx][sy]=0, d_cur[1][sx][sy]=k_dist(sx, sy);
    queue<array<int, 3>> q;
    q.push({sx, sy, 0});
    q.push({sx, sy, 1});
    while (q.size()) {
        int cx=q.front()[0], cy=q.front()[1], k=q.front()[2];
        q.pop();
        for (int i=0; i<8; ++i) {
            int nx=cx+dx[i], ny=cy+dy[i];
            if (in(nx, ny) && d_cur[k][nx][ny]>d_cur[k][cx][cy]+1) {
                d_cur[k][nx][ny]=d_cur[k][cx][cy]+1;
                if (!k)
                    d_cur[1][nx][ny]=min(d_cur[1][nx][ny], d_cur[k][nx][ny]+k_dist(nx, ny));
                q.push({nx, ny, 0});
                q.push({nx, ny, 1});
            }
        }
    }
}

int main() {
    memset(pickup, 0x3f, sizeof(pickup));
    ifstream cin("camelot.in");
    ofstream cout("camelot.out");
    cin >> m >> n;
    char c; int p;
    cin >> c >> p;
    kx=(c-'A')+1, ky=p;
    while (cin >> c >> p) {
        f=1;
        memset(d_cur, 0x3f, sizeof(d_cur));
        int sx=(c-'A')+1, sy=p;
        bfs(sx, sy);
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=m; ++j) {
                if (d_cur[0][i][j]^INF) {
                    d_tot[i][j]+=d_cur[0][i][j];
                    pickup[i][j]=min(pickup[i][j], d_cur[1][i][j]-d_cur[0][i][j]);
                }
                else
                    bad[i][j]=1;
            }
    }
    if (!f)
        return cout << "0\n", 0;
    int ans=INF;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            if (!bad[i][j])
                ans=min(ans, pickup[i][j]+d_tot[i][j]);
    cout << ans << '\n';
}
