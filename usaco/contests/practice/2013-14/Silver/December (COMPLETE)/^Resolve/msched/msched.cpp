//Got it second try
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;

const int mxN=1e4+1;
int n;
pii c[mxN];

int main() {
    ifstream cin("msched.in");
    ofstream cout("msched.out");
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> c[i].se >> c[i].fi;
    sort(c, c+n, greater<pii>());
    priority_queue<int> pq;
    int ans=0;
    for (int t=mxN-1, i=0; ~t; --t) {
        while (i<n && c[i].fi-1==t)
            pq.push(c[i++].se);
        if (pq.size()) {
            ans+=pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';
}

