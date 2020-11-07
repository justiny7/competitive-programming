#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;
using ull=unsigned ll;
using pll=pair<ull, ull>;

int rng() {
    mt19937 r(chrono::high_resolution_clock::now().time_since_epoch().count());
    int b=uniform_int_distribution<int>(501, 1001)(r);
    return ((b&1)?b:b-1);
}

const ll M=1e9+7, B=rng();
int n;
string s;
vector<ull> p1={1}, p2={1}, hsh, hsh2;

void prep() {
    while (p1.size()<=2*n) {
        p1.pb(p1.back()*B%M);
        p2.pb(p2.back()*B);
    }
    hsh.resize(2*n+1), hsh2.resize(2*n+1);
    for (int i=0; i<2*n; ++i) {
        hsh[i+1]=(hsh[i]+s[i%n]*p1[i])%M;
        hsh2[i+1]=hsh2[i]+s[i%n]*p2[i];
    }
}
pll get(int st, int len) {
    int en=st+len;
    ll h1=(hsh[en]-hsh[st]+M)%M;
    ull h2=hsh2[en]-hsh2[st];
    h1=(h1*p1[2*n-en+1])%M;
    h2*=p2[2*n-en+1];
    return {h1, h2};
}
bool cmp(int a, int b) {
    int lo=0, hi=n;
    while (lo<hi) {
        int mid=(lo+hi+1)/2;
        if (get(a, mid)==get(b, mid))
            lo=mid;
        else
            hi=mid-1;
    }
    return s[(a+lo)%n]<s[(b+lo)%n];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s, n=s.size();
    prep();
    int best=0;
    for (int i=1; i<n; ++i)
        if (cmp(i, best))
            best=i;
    for (int i=0; i<n; ++i)
        cout << s[(best+i)%n];
    cout << '\n';
}

