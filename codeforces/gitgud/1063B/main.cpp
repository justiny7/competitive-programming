#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;

const int mxN=2e3+1, dy[]={0,1,0,-1}, dx[]={1,0,-1,0};
int n, m, r, c, llim, rlim, ans;
string s[mxN];
pii state[mxN][mxN];
queue<pii> q;

bool in(int y, int x) {
    return (y>=0 && x>=0 && y<n && x<m);
}

int main() {
    memset(state, -1, sizeof(state));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> r >> c >> llim >> rlim, --r, --c;
    for (int i=0; i<n; ++i)
        cin >> s[i];
    state[r][c]=pii(llim, rlim);
    q.push(pii(r, c));
    while (q.size()) {
        int y=q.front().fi, x=q.front().se, lm=state[y][x].fi, rm=state[y][x].se;
        q.pop();
        for (int i=0; i<4; ++i) {
            int ny=y+dy[i], nx=x+dx[i];
            if (!in(ny, nx) || s[ny][nx]=='*')
                continue;
            if (~state[ny][nx].fi) {
                if (state[ny][nx].fi>=(lm-(i==2)) && state[ny][nx].se>=(rm-(i==0)))
                    continue;
            }
            if ((!i && !state[y][x].se) || (i==2 && !state[y][x].fi))
                continue;
            state[ny][nx]=pii(max(state[ny][nx].fi, lm-(i==2)), max(state[ny][nx].se, rm-(i==0)));
            q.push(pii(ny, nx));
        }
    }
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            if (~state[i][j].fi)
                ++ans;
    cout << ans << '\n';
}

