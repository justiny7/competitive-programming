//Yay worked first try
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3+1, dy[]={0,1,0,-1}, dx[]={1,0,-1,0};
int n, area, per, mxa, mnp=INT_MAX;
bool mat[mxN][mxN], vis[mxN][mxN];

bool in(int y, int x) {
    return (y>=0 && x>=0 && y<n && x<n);
}

void dfs(int y, int x) {
    ++area, vis[y][x]=1;
    for (int i=0; i<4; ++i) {
        int ny=y+dy[i], nx=x+dx[i];
        if (in(ny, nx) && mat[ny][nx] && !vis[ny][nx])
            dfs(ny, nx);
        else if (!in(ny, nx) || (in(ny, nx) && !mat[ny][nx]))
            ++per;
    }
}

int main() {
    ifstream cin("perimeter.in");
    ofstream cout("perimeter.out");
    cin >> n;
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j) {
            char c; cin >> c;
            mat[i][j]=(c=='#');
        }
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if (!vis[i][j] && mat[i][j]) {
                area=0, per=0;
                dfs(i, j);
                if (area>mxa)
                    mnp=INT_MAX;
                if (area>=mxa)
                    mxa=area, mnp=min(mnp, per);
            }
    cout << mxa << " " << mnp << '\n';
}

