#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define pf push_front
using namespace std;
using pii=pair<int, int>;

const int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
int n, m, k, out[2]={INT_MAX, INT_MAX};
vector<pii> rams;
vector<string> s;
vector<vector<int>> d_edge;
vector<vector<pii>> d_rams;
deque<pii> q;

bool in(int x, int y) {
    return (x>=0 && x<n && y>=0 && y<m);
}
void ins(int x, int y) {
    if (s[x][y]=='#')
        q.pb(pii(x, y));
    else
        q.pf(pii(x, y));
}
void go(int x, int y) {
    d_edge[x][y]=(s[x][y]=='#');
    ins(x, y);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    s.resize(n);
    rams.resize(k);
    d_edge.resize(n, vector<int>(m, INT_MAX));
    d_rams.resize(n, vector<pii>(m, pii(INT_MAX, INT_MAX)));
    for (int i=0; i<n; ++i)
        cin >> s[i];
    for (int i=0; i<k; ++i)
        cin >> rams[i].fi >> rams[i].se, --rams[i].fi, --rams[i].se;
    {
        for (int i=1; i<n-1; ++i) {
            go(i, 0); go(i, m-1);
        }
        for (int i=1; i<m-1; ++i) {
            go(0, i); go(n-1, i);
        }
        go(0, 0); go(0, m-1); go(n-1, 0); go(n-1, m-1);
        while (q.size()) {
            int x, y;
            tie(x, y)=q.front(); q.pop_front();
            for (int i=0; i<4; ++i) {
                int nx=x+dx[i], ny=y+dy[i], w=(in(nx, ny)?(s[nx][ny]=='#'):-1);
                if (~w && d_edge[x][y]+w<d_edge[nx][ny])
                    d_edge[nx][ny]=d_edge[x][y]+w, ins(nx, ny);
            }
        }
    }
    {
        for (pii p:rams) {
            vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
            q.pf(p);
            dist[p.fi][p.se]=0;
            while (q.size()) {
                int x, y;
                tie(x, y)=q.front(); q.pop_front();
                for (int i=0; i<4; ++i) {
                    int nx=x+dx[i], ny=y+dy[i], w=(in(nx, ny)?(s[nx][ny]=='#'):-1);
                    if (~w && dist[x][y]+w<dist[nx][ny])
                        dist[nx][ny]=dist[x][y]+w, ins(nx, ny);
                }
            }
            for (int i=0; i<n; ++i)
                for (int j=0; j<m; ++j) {
                    if (!i || !j || i==n-1 || j==m-1) {
                        if (dist[i][j]<out[0])
                            out[1]=out[0], out[0]=dist[i][j];
                        else
                            out[1]=min(out[1], dist[i][j]);
                    }
                    dist[i][j]-=(s[i][j]=='#');
                    if (dist[i][j]<d_rams[i][j].fi)
                        d_rams[i][j].se=d_rams[i][j].fi, d_rams[i][j].fi=dist[i][j];
                    else
                        d_rams[i][j].se=min(d_rams[i][j].se, dist[i][j]);
                }
        }
    }
    int ans=out[0]+out[1];
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            ans=min(ans, d_rams[i][j].fi+d_rams[i][j].se+d_edge[i][j]);
    cout << ans << '\n';
}

