#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;
using ull=unsigned long long;
using upll=pair<ull, ull>;

int rng() {
    mt19937 r(chrono::high_resolution_clock::now().time_since_epoch().count());
    int b=uniform_int_distribution<int>(501, 1001)(r);
    return (b&1)?b:b-1;
}

const int mxN=5e3+1;
const ll M=1e9+7, B=rng();
string s;
int n, cnt[mxN];
bool ispal[mxN][mxN];
vector<ull> p1={1}, p2={1}, hsh, hsh2;
map<upll, int> mp;

void setup() {
    while (p1.size()<=n) {
        p1.pb(p1.back()*B%M);
        p2.pb(p2.back()*B);
    }
    hsh.resize(n+1), hsh2.resize(n+1);
    for (int i=0; i<n; ++i) {
        hsh[i+1]=(hsh[i]+s[i]*p1[i])%M;
        hsh2[i+1]=(hsh2[i]+s[i]*p2[i]);
    }
}

upll get(int st, int len) {
    int en=st+len;
    ll h1=(hsh[en]+M-hsh[st])%M;
    ull h2=hsh2[en]-hsh2[st];
    h1=(h1*p1[n-en+1])%M;
    h2*=p2[n-en+1];
    return upll(h1, h2);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s, n=s.size();
    setup();
    for (int i=0; i<n; ++i) {
        for (int j=0; i+j<n && i-j>=0; ++j) {
            if (s[i+j]==s[i-j])
                ispal[i-j][i+j]=1;
            else
                break;
        }
        for (int j=0; i+j+1<n && i-j>=0; ++j) {
            if (s[i+j+1]==s[i-j])
                ispal[i-j][i+j+1]=1;
            else
                break;
        }
    }
    for (int l=1; l<=n; ++l)
        for (int i=0; i+l-1<n; ++i)
            if (ispal[i][i+l-1]) {
                upll a=get(i, l/2), b=get(i, l);
                if (l>1 && a==get(i+(l+1)/2, l/2))
                    mp[b]=mp[a]+1, ++cnt[mp[b]];
                else
                    mp[b]=1, ++cnt[1];
            }
    for (int i=n-2; i>0; --i)
        cnt[i]+=cnt[i+1];
    for (int i=1; i<=n; ++i)
        cout << cnt[i] << ((i^n)?" ":"\n");
}

