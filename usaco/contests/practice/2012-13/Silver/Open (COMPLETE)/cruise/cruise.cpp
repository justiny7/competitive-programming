#include <bits/stdc++.h>
#define pb push_back
using namespace std;
//Took a little debugging but I got it in the end
ifstream fin("cruise.in");
ofstream fout("cruise.out");

struct port {
    int l, r;
};

const int mxN=1e3+1;
int n, m, to[mxN];
long long k;
vector<int> path;
port p[mxN];
bool seq[mxN], vis[mxN];

int main(void) {
    fin >> n >> m >> k;
    for (int i=1; i<=n; ++i)
        fin >> p[i].l >> p[i].r;
    for (int i=0; i<m; ++i) {
        char c; fin >> c;
        seq[i]=(c=='R');
    }
    for (int i=1; i<=n; ++i) {
        int cur=i;
        for (int j=0; j<m; ++j)
            cur=(seq[j])?p[cur].r:p[cur].l;
        to[i]=cur;
    }
    int c=1, cnt=0;
    do {
        vis[c]=1, ++cnt;
        c=to[c];
    } while (!vis[c]);
    int s=1;
    path.pb(c);
    for (int i=to[c]; i!=c; ++s)
        path.pb(i), i=to[i];
    fout << path[(k-(cnt-s))%s] << '\n';
}

