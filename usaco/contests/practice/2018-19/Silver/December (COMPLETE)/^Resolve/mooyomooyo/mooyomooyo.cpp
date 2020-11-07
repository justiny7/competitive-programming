//Yay worked first try
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using pii=pair<int, int>;

const int mxN=101, dy[]={0,1,0,-1}, dx[]={1,0,-1,0};
int n, k, a[mxN][mxN];
vector<pii> nxt;
bool vis[mxN][mxN];

bool in(int y, int x) {
    return (y>=0 && x>=0 && y<n && x<10);
}
void dfs(int y, int x) {
    vis[y][x]=1, nxt.pb(pii(y, x));
    for (int i=0; i<4; ++i) {
        int ny=y+dy[i], nx=x+dx[i];
        if (in(ny, nx) && a[ny][nx]==a[y][x] && !vis[ny][nx])
            dfs(ny, nx);
    }
}
bool del() {
    memset(vis, 0, sizeof(vis));
    bool f=0;
    for (int i=0; i<n; ++i)
        for (int j=0; j<10; ++j)
            if (a[i][j] && !vis[i][j]) {
                nxt.clear();
                dfs(i, j);
                if (nxt.size()>=k) {
                    f=1;
                    for (auto p:nxt)
                        a[p.fi][p.se]=0;
                }
            }
    return f;
}
void shift() {
    for (int i=0; i<10; ++i) {
        vector<int> ord;
        for (int j=n-1; ~j; --j)
            if (a[j][i])
                ord.pb(a[j][i]);
        for (int j=n-1, k=0; ~j; --j) {
            if (k<ord.size())
                a[j][i]=ord[k++];
            else
                a[j][i]=0;
        }
    }
}

int main() {
    ifstream cin("mooyomooyo.in");
    ofstream cout("mooyomooyo.out");
    cin >> n >> k;
    for (int i=0; i<n; ++i)
        for (int j=0; j<10; ++j) {
            char c; cin >> c;
            a[i][j]=(c-'0');
        }
    while (del())
        shift();
    for (int i=0; i<n; ++i)
        for (int j=0; j<10; ++j)
            cout << a[i][j] << (j<9?"":"\n");
}

