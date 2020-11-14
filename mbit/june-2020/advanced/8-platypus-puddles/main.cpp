#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;
using ppll=pair<ll, pll>;

const int mxN=1e3+5, dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
ll n, ans, a[mxN][mxN], vis[mxN][mxN];
priority_queue<ppll, vector<ppll>, greater<ppll>> pq;

bool in(int cx, int cy) {
    return (~cx && cx<n && ~cy && cy<n);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j) {
            cin >> a[i][j];
            if (!i || !j || i==n-1 || j==n-1)
                pq.push(ppll(a[i][j], pll(i, j)));
        }
    while (pq.size()) {
        ppll cur=pq.top(); pq.pop();
        int cx=cur.y.x, cy=cur.y.y;
        if (vis[cx][cy])
            continue;
        vis[cx][cy]=1, ans+=cur.x-a[cx][cy];
        for (int i=0; i<4; ++i) {
            int nx=cx+dx[i], ny=cy+dy[i];
            if (in(nx, ny))
                pq.push(ppll(max(a[nx][ny], cur.x), pll(nx, ny)));
        }
    }
    cout << ans << '\n';
}

