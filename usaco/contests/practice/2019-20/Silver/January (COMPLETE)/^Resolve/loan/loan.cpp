#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll INF=1e15;
ll n, k, m;

bool works(ll x) {
    ll left=n, cur=k;
    while (cur>0 && left>0) {
        ll y=left/x;
        if (y<=m)
            return (left<=cur*m);
        ll nxt=1+(left-x*y)/y;
        cur-=nxt, left-=nxt*y;
    }
    return (left<=0);
}

int main() {
    ifstream cin("loan.in");
    ofstream cout("loan.out");
    cin >> n >> k >> m;
    ll lo=1, hi=INF;
    while (lo<hi) {
        ll mid=(lo+hi+1)/2;
        if (works(mid))
            lo=mid;
        else
            hi=mid-1;
    }
    cout << lo << '\n';
}

