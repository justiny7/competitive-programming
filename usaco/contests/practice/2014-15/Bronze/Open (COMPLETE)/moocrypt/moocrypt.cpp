#include <bits/stdc++.h>
using namespace std;

ifstream fin("moocrypt.in");
ofstream fout("moocrypt.out");

int n, m, ans, kx1[]={0,1,1,1,0,-1,-1,-1}, ky1[]={1,1,0,-1,-1,-1,0,1},
    ky2[]={2,2,0,-2,-2,-2,0,2}, kx2[]={0,2,2,2,0,-2,-2,-2};
string bo[51];
map<pair<char, char>, int> t;

bool in(int a, int b, int i) {
    return (a+ky2[i]>=0 && a+ky2[i]<n && b+kx2[i]>=0 && b+kx2[i]<m);
}

void check (int a, int b) {
    for (int i=0; i<8; ++i) {
        if (!in(a, b, i))
            continue;
        char o=bo[a][b], p=bo[a+ky1[i]][b+kx1[i]], q=bo[a+ky2[i]][b+kx2[i]];
        //cout << a << " " << b << " + " << i << ": " << o << p << q << '\n';
        if (o==q)
            continue;
        if (p==o)
            t[{q, o}]++;
        else if (p==q)
            t[{o, q}]++;
    }
}

int main(void) {
    fin >> n >> m;
    for (int i=0; i<n; ++i)
        fin >> bo[i];
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            check(i, j);
    for (auto p : t)
        if (p.first.first!='M' && p.first.second!='O')
            ans=max(ans, p.second/2);
    fout << ans << '\n';
}
