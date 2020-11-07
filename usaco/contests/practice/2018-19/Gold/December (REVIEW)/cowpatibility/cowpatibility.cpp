//Had to look at solution (will review again later)
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;

ifstream fin("cowpatibility.in");
ofstream fout("cowpatibility.out");

struct five {
    int i, v[5];
};

bool operator<(const five& a, const five& b) {
    for (int j=0; j<5; ++j) {
        if (a.v[j]<b.v[j])
            return 1;
        if (a.v[j]>b.v[j])
            return 0;
    }
    return 0;
}

five get_subset(five& a, int x) {
    five f={0, {0, 0, 0, 0, 0}};
    for (int j=0; j<5; ++j)
        if (x&(1<<j))
            f.v[f.i++]=a.v[j];
    return f;
}

const int mxN=5e4+1, mult[]={-1,1,-1,1,-1,1};
ll n, ans;
five a[mxN];
map<five, int> mp;

int main() {
    fin >> n;
    for (int t=0; t<n; ++t) {
        a[t].i=5;
        for (int j=0; j<5; ++j)
            fin >> a[t].v[j];
        sort(a[t].v, a[t].v+5);
        for (int j=1; j<32; ++j)
            ++mp[get_subset(a[t], j)];
    }
    ans=n*(n-1)/2;
    for (auto& p:mp)
        ans-=1LL*mult[p.fi.i]*p.se*(p.se-1)/2;
    fout << ans << '\n';
}

