/*
 * Had the greedy idea right (if you can reach another station with less cost, the buy the
 * minimum amount of gas to get there - otherwise, fill the tank to full capacity) but I
 * didn't use the correct stack implementation at first so I peeked at answer for the idea,
 * and then stole my CSES stack impl for next smallest number
*/

#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

ifstream fin("fuel.in");
ofstream fout("fuel.out");

const int mxN=5e4+1;
ll n, g, b, d, nxt[mxN];
pll s[mxN];

int main(void) {
    fin >> n >> g >> b >> d;
    for (int i=0; i<n; ++i)
        fin >> s[i].fi >> s[i].se;
    sort(s, s+n);
    stack<pll> st;
    for (int i=n-1; i>=0; --i) {
        while (!st.empty() && s[i].se<=st.top().fi)
            st.pop();
        nxt[i]=(st.empty()?-1:st.top().se);
        st.push({s[i].se, i});
    }
    ll cur=b-s[0].fi, ans=0;
    for (int i=0; i<n; ++i) {
        if (cur<0) {
            fout << "-1\n";
            return 0;
        }
        ll need=min(g, ((nxt[i]<0)?d:s[nxt[i]].fi)-s[i].fi);
        ans+=max(0LL, (need-cur)*s[i].se), cur=max(cur, need)-((i<n-1)?s[i+1].fi:d)+s[i].fi;
    }
    fout << ((cur<0)?-1:ans) << '\n';
}
