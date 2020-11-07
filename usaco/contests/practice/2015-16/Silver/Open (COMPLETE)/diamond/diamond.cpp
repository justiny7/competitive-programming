//USACO Silver US Open 2016 Problem 2
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
//whoops I was reading the problem completely wrong - thought it was how many pairs of diamonds
//are within k of each other... -_-
//Ok this problem was pretty confusing, had to resort to a peek at the solution :c
ifstream fin("diamond.in");
ofstream fout("diamond.out");

int n, k, m1, m2, r[50001], l[50001], rs[50001], ls[50001], ans;
pair<int, int> max1;
vector<int> d;

int main(void) {
    fin >> n >> k;
    d.resize(n);
    for (int i=0; i<n; ++i)
        fin >> d[i];
    sort(d.begin(), d.end());
    for (int i=0; i<n; ++i) {
        int a=upper_bound(d.begin()+i, d.end(), d[i]+k)-d.begin()-1;
        r[i]=a;
    }
    for (int i=n-1; i>=0; --i) {
        int a=lower_bound(d.begin(), d.begin()+i, d[i]-k)-d.begin();
        l[i]=a;
    }
    for (int i=0; i<n; ++i) {
        ls[i]=i-l[i]+1;
        if (i!=0)
            ls[i]=max(ls[i], ls[i-1]);
    }
    for (int i=n-1; i>=0; --i) {
        rs[i]=r[i]-i+1;
        if (i<n-1)
            rs[i]=max(rs[i], rs[i+1]);
    }
    for (int i=0; i<n-1; ++i)
        ans=max(ans, rs[i+1]+ls[i]);
    fout << ans << '\n';
}
