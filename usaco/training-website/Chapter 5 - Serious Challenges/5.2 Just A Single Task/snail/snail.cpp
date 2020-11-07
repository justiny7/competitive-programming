/*
ID: justiny7
LANG: C++
TASK: snail
*/

//Pretty easy dfs problem except it took me 2 subs because I read the input wrong :c
#include <bits/stdc++.h>
using namespace std;

ifstream fin("snail.in");
ofstream fout("snail.out");

int n, b, ans, kx[]={1, 0, -1, 0}, ky[]={0, 1, 0, -1}, vis[121][121];

bool in(int a, int b) {
    return (a>=0 && b>=0 && a<n && b<n);
}

void dfs(int y, int x, int k, int len) {
    vis[y][x]=2;
    len++;
    ans=max(ans, len);
    int ny=y+ky[k], nx=x+kx[k];
    if (in(ny, nx) && !vis[ny][nx])
        dfs(ny, nx, k, len);
    else if (vis[ny][nx]==1 || !in(ny, nx)) {
        int nk1=(k+4+1)%4, nk2=(k+4-1)%4;
        if (in(y+ky[nk1], x+kx[nk1]) && !vis[y+ky[nk1]][x+kx[nk1]])
            dfs(y+ky[nk1], x+kx[nk1], nk1, len);
        if (in(y+ky[nk2], x+kx[nk2]) && !vis[y+ky[nk2]][x+kx[nk2]])
            dfs(y+ky[nk2], x+kx[nk2], nk2, len);
    }
    vis[y][x]=0;
}

int main(void) {
    fin >> n >> b;
    for (int i=0; i<b; ++i) {
        string s;
        fin >> s;
        vis[stoi(s.substr(1))-1][s[0]-'A']=1;
    }
    dfs(0, 0, 0, 0);
    dfs(0, 0, 1, 0);
    fout << ans << '\n';
}
