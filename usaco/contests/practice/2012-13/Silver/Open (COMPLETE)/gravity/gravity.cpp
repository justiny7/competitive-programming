/*
 * This one wasn't too hard but it took so long to debug
 * And also there were so many unclear things in the problem statement,
 * like they didn't specify that Docto Beefalo could be suspended in midair smh
*/

#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;

template<class T> bool ckmin(T& a, const T& b) {
    return ((b<a || a<0)?a=b, 1:0);
}

ifstream fin("gravity.in");
ofstream fout("gravity.out");

const int mxN=501, kx[]={-1,1};
int n, m, cy, cx, dy, dx, f[2][mxN][mxN];
string s[mxN];

bool in(int y, int x) {
    if ((y==0 || y==n-1) && x>=0 && x<m && s[y][x]=='D')
        return 1;
    return (y>0 && x>=0 && y<n-1 && x<m);
}

int fall(int y, int x, int g) {
    int ans=y;
    if (g&1)
        while (ans>0 && s[ans-1][x]!='#')
            ckmin(f[1][ans][x], g), --ans;
    else
        while (ans<n-1 && s[ans+1][x]!='#')
            ckmin(f[0][ans][x], g), ++ans;
    return ans;
}

int main(void) {
    fin >> n >> m;
    for (int i=0; i<n; ++i) {
        fin >> s[i];
        for (int j=0; j<m; ++j) {
            if (s[i][j]=='C')
                cy=i, cx=j;
            else if (s[i][j]=='D')
                dy=i, dx=j;
        }
    }
    memset(f, -1, sizeof(f));
    queue<pair<pii, int>> q;
    q.push({{cy, cx}, 0});
    f[0][cy][cx]=0;
    while (!q.empty()) {
        int y=q.front().fi.fi, x=q.front().fi.se, cur=q.front().se;
        q.pop();
        y=fall(y, x, cur);
        for (int i=0; i<2; ++i) {
            int nx=x+kx[i], p=cur&1;
            if (!in(y, nx) || (in(y, nx) && s[y][nx]=='#'))
                continue;
            int ny=fall(y, nx, cur);
            if (in(ny, nx) && ckmin(f[p][ny][nx], cur))
                q.push({{ny, nx}, cur});
        }
        int ny=fall(y, x, cur+1), p=(cur+1)&1;
        if (in(ny, x) && ckmin(f[p][ny][x], cur+1))
            q.push({{ny, x}, cur+1});
    }
    //for (int p=0; p<2; ++p) {
        //for (int i=0; i<n; ++i) {
            //for (int j=0; j<m; ++j)
                //cout << f[p][i][j] << '\t';
            //cout << '\n';
        //}
        //cout << '\n';
    //}
    int ans1=f[0][dy][dx], ans2=f[1][dy][dx];
    if (ans1>=0 && ans2>=0)
        fout << min(ans1, ans2);
    else if (ans1>=0)
        fout << ans1;
    else if (ans2>=0)
        fout << ans2;
    else
        fout << -1;
    fout << '\n';
}
