#include <bits/stdc++.h>
using namespace std;

ifstream fin("reorder.in");
ofstream fout("reorder.out");

const int mxN=101;
int n, a[mxN], b[mxN], to[mxN], grp[mxN], cnt, sz, maxsz;

void go(int cur) {
    if (grp[cur])
        return;
    grp[cur]=cnt, ++sz, maxsz=max(sz, maxsz);
    go(to[a[cur]]);
    a[cur]=b[cur];
}

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i)
        fin >> a[i];
    for (int i=0; i<n; ++i) {
        fin >> b[i];
        to[b[i]]=i;
    }
    for (int i=0; i<n; ++i)
        if (a[i]!=b[i]) {
            sz=0, ++cnt;
            go(i);
        }
    if (cnt)
        fout << cnt << " " << maxsz;
    else
        fout << "0 -1";
    fout << '\n';
}
