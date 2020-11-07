#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=unsigned long long;
using pll=pair<ll, ll>;

int rng() {
    auto s=chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 r(s);
    int b=uniform_int_distribution<int>(501, 1001)(r);
    return ((b&1)?b:b-1);
}

const int mxN=1e6+1;
const ll M=1e9+7, B=rng();
int n, mx, mx2, pos, pos2;
string s1, s2;

struct HASH {
    string s;
    vector<ll> p1={1}, p2={1}, hsh, hsh2;
    HASH(string x):s(x) {
        while (p1.size()<=n) {
            p1.pb(p1.back()*B%M);
            p2.pb(p2.back()*B);
        }
        hsh.resize(n+1), hsh2.resize(n+1);
        for (int i=0; i<n; ++i) {
            hsh[i+1]=(hsh[i]+s[i]*p1[i])%M;
            hsh2[i+1]=hsh2[i]+s[i]*p2[i];
        }
    }
    pll get(int st, int len) {
        int en=st+len;
        ll h1=(hsh[en]-hsh[st]+M)%M,
           h2=hsh2[en]-hsh2[st];
        h1=(h1*p1[n-en+1])%M;
        h2*=p2[n-en+1];
        return {h1, h2};
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s1; n=s1.size(), s2=s1;
    reverse(s2.begin(), s2.end());
    HASH forward(s1), backward(s2);
    for (int i=0; i<n; ++i) {
        bool f=0;
        while (i-mx+1>=0 && i+mx-1<n && forward.get(i, mx)==backward.get(n-i-1, mx))
            ++mx, f=1;
        if (f)
            pos=i;
    }
    for (int i=0; i<n; ++i) {
        bool f=0;
        while (i-mx2+1>=0 && i+mx2<n && forward.get(i+1, mx2)==backward.get(n-i-1, mx2))
            ++mx2, f=1;
        if (f)
            pos2=i;
    }
    --mx, --mx2;
    if (mx>mx2)
        cout << s1.substr(pos-mx+1, mx*2-1) << '\n';
    else
        cout << s1.substr(pos2-mx2+1, mx2*2) << '\n';
}
