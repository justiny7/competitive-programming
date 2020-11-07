//Yay worked first try
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+1;
int n, bit[mxN];
ll ans, cnt[mxN];

void upd(int i) {
    for (++i; i<=n; i+=i&-i)
        ++bit[i];
}

ll query(int i) {
    ll ret=0;
    for (++i; i; i-=i&-i)
        ret+=bit[i];
    return ret;
}

int main() {
    ifstream cin("haircut.in");
    ofstream cout("haircut.out");
    cin >> n;
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        cnt[a]+=i-query(a);
        upd(a);
    }
    for (int i=0; i<n; ++i)
        cout << ans << '\n', ans+=cnt[i];
}

