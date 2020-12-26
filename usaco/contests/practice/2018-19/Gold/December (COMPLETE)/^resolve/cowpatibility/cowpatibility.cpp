//Yay worked after a few tries due to overflow problems
#include <bits/stdc++.h>
#define ar5 array<int, 5>
using namespace std;
using ll=long long;
using pal=pair<ar5, ll>;

const int M[]={-1,1,-1,1,-1,1,-1};
ll n, cnt;
map<pal, ll> mp;

int main() {
    ifstream cin("cowpatibility.in");
    ofstream cout("cowpatibility.out");
    cin >> n;
    for (int i=0; i<n; ++i) {
        ar5 a;
        for (int j=0; j<5; ++j)
            cin >> a[j];
        sort(a.begin(), a.end());
        for (int j=1; j<(1<<5); ++j) {
            ar5 cur={0,0,0,0,0};
            int c=0;
            for (int k=0; k<5; ++k)
                if (j&(1<<k))
                    cur[c++]=a[k];
            ++mp[pal(cur, c)];
        }
    }
    for (auto &p:mp)
        cnt+=M[p.first.second]*(p.second-1)*p.second/2;
    cout << n*(n-1)/2-cnt << '\n';
}

