#include <bits/stdc++.h>
using namespace std;
//This problem was pretty easy but my solution was kinda ridiculous
ifstream fin("dream.in");
ofstream fout("dream.out");

struct state {
    int x, y, dir;
    bool orange=0;
    state(int y, int x, int dir, bool o):y(y), x(x), dir(dir), orange(o) {}
};

const int mxN=1e3+1, kx[]={0,1,0,-1}, ky[]={1,0,-1,0};
int n, m, a[mxN][mxN], b[2][4][mxN][mxN]; //min # of moves for each square given a smell and direction

bool in(int y, int x) {
    return (x>=0 && y>=0 && x<m && y<n);
}

int main(void) {
    memset(b, -1, sizeof(b));
    fin >> n >> m;
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            fin >> a[i][j];
    queue<state> q;
    q.push(state(0, 0, 0, 0));
    q.push(state(0, 0, 1, 0));
    b[0][0][0][0]=b[0][1][0][0]=0;
    while (!q.empty()) {
        state t=q.front();
        q.pop();
        bool o=t.orange;
        int cur=b[o][t.dir][t.y][t.x];
        if (a[t.y][t.x]==4) {
            int ny=t.y+ky[t.dir], nx=t.x+kx[t.dir];
            if (in(ny, nx)) {
                if (a[ny][nx]==0 || a[ny][nx]==3) {
                    for (int i=-1; i<2; i+=2) {
                        int nd=(t.dir+i+4)%4;
                        ny=t.y+ky[nd], nx=t.x+kx[nd];
                        if (!in(ny, nx))
                            continue;
                        if ((a[ny][nx]==1 || a[ny][nx]==4)
                                && b[0][nd][ny][nx]<0) {
                            b[0][nd][ny][nx]=cur+1;
                            q.push(state(ny, nx, nd, 0));
                        }
                        else if (a[ny][nx]==2 && b[1][nd][ny][nx]<0) {
                            b[1][nd][ny][nx]=cur+1;
                            q.push(state(ny, nx, nd, 1));
                        }
                    }
                }
                else if ((a[ny][nx]==1 || a[ny][nx]==4)
                        && b[0][t.dir][ny][nx]<0) {
                    b[0][t.dir][ny][nx]=cur+1;
                    q.push(state(ny, nx, t.dir, 0));
                }
                else if ((a[ny][nx]==2) && b[1][t.dir][ny][nx]<0) {
                    b[1][t.dir][ny][nx]=cur+1;
                    q.push(state(ny, nx, t.dir, 1));
                }
            }
            else {
                for (int i=-1; i<2; i+=2) {
                    int nd=(t.dir+i+4)%4;
                    ny=t.y+ky[nd], nx=t.x+kx[nd];
                    if (!in(ny, nx))
                        continue;
                    if ((a[ny][nx]==1 || a[ny][nx]==4)
                            && b[0][nd][ny][nx]<0) {
                        b[0][nd][ny][nx]=cur+1;
                        q.push(state(ny, nx, nd, 0));
                    }
                    else if (a[ny][nx]==2 && b[1][nd][ny][nx]<0) {
                        b[1][nd][ny][nx]=cur+1;
                        q.push(state(ny, nx, nd, 1));
                    }
                }
            }
        }
        else {
            for (int i=0; i<4; ++i) {
                int ny=t.y+ky[i], nx=t.x+kx[i];
                if (in(ny, nx)) {
                    if (a[ny][nx]==3 && o && b[1][i][ny][nx]<0) {
                        b[1][i][ny][nx]=cur+1;
                        q.push(state(ny, nx, i, 1));
                    }
                    else if (a[ny][nx]==1 && b[o][i][ny][nx]<0) {
                        b[o][i][ny][nx]=cur+1;
                        q.push(state(ny, nx, i, o));
                    }
                    else if (a[ny][nx]==4 && b[0][i][ny][nx]<0) {
                        b[0][i][ny][nx]=cur+1;
                        q.push(state(ny, nx, i, 0));
                    }
                    else if ((a[ny][nx]==2) && b[1][i][ny][nx]<0) {
                        b[1][i][ny][nx]=cur+1;
                        q.push(state(ny, nx, i, 1));
                    }
                }
            }
        }
    }
    int ans=INT_MAX;
    for (int s=0; s<2; ++s)
        for (int i=0; i<4; ++i)
            if (b[s][i][n-1][m-1]>=0)
                ans=min(ans, b[s][i][n-1][m-1]);
    fout << ((ans==INT_MAX)?-1:ans) << '\n';
}
