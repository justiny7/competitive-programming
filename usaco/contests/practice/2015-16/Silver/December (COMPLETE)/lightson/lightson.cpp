//USACO Silver December 2015 Problem 1
#include <bits/stdc++.h>
using namespace std;
//I did this problem before
int n, m, ans, curr;
bool can[101][101], vis[101][101], pos;
map<pair<int, int>, vector<pair<int, int>>> adj;

void dfs(int x, int y) {
    if (can[x][y] == 0 || vis[x][y])
        return;
    curr++;
    for (auto p : adj[{x, y}])
        can[p.first][p.second] = true;
    vis[x][y] = true;
    if (x > 1)
        dfs(x-1, y);
    if (x < n)
        dfs(x+1, y);
    if (y > 1)
        dfs(x, y-1);
    if (y < n)
        dfs(x, y+1);
}

int main(void) {
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        adj[{a, b}].push_back({c, d});
    }
    can[1][1] = true;
    int last = -1;
    while (1) {
        curr = 0;
        memset(vis, false, sizeof(vis));
        dfs(1, 1);
        if (last == curr)
            break;
        last = curr;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (can[i][j])
                ans++;
    cout << ans << '\n';
    return 0;
}

