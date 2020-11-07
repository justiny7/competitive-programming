#include <bits/stdc++.h>
using namespace std;

ifstream fin("dream.in");
ofstream fout("dream.out");

struct state {
    int y, x, dir;
    bool orange;
    state(int y, int x, int dir, bool o):y(y), x(x), dir(dir), orange(o) {}
};

const int mxN=1e3+1, kx[]={1,0,-1,0}, ky[]={0,1,0,-1};
int n, m, a[mxN][mxN], b[2][4][mxN][mxN];

bool in(int y, int x) {
    return (y>=0 && x>=0 && y<n && x<m);
}

int main(void) {
    memset(b, -1, sizeof(b));
    fin >> n >> m;
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            fin >> a[i][j];
    queue<state> q;
    q.push(state(0, 0, 0, 0));
    b[0][0][0][0]=0;
    while (!q.empty()) {
        state t=q.front();
        q.pop();
        bool o=t.orange;
        int cd=t.dir, cy=t.y, cx=t.x, cur=b[o][cd][cy][cx];
        if (cy==n-1 && cx==m-1) {
            fout << cur << '\n';
            return 0;
        }
        if (a[cy][cx]==4) {
            int ny=cy+ky[cd], nx=cx+kx[cd];
            if (in(ny, nx) && a[ny][nx] && a[ny][nx]!=3) {
                bool no=(a[ny][nx]==2)?1:0;
                if (b[no][cd][ny][nx]<0) {
                    b[no][cd][ny][nx]=cur+1;
                    q.push(state(ny, nx, cd, no));
                    continue;
                }
            }
        }
        for (int i=0; i<4; ++i) {
            int ny=cy+ky[i], nx=cx+kx[i];
            if (in(ny, nx) && a[ny][nx]) {
                if (a[ny][nx]==3 && !o)
                    continue;
                bool no=(a[ny][nx]==4)?0:(a[ny][nx]==2)?1:o;
                if (b[no][i][ny][nx]<0) {
                    b[no][i][ny][nx]=cur+1;
                    q.push(state(ny, nx, i, no));
                }
            }
        }
    }
    fout << "-1\n";
}
