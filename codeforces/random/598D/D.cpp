#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3+1, dy[]={0,1,0,-1}, dx[]={1,0,-1,0};
int n, m, k, cnt, cur, grp[mxN][mxN], mp[mxN*mxN];
string s[mxN];

void dfs(int y, int x) {
    grp[y][x]=cur;
    for (int i=0; i<4; ++i) {
        int ny=y+dy[i], nx=x+dx[i];
        if (!grp[ny][nx] && s[ny][nx]^'*')
            dfs(ny, nx);
        else if (s[ny][nx]=='*')
            ++cnt;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i=0; i<n; ++i)
        cin >> s[i];
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            if (!grp[i][j] && s[i][j]^'*')
                cnt=0, ++cur, dfs(i, j), mp[cur]=cnt;
    while (k--) {
        int y, x;
        cin >> y >> x, --y, --x;
        cout << mp[grp[y][x]] << '\n';
    }
}

