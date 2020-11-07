#include <bits/stdc++.h>
using namespace std;
//I had no idea how to do this so I resorted to the solution and I still have no
//idea how it works
ifstream fin("shuffle.in");
ofstream fout("shuffle.out");

const int mxN=1e5+1;
int n, m, dif, q, p[mxN], x[mxN], y[mxN];

void go(int a[], int b[], int c[], int n) {
    for (int i=0; i<n; ++i)
        a[i]=b[c[i]];
}

int main(void) {
    fin >> n >> m >> q;
    for (int i=0; i<n; ++i) {
        x[i]=i;
        if (i<m) {
            int a; fin >> a, --a;
            p[a]=i;
        }
        else
            p[i]=i;
    }
    rotate(p, p+1, p+n);
    dif=n-m+1;
    for (int i=31-__builtin_clz(dif); i>=0; --i) {
        go(y, x, x, n);
        memcpy(x, y, sizeof(x));
        if (dif&1<<i) {
            go(y, x, p, n);
            memcpy(x, y, sizeof(x));
        }
    }
    while (q--) {
        int r; fin >> r;
        fout << x[(n+m-1-r)%n]+1 << '\n';
    }
}
