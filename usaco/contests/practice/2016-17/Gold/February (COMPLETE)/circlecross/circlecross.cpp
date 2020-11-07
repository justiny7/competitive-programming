#include <bits/stdc++.h>
using namespace std;
//Pretty simple bit problem except I got it on the second try because I forgot to change the bit size to mxN*2 T-T
ifstream fin("circlecross.in");
ofstream fout("circlecross.out");

const int mxN=5e4+1;
int n, a[mxN*2], ans, beg[mxN], bit[mxN*2];

void upd(int i, int x) {
    for (; i<=n*2; i+=i&(-i))
        bit[i]+=x;
}

void add(int i) {
    upd(i, 1);
}

void del(int i) {
    upd(i, -1);
}

int query(int i) {
    int ans=0;
    for (; i>0; i-=i&(-i))
        ans+=bit[i];
    return ans;
}

int query(int l, int r) {
    return query(r)-query(l-1);
}

int main() {
    fin >> n;
    for (int i=1; i<=n*2; ++i) {
        int a; fin >> a;
        if (!beg[a]) {
            beg[a]=i;
            add(i);
            continue;
        }
        ans+=query(beg[a], i)-1;
        del(beg[a]);
    }
    fout << ans << '\n';
}
