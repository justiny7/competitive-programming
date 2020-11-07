#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//Ok wtf I spend over an hour debugging this crap and in the end the reason why it
//took like 10 submissions was because I didn't put a[] and ans as long longs sigh
ifstream fin("superbull.in");
ofstream fout("superbull.out");

const int mxN=2001;
int n, sz;
ll ans, a[mxN], dist[mxN], w[mxN][mxN];
bool in[mxN];

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i)
        fin >> a[i];
    memset(w, -1, sizeof(w));
    fill(dist, dist+n, LLONG_MIN);
    for (int i=0; i<n; ++i)
        for (int j=i+1; j<n; ++j)
            w[i][j]=w[j][i]=a[i]^a[j];
    dist[0]=0;
    while (sz<n) {
        ll cmax=LLONG_MIN;
        int v;
        for (int i=0; i<n; ++i)
            if (!in[i] && dist[i]>cmax)
                cmax=dist[i], v=i;
        assert(cmax>=0);
        ++sz, ans+=dist[v], in[v]=1;
        for (int i=0; i<n; ++i)
            if (!in[i] && w[v][i]>=0 && dist[i]<w[v][i])
                dist[i]=w[v][i];
    }
    fout << ans << '\n';
}
