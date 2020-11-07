#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<int, int>;
//Yay worked first try - relatively easy dp
ifstream fin("radio.in");
ofstream fout("radio.out");

template<class T> bool ckmin(T& a, const T& b) {
    return (a>b)?a=b, 1:0;
}

const int mxN=1e3+1;
int n, m, fx, fy, bx, by, x[256], y[256];
ll dp[mxN][mxN];
pii fjpos[mxN], bpos[mxN];
string fs, bs;

ll dist(pii a, pii b) {
    return ll((a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se));
}

int main(void) {
    fin >> n >> m >> fx >> fy >> bx >> by >> fs >> bs;
    x['E']=y['N']=1;
    x['W']=y['S']=-1;
    fjpos[0]={fx, fy};
    bpos[0]={bx, by};
    for (int i=0; i<n; ++i) {
        fjpos[i+1].fi=fjpos[i].fi+x[fs[i]];
        fjpos[i+1].se=fjpos[i].se+y[fs[i]];
    }
    for (int i=0; i<m; ++i) {
        bpos[i+1].fi=bpos[i].fi+x[bs[i]];
        bpos[i+1].se=bpos[i].se+y[bs[i]];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0]=0;
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j) { //either FJ moves, Bessie moves, or both move
            ckmin(dp[i+1][j], dp[i][j]+dist(fjpos[i+1], bpos[j]));
            ckmin(dp[i][j+1], dp[i][j]+dist(fjpos[i], bpos[j+1]));
            ckmin(dp[i+1][j+1], dp[i][j]+dist(fjpos[i+1], bpos[j+1]));
        }
    fout << dp[n][m] << '\n';
}

