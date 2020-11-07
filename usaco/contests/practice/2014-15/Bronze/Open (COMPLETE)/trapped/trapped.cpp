//USACO Bronze US Open 2015 Problem 3
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;
//Yay worked first try
ifstream fin("trapped.in");
ofstream fout("trapped.out");

int n, ans;
pii bales[4001];

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i)
        fin >> bales[i].se >> bales[i].fi;
    sort(bales, bales+n);
    for (int i=1; i<n; ++i) {
        int d=bales[i].fi-bales[i-1].fi, l=i-1, r=i;
        while (d>bales[l].se || d>bales[r].se) {
            if (d>bales[r].se)
                ++r;
            if (d>bales[l].se)
                --l;
            if (r==n || l<0)
                break;
            d=bales[r].fi-bales[l].fi;
        }
        if (r<n && l>=0)
            ans+=bales[i].fi-bales[i-1].fi;
    }
    fout << ans << '\n';
}
