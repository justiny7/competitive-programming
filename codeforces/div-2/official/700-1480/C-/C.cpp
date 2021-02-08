#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+5;
int n, a[mxN];
int query(int k) {
    cout << "? " << k << endl;
    int ret;
    cin >> ret;
    return ret;
}
void guess(int k) {
    cout << "! " << k << endl;
}
array<int, 3> go(int k) {
    array<int, 3> ret;
    if (k>1) {
        if (a[k-1]<0)
            a[k-1]=query(k-1);
    }
    if (k<n) {
        if (a[k+1]<0)
            a[k+1]=query(k+1);
    }
    if (a[k]<0)
        a[k]=query(k);
    return {a[k-1], a[k], a[k+1]};
}

int main() {
    memset(a, -1, sizeof(a));
    cin >> n;
    int lo=1, hi=n;
    {
        int a=query(1),
            b=query(2);
        if (b>a) {
            guess(1);
            return 0;
        }
        a=query(n);
        b=query(n-1);
        if (b>a) {
            guess(n);
            return 0;
        }
    }
    while (lo<=hi) {
        int m=lo+hi>>1;
        array<int, 3> here=go(m);
        if (here[0]>here[1] && here[1]<here[2]) {
            guess(m);
            return 0;
        }
        else if (here[0]>here[1] && here[1]>here[2])
            lo=m;
        else
            hi=m;
    }
}

