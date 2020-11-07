//Yay got it second try after a small optimization
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using pii=pair<int, int>;

const int mxN=20, mxK=51;
int n, k, breed[mxN];
vector<int> same[mxN], dif[mxN];

int solve(int cow=2) {
    if (cow==n+1)
        return 1;
    int cur=0;
    for (int t=1; t<=3; ++t) {
        breed[cow]=t;
        bool ok=1;
        for (int c:same[cow])
            if (c<cow)
                ok&=(breed[c]==t);
        for (int c:dif[cow])
            if (c<cow)
                ok&=(breed[c]!=t);
        if (ok)
            cur+=solve(cow+1);
    }
    breed[cow]=0;
    return cur;
}

int main() {
    ifstream cin("assign.in");
    ofstream cout("assign.out");
    cin >> n >> k;
    for (int i=0; i<k; ++i) {
        char c; int a, b;
        cin >> c >> a >> b;
        (c=='S'?same:dif)[a].pb(b);
        (c=='S'?same:dif)[b].pb(a);
    }
    breed[1]=1;
    cout << 3*solve() << '\n';
}

