#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

bool ckmax(ll& a, const ll& b) {
    return (a<b?a=b,1:0);
}

const int mxN=5e5+1;
ll n, a[mxN], l[mxN], r[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    stack<pll> st;
    for (int i=0; i<n; ++i) {
        while (!st.empty() && a[i]<=st.top().fi)
            st.pop();
        l[i]=(st.empty()?(i+1)*a[i]:l[st.top().se]+(i-st.top().se)*a[i]);
        st.push({a[i], i});
    }
    while (!st.empty())
        st.pop();
    reverse(a, a+n);
    for (int i=0; i<n; ++i) {
        while (!st.empty() && a[i]<=st.top().fi)
            st.pop();
        r[n-i-1]=(st.empty()?(i+1)*a[i]:r[n-st.top().se-1]+(i-st.top().se)*a[i]);
        st.push({a[i], i});
    }
    reverse(a, a+n);
    ll cur=0, ind;
    for (int i=0; i<n; ++i)
        if (ckmax(cur, l[i]+r[i]-a[i]))
            ind=i;
    vector<ll> ans(n);
    ans[ind]=a[ind];
    for (int i=ind-1; ~i; --i)
        ans[i]=min(ans[i+1], a[i]);
    for (int i=ind+1; i<n; ++i)
        ans[i]=min(ans[i-1], a[i]);
    for (int i=0; i<n; ++i)
        cout << ans[i] << (i<n-1?" ":"\n");
}

