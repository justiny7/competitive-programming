#include <bits/stdc++.h>
using namespace std;
//Worked second try because of a typo :c
ifstream fin("tractor.in");
ofstream fout("tractor.out");

const int mxN=501, ky[]={0,1,0,-1}, kx[]={1,0,-1,0};
int n, a[mxN][mxN], g[mxN][mxN];

bool in(int y, int x) {
    return (y>=0 && x>=0 && y<n && x<n);
}

int dfs(int y, int x, int l, int step) {
    g[y][x]=l;
    int tot=1;
    for (int i=0; i<4; ++i) {
        int ny=y+ky[i], nx=x+kx[i];
        if (in(ny, nx) && !g[ny][nx] && abs(a[ny][nx]-a[y][x])<=step)
            tot+=dfs(ny, nx, l, step);
    }
    return tot;
}

bool works(int x) {
    int cnt=0, grp=1;
    memset(g, 0, sizeof(g));
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if (!g[i][j])
                cnt=max(cnt, dfs(i, j, grp++, x));
    return (cnt>=(n*n+1)/2);
}

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            fin >> a[i][j];
    int lo=0, hi=int(1e6);
    while (lo<hi) {
        int mid=(lo+hi)/2;
        if (works(mid))
            hi=mid;
        else
            lo=mid+1;
    }
    fout << lo << '\n';
}
