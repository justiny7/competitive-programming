#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int, int> pii;

int n, m, d[1001][1001], d2[1001][1001], Y, X;
pii A;
char l[1001][1001];
vector<pii> e, mon; //exits, monsters
bool pos, vis[1001][1001], vis2[1001][1001];
string ans;

void dfs(int y, int x, int cur) {
    if (ans.length()!=d2[Y][X]) {
        if (y+1<n && d2[y+1][x]==cur-1) {
            ans+='U';
            dfs(y+1, x, cur-1);
            return;
        }
        if (y-1>=0 && d2[y-1][x]==cur-1) {
            ans+='D';
            dfs(y-1, x, cur-1);
            return;
        }
        if (x+1<m && d2[y][x+1]==cur-1) {
            ans+='L';
            dfs(y, x+1, cur-1);
            return;
        }
        if (x-1>=0 && d2[y][x-1]==cur-1) {
            ans+='R';
            dfs(y, x-1, cur-1);
            return;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j) {
            char c;
            cin >> c;
            if (i==0 || j==0 || i==n-1 || j==m-1) {
                if (c=='.')
                    e.pb({i, j});
                if (c=='A') {
                    cout << "YES\n0\n\n";
                    return 0;
                }
            }
            l[i][j]=c;
            if (c=='A')
                A={i, j};
            if (c=='M')
                mon.pb({i, j});
        }
    queue<pair<int, pii>> q;
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j) {
            d[i][j]=d2[i][j]=1e9;
            if (l[i][j]=='#')
                vis[i][j]=vis2[i][j]=1;
        }
    for (pii& p : mon) { //bfs from each monster
        q.push({0, p});
        d[p.fi][p.se]=0;
        vis[p.fi][p.se]=1;
    }
    while (!q.empty()) {
        int y=q.front().se.fi, x=q.front().se.se, dst=q.front().fi;
        q.pop();
        d[y][x]=dst;
        if (y+1<n && !vis[y+1][x]) {
            vis[y+1][x]=1;
            q.push({dst+1, {y+1, x}});
        }
        if (y-1>=0 && !vis[y-1][x]) {
            vis[y-1][x]=1;
            q.push({dst+1, {y-1, x}});
        }
        if (x+1<m && !vis[y][x+1]) {
            vis[y][x+1]=1;
            q.push({dst+1, {y, x+1}});
        }
        if (x-1>=0 && !vis[y][x-1]) {
            vis[y][x-1]=1;
            q.push({dst+1, {y, x-1}});
        }
    }
    q.push({0, A});
    vis2[A.fi][A.se]=1;
    d2[A.fi][A.se]=0;
    while (!q.empty()) {
        int y=q.front().se.fi, x=q.front().se.se, dst=q.front().fi;
        q.pop();
        d2[y][x]=dst;
        if (y+1<n && !vis2[y+1][x]) {
            vis2[y+1][x]=1;
            q.push({dst+1, {y+1, x}});
        }
        if (y-1>=0 && !vis2[y-1][x]) {
            vis2[y-1][x]=1;
            q.push({dst+1, {y-1, x}});
        }
        if (x+1<m && !vis2[y][x+1]) {
            vis2[y][x+1]=1;
            q.push({dst+1, {y, x+1}});
        }
        if (x-1>=0 && !vis2[y][x-1]) {
            vis2[y][x-1]=1;
            q.push({dst+1, {y, x-1}});
        }
    }
    for (auto& p : e)
        if (d2[p.fi][p.se]<d[p.fi][p.se]) {
            pos=1;
            Y=p.fi, X=p.se;
            break;
        }/*
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j)
            cout << d2[i][j] << " ";
        cout << '\n';
    }*/
    if (!pos && !mon.empty()) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << d2[Y][X] << '\n';
    dfs(Y, X, d2[Y][X]);
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}
