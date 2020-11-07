//Yay worked first try
#include <bits/stdc++.h>
using namespace std;

const int ky[]={1,0,-1,0}, kx[]={0,1,0,-1};
int n, ans, minx=INT_MAX, miny=INT_MAX;
map<int, map<int, bool>> a, vis[4];

int main() { //Just copied my code from silv version - prob super overkill
    ifstream cin("perimeter.in");
    ofstream cout("perimeter.out");
    cin >> n;
    for (int i=0; i<n; ++i) {
        int x, y;
        cin >> x >> y;
        a[x][y]=1;
        if (x<minx)
            miny=INT_MAX;
        if (x<=minx)
            minx=x, miny=min(miny, y);
    }
    int x=--minx, y=miny, d=0, lc=0;
    vis[d][x][y]=1;
    while (1) {
        ++ans;
        int nd=(d+1)%4;
        if (!a[x+kx[d]+kx[nd]][y+ky[d]+ky[nd]] &&
            a[x+kx[nd]][y+ky[nd]] &&
            !a[x+kx[d]][y+ky[d]]) {
            x+=kx[d]+kx[nd], y+=ky[d]+ky[nd];
            if (!vis[nd][x][y]) {
                vis[nd][x][y]=1, lc=0, d=nd;
                continue;
            }
            else
                break;
        }
        if (!a[x+kx[d]][y+ky[d]]) {
            x+=kx[d], y+=ky[d];
            if (!vis[d][x][y]) {
                vis[d][x][y]=1, lc=0;
                continue;
            }
            else
                break;
        }
        d=(d+3)%4, ++lc;
        if (lc==4)
            break;
    }
    cout << ans << '\n';
}

