//USACO Silver January 2016 Problem 1

#include <bits/stdc++.h>
using namespace std;

ifstream fin("angry.in");
ofstream fout("angry.out");

int n, k, cows[50001];

bool works(int x) {
    int cc=0, cnt=0; //curcow
    while (cc<n && cnt<k) {
        int cur=cows[cc]+2*x;
        while (cc<n && cows[cc]<=cur)
            cc++;
        cnt++;
    }
    return cc==n;
}

int main(void) {
    fin >> n >> k;
    for (int i=0; i<n; i++)
        fin >> cows[i];
    sort(cows, cows+n);
    int lo=1, hi=1e9, best;
    while(lo<=hi) {
        int mid=lo+(hi-lo)/2;
        if (works(mid)) {
            best = mid;
            hi=mid-1;
        }
        else
            lo=mid+1;
    }
    fout << best << '\n';
}
