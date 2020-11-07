//Yay worked second try after a small bug
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, m, c, t[mxN];

bool works(int x) {
    int cc=0, cb=0, ccnt=0, lst=0;
    while (cc<n && cb<m) {
        if ((cc && t[cc]-t[lst]>x) || ccnt==c)
            ccnt=0, ++cb, lst=cc;
        if (cb==m)
            break;
        ++cc, ++ccnt;
    }
    return (cc==n);
}

int main() {
    ifstream cin("convention.in");
    ofstream cout("convention.out");
    cin >> n >> m >> c;
    for (int i=0; i<n; ++i)
        cin >> t[i];
    sort(t, t+n);
    int lo=0, hi=int(1e9);
    while (lo<hi) {
        int mid=lo+hi>>1;
        if (works(mid))
            hi=mid;
        else
            lo=mid+1;
    }
    cout << lo << '\n';
}

