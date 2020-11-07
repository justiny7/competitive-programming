#include <bits/stdc++.h>
using namespace std;
using ll=long long;
//Yay worked first try although I had to get a little hint on to find starting position
ifstream fin("cbarn.in");
ofstream fout("cbarn.out");

const int mxN=1e5+1;
ll n, a[mxN], ans;

inline ll get_dist(ll a, ll b) {
    if (a>=b)
        return (a-b)*(a-b);
    else
        return (a+n-b)*(a+n-b);
}

int main(void) {
    fin >> n;
    ll cur=0, pos;
    for (int i=0; i<n; ++i)
        fin >> a[i], cur=max(cur+a[i]-1, 0LL);
    for (int i=0; i<n; ++i) {
        if (!cur) {
            pos=i;
            break;
        }
        cur=max(cur+a[i]-1, 0LL);
    }
    queue<ll> cows;
    for (int cnt=0, i=pos; cnt<n; i=(i+1)%n, ++cnt) {
        for (int t=0; t<a[i]; ++t)
            cows.push(i);
        ll nxt=cows.front(); cows.pop();
        ans+=get_dist(i, nxt);
    }
    fout << ans << '\n';
}
