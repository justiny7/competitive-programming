#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, m, sx, sy, ex, ey, dist[1001][1001], kx[4]={1, 0, -1, 0}, ky[4]={0, 1, 0, -1};
vector<int> path;
string dir[4]={"L", "U", "R", "D"};
bool l[1001][1001];

void dfs(int cx, int cy) {
    if (dist[cy][cx]==0)
        return;
    for (int i=0; i<4; i++)
        if (cy+ky[i]>=0 && cy+ky[i]<n && cx+kx[i]>=0 && cx+kx[i]<m && dist[cy+ky[i]][cx+kx[i]]==dist[cy][cx]-1) {
            path.push_back(i);
            dfs(cx+kx[i], cy+ky[i]);
            break;
        }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            char c;
            cin >> c;
            l[i][j]=(c=='#');
            if (c=='A') {
                sx=j;
                sy=i;
            }
            if (c=='B') {
                ex=j;
                ey=i;
            }
            dist[i][j]=-1;
        }
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {sx, sy}});
    l[sy][sx]=1;
    while (!q.empty()) {
        int d=q.front().fi, x=q.front().se.fi, y=q.front().se.se;
        q.pop();
        dist[y][x]=d;
        if (x==ex && y==ey) {
            dfs(x, y);
            cout << "YES\n" << d << '\n';
            for (int i=path.size()-1; i>=0; i--)
                cout << dir[path[i]];
            cout << '\n';
            return 0;
        }
        if (y+1<n && !l[y+1][x]) {
            q.push({d+1, {x, y+1}});
            l[y+1][x]=1;
        }
        if (y-1>=0 && !l[y-1][x]) {
            q.push({d+1, {x, y-1}});
            l[y-1][x]=1;
        }
        if (x+1<m && !l[y][x+1]) {
            q.push({d+1, {x+1, y}});
            l[y][x+1]=1;
        }
        if (x-1 >= 0 && !l[y][x-1]) {
            q.push({d+1, {x-1, y}});
            l[y][x-1]=1;
        }
    }
    cout << "NO\n";
}
