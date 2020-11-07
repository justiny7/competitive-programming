#include <bits/stdc++.h>
using namespace std;

ifstream fin("cowart.in");
ofstream fout("cowart.out");

const int mxN=101, kx[]={0,1,0,-1}, ky[]={1,0,-1,0};
int n, grp1[mxN][mxN], grp2[mxN][mxN], c1, c2;
string a[mxN];

bool in(int y, int x) {
    return (y>=0 && x>=0 && y<n && x<n);
}

void dfs1(int y, int x, bool b) {
    grp1[y][x]=c1;
    for (int i=0; i<4; ++i) {
        int ny=y+ky[i], nx=x+kx[i];
        if (in(ny, nx) && !grp1[ny][nx] && b==(a[ny][nx]=='B'))
            dfs1(ny, nx, b);
    }
}

void dfs2(int y, int x, char c) {
    grp2[y][x]=c2;
    for (int i=0; i<4; ++i) {
        int ny=y+ky[i], nx=x+kx[i];
        if (in(ny, nx) && !grp2[ny][nx] && a[ny][nx]==c)
            dfs2(ny, nx, c);
    }
}

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i)
        fin >> a[i];
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j) {
            if (!grp1[i][j]) {
                ++c1;
                dfs1(i, j, (a[i][j]=='B'));
            }
            if (!grp2[i][j]) {
                ++c2;
                dfs2(i, j, a[i][j]);
            }
        }
    fout << c2 << " " << c1 << '\n';
}
