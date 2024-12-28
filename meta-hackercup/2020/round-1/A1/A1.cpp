#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll M=1e9+7;
const int mxN=1e6+1;
ll n, k, w, l[mxN], h[mxN], al, bl, cl, dl, ah, bh, ch, dh;

ll solve() {
    for (int i=k; i<n; ++i) {
        l[i]=((al*l[i-2]+bl*l[i-1]+cl)%dl)+1;
        h[i]=((ah*h[i-2]+bh*h[i-1]+ch)%dh)+1;
    }
    ll cur=2*(w+h[0]), tot=cur;
    for (int i=1; i<n; ++i) {
        if (l[i-1]+w<l[i])
            cur+=2*(w+h[i]);
        else {
            ll mx=0;
            for (int j=i-1; j>=0 && l[j]+w>=l[i]; mx=max(mx, h[j]), --j);
            if (h[i]>mx)
                cur+=2*(l[i]-l[i-1]+h[i]-mx);
            else
                cur+=2*(l[i]-l[i-1]);
        }
        cur%=M;
        tot=tot*cur%M;
    }
    return tot;
}

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int t; cin >> t;
    for (int tt=1; tt<=t; ++tt) {
        cin >> n >> k >> w;
        for (int i=0; i<k; ++i)
            cin >> l[i];
        cin >> al >> bl >> cl >> dl;
        for (int i=0; i<k; ++i)
            cin >> h[i];
        cin >> ah >> bh >> ch >> dh;
        cout << "Case #" << tt << ": " << solve() << '\n';
    }
}

