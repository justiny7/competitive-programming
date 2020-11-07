#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1;
string s, p;
int n, a[mxN];

bool works(int x) {
    vector<bool> gone(n);
    for (int i=0; i<x; ++i)
        gone[a[i]-1]=1;
    string c="";
    for (int i=0; i<n; ++i)
        if (!gone[i])
            c+=s[i];
    for (int i=0, j=0; i<c.size(); ++i) {
        if (c[i]==p[j])
            ++j;
        if (j==p.size())
            return 1;
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> p;
    n=s.size();
    for (int i=0; i<n; ++i)
        cin >> a[i];
    int lo=0, hi=n-1;
    while (lo<hi) {
        int mid=(lo+hi+1)/2;
        if (works(mid))
            lo=mid;
        else
            hi=mid-1;
    }
    cout << lo << '\n';
}


