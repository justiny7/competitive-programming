//USACO Silver February 2017 Problem 2
#include <bits/stdc++.h>
using namespace std;
//Nice! Worked first try
//Interesting prefix sum+binsearch problem
ifstream fin("maxcross.in");
ofstream fout("maxcross.out");

int n, k, b, sum[100002], br[100001];

bool works(int x) {
    if (x>=b)
        return 1;
    for (int i=x+1; i<=b+1; ++i)
        if (sum[i]-sum[i-x-1]+x>=k)
            return 1;
    return 0;
}

int main(void) {
    int last;
    fin >> n >> k >> b;
    for (int i=1; i<=b; ++i)
        fin >> br[i];
    sort(br+1, br+b+1);
    for (int i=1; i<=b; ++i)
        sum[i]=br[i]-br[i-1]-1+sum[i-1];
    sum[b+1]=sum[b]+n-br[b];
    int lo=0, hi=100000, best;
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
