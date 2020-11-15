#include <bits/stdc++.h>
using namespace std;
using pii=pair<int, int>;

const int mxN=1e3+1, dx[]={-1,0,1,0}, dy[]={0,1,0,-1};
int n, m, k, b, cur, mp[256];
string s;
queue<pii> nxt[4];
bool vis[mxN][mxN];

bool in(int x, int y) {
    return (x>0 && x<=n && y>0 && y<=m);
}

int main() {
    mp['N']=0, mp['E']=1, mp['S']=2, mp['W']=3;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k >> b >> s;
    cur=k;
    {
        vector<pii> v;
        while (k--) {
            int x, y;
            cin >> x >> y;
            v.push_back(pii(x, y));
            vis[x][y]=1;
        }
        for (auto p:v) {
            int x=p.first, y=p.second;
            for (int i=0; i<4; ++i) {
                int nx=x+dx[i], ny=y+dy[i];
                if (in(nx, ny) && !vis[nx][ny])
                    nxt[i].push(pii(nx, ny));
            }
        }
    }
    for (int t=0; t<b; ++t) {
        int dir=mp[s[t]];
        vector<pii> v;
        while (nxt[dir].size())
            v.push_back(nxt[dir].front()), nxt[dir].pop();
        for (auto p:v) {
            int x=p.first, y=p.second;
            if (vis[x][y])
                continue;
            vis[x][y]=1;
            ++cur;
            for (int i=0; i<4; ++i) {
                int nx=x+dx[i], ny=y+dy[i];
                if (in(nx, ny) && !vis[nx][ny])
                    nxt[i].push(pii(nx, ny));
            }
        }
        cout << cur << '\n';
    }
}

