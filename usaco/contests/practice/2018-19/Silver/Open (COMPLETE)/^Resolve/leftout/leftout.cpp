//Yay worked first try
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3+1;
int n, acnt, bcnt, ai, bi;
bool mat[mxN][mxN], a[mxN], b[mxN];

bool eq(bool x[], bool y[]) {
    bool f=(x[0]^y[0]);
    for (int i=0; i<n; ++i)
        if ((x[i]^y[i])^f)
            return 0;
    return 1;
}

int main() {
    ifstream cin("leftout.in");
    ofstream cout("leftout.out");
    cin >> n;
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j) {
            char c; cin >> c;
            mat[i][j]=(c=='R');
        }
    for (int i=0; i<n; ++i)
        a[i]=mat[0][i];
    int j=1;
    do {
        for (int i=0; i<n; ++i)
            b[i]=mat[j][i];
        ++j;
    } while (j<n && eq(a, b));
    if (eq(a, b))
        return cout << "-1\n", 0;
    for (int i=n-1; ~i; --i) {
        if (eq(a, mat[i]))
            ++acnt, ai=i;
        else if (eq(b, mat[i]))
            ++bcnt, bi=i;
        else
            return cout << "-1\n", 0;
    }
    bool ok=0;
    int lst=mxN;
    for (int t=0; t<2; ++t) {
        int cnt=0, cur=-1;
        for (int i=0; i<n; ++i) {
            if (a[i]^b[i])
                ++cnt, cur=i;
            b[i]^=1;
        }
        if (cnt==1)
            ok=1, lst=min(lst, cur);
    }
    if (!ok)
        return cout << "-1\n", 0;
    ++lst, ++ai, ++bi;
    if (acnt>1 && bcnt>1)
        cout << min(ai, bi) << " " << lst << '\n';
    else if (acnt==1)
        cout << ai << " " << lst << '\n';
    else
        cout << bi << " " << lst << '\n';
}

