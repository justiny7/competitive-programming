#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;

const int mxN=1.5e5;
int n;
pii a[mxN];
set<int> cand;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i].fi >> a[i].se;
    for (int i=2; i*i<=a[0].fi; ++i) {
        int& c=a[0].fi;
        while (c%i==0)
            cand.insert(i), c/=i;
    }
    if (a[0].fi>1)
        cand.insert(a[0].fi);
    for (int i=2; i*i<=a[0].se; ++i) {
        int& c=a[0].se;
        while (c%i==0)
            cand.insert(i), c/=i;
    }
    if (a[0].se>1)
        cand.insert(a[0].se);
    for (int i=1; i<n; ++i) {
        vector<int> e;
        for (int j:cand)
            if (a[i].fi%j!=0 && a[i].se%j!=0)
                e.push_back(j);
        for (int j:e)
            cand.erase(j);
    }
    cout << (cand.empty()?-1:*cand.begin()) << '\n';
}

