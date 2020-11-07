#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
//Yay another ridiculous solution but it worked second try with relatively little debugging
ifstream fin("cownav.in");
ofstream fout("cownav.out");

struct state {
    int y, x, dir;
    bool done=0;
    state(int y, int x, int dir, bool done):y(y), x(x), dir(dir), done(done) {}
};

const int mxN=20, ky[]={1,0,-1,0}, kx[]={0,1,0,-1};
int n, v[mxN][mxN][4][mxN][mxN][4];
string a[mxN];

int get(int x, int d) {
    return (x+4+d)%4;
}

bool ok(int y, int x) {
    return (a[y][x]!='H');
}

bool in(int y, int x) {
    return (y>=0 && x>=0 && y<n && x<n);
}

int main() {
    memset(v, -1, sizeof(v));
    fin >> n;
    for (int i=0; i<n; ++i)
        fin >> a[n-i-1];
    queue<pair<state, state>> q;
    q.push({state(0, 0, 0, 0), state(0, 0, 1, 0)});
    v[0][0][0][0][0][1]=0;
    while (!q.empty()) {
        state c1=q.front().fi, c2=q.front().se;
        q.pop();
        int x1=c1.x, x2=c2.x, y1=c1.y, y2=c2.y, d1=c1.dir, d2=c2.dir,
            cur=v[y1][x1][d1][y2][x2][d2];
        if (x1==n-1 && y1==n-1)
            c1.done=1;
        if (x2==n-1 && y2==n-1)
            c2.done=1;
        if (c1.done && c2.done) {
            fout << cur << '\n';
            return 0;
        }
        for (int i=-1; i<=1; ++i) {
            if (!i) {
                int ny1=y1+ky[d1], nx1=x1+kx[d1],
                    ny2=y2+ky[d2], nx2=x2+kx[d2];
                if (c1.done || !in(ny1, nx1) || !ok(ny1, nx1))
                    ny1=y1, nx1=x1;
                if (c2.done || !in(ny2, nx2) || !ok(ny2, nx2))
                    ny2=y2, nx2=x2;
                if (v[ny1][nx1][d1][ny2][nx2][d2]<0) {
                    v[ny1][nx1][d1][ny2][nx2][d2]=cur+1;
                    q.push({state(ny1, nx1, d1, c1.done), state(ny2, nx2, d2, c2.done)});
                }
            }
            else {
                int nd1=get(d1, i), nd2=get(d2, i);
                if (v[y1][x1][nd1][y2][x2][nd2]<0) {
                    v[y1][x1][nd1][y2][x2][nd2]=cur+1;
                    q.push({state(y1, x1, nd1, c1.done), state(y2, x2, nd2, c2.done)});
                }
            }
        }
    }
}
