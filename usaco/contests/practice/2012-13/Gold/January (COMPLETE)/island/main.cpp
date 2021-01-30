//Yay worked second try after a small typo
//Floodfill + multisource bfs + bitmask dp
#include <bits/stdc++.h>
using namespace std;

const int mxN=15, mxL=51, dy[]={1,0,-1,0}, dx[]={0,1,0,-1};
int n, r, c, col, ans=INT_MAX, grp[mxL][mxL], dist[mxL][mxL], d[mxN][mxN], dp[1<<mxN][mxN];
string s[mxL];

bool in(int y, int x) {
    return (y>=0 && x>=0 && y<r && x<c);
}
void dfs(int y, int x) {
    grp[y][x]=col;
    for (int i=0; i<4; ++i) {
        int ny=y+dy[i], nx=x+dx[i];
        if (in(ny, nx) && grp[ny][nx]<0 && s[ny][nx]==s[y][x])
            dfs(ny, nx);
    }
}

int main() {
    memset(grp, -1, sizeof(grp));
    memset(d, 0x3f, sizeof(d));
    memset(dp, 0x3f, sizeof(dp));
    ifstream cin("island.in");
    ofstream cout("island.out");
    cin >> r >> c;
    for (int i=0; i<r; ++i)
        cin >> s[i];
    for (int i=0; i<r; ++i) {
        for (int j=0; j<c; ++j) {
            if (~grp[i][j] || s[i][j]^'X')
                continue;
            dfs(i, j), ++col;
        }
    }
    for (int i=0; i<col; ++i) {
        memset(dist, -1, sizeof(dist));
        deque<pair<int, int>> q;
        for (int j=0; j<r; ++j)
            for (int k=0; k<c; ++k)
                if (grp[j][k]==i)
                    q.emplace_back(j, k), dist[j][k]=0;
        while (q.size()) {
            int y, x;
            tie(y, x)=q.front(); q.pop_front();
            for (int j=0; j<4; ++j) {
                int ny=y+dy[j], nx=x+dx[j], w=((in(ny, nx) && s[ny][nx]^'.')?(s[ny][nx]=='S'):-1);
                if (~w && dist[ny][nx]<0) {
                    dist[ny][nx]=dist[y][x]+w;
                    if (w)
                        q.emplace_back(ny, nx);
                    else
                        q.emplace_front(ny, nx);
                }
            }
        }
        for (int j=0; j<r; ++j)
            for (int k=0; k<c; ++k)
                if (~dist[j][k] && ~grp[j][k])
                    d[i][grp[j][k]]=d[grp[j][k]][i]=min(d[i][grp[j][k]], dist[j][k]);
    }
    for (int i=1; i<(1<<col); ++i) {
        vector<int> here;
        for (int j=0; j<col; ++j)
            if (i&(1<<j))
                here.push_back(j);
        if (here.size()==1)
            dp[i][here[0]]=0;
        else {
            for (int k:here) { //adding cow k
                int j=i&(~(1<<k));
                for (int l=0; l<col; ++l)
                    if (j&(1<<l))
                        dp[i][k]=min(dp[i][k], dp[j][l]+d[l][k]);
            }
        }
    }
    for (int i=0; i<col; ++i)
        ans=min(ans, dp[(1<<col)-1][i]);
    cout << ans << '\n';
}

