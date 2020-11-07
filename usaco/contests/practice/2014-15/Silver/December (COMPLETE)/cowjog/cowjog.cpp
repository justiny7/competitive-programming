#include <bits/stdc++.h>
using namespace std;
using ll=long long;
//Hm...pretty easy problem
ifstream fin("cowjog.in");
ofstream fout("cowjog.out");

ll n, t, ans=1;
vector<ll> vec;

int main(void) {
    fin >> n >> t;
    for (int i=0; i<n; ++i) {
        ll p, s;
        fin >> p >> s;
        vec.push_back(p+s*t);
    }
    ll cur=vec[n-1];
    for (int i=n-2; i>=0; --i)
        if (vec[i]<cur)
            cur=vec[i], ++ans;
    fout << ans << '\n';
}
