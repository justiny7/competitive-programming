//USACO Silver January 2017 Problem 1
#include <bits/stdc++.h>
using namespace std;
//ay worked first try
ifstream fin("cowdance.in");
ofstream fout("cowdance.out");

int n, tmax, t[10001];

bool works(int x) {
    int cc=0, ct=0, cn, mt=-1; //curcow, curtime, cur num of cows, max time
    map<int, int> avail;
    while (cn<x) {
        avail[ct+t[cc]]--;
        mt=max(ct+t[cc], mt);
        cn++, cc++;
        if (cc==n)
            break;
    }
    for (auto p : avail) {
        cn+=p.second;
        while (cn<x && cc<n) {
            avail[p.first+t[cc++]]--;
            cn++;
        }
        mt=max(mt, p.first);
    }
    return mt<=tmax;
}

int main(void) {
    fin >> n >> tmax;
    for (int i=0; i<n; ++i)
        fin >> t[i];
    int lo=1, hi=n, best;
    while (lo<=hi) {
        int mid=lo+(hi-lo)/2;
        if (works(mid)) {
            best=mid;
            hi=mid-1;
        }
        else
            lo=mid+1;
    }
    fout << best << '\n';
}
