#include <bits/stdc++.h>
#define lb lower_bound
#define ub upper_bound
using namespace std;
using ll=long long;
//I was close but still had to look at the solution in the end - I didn't binsearch for starting pos before
ifstream fin("angry.in");
ofstream fout("angry.out");

const int mxN=5e4+1;
ll n, x[mxN];

bool pos_front(ll st, ll rad) {
    if (x[0]<st-rad) {
        ll c=x[lb(x, x+n, st-rad)-x];
        rad-=2;
        while (c!=x[0]) {
            int nxt=lb(x, x+n, c-rad)-x;
            if (x[nxt]>=c)
                return 0;
            c=x[nxt], rad-=2;
        }
    }
    return 1;
}

bool pos_back(ll st, ll rad) {
    if (x[n-1]>st+rad) {
        ll c=ub(x, x+n, st+rad)-x-1;
        if (x>=0)
            c=x[c];
        else
            return 0;
        rad-=2;
        while (c!=x[n-1]) {
            int nxt=ub(x, x+n, c+rad)-x-1;
            if (x<0 || x[nxt]<=c)
                return 0;
            c=x[nxt], rad-=2;
        }
    }
    return 1;
}

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i)
        fin >> x[i], x[i]*=2;
    sort(x, x+n);
    ll lo=0, hi=2e9;
    while (lo<hi) {
        ll mid=(lo+hi)/2, l=x[0], r=x[n-1];
        while (l<r) { //binary search rightmost position
            ll m=(l+r+1)/2;
            if (pos_front(m, mid))
                l=m;
            else
                r=m-1;
        }
        if (pos_back(l, mid)) //check if it reaches the end
            hi=mid;
        else
            lo=mid+1;
    }
    fout << lo/2;
    if (lo&1)
        fout << ".5\n";
    else
        fout << ".0\n";
}
