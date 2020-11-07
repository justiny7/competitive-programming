#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5+1;
const ll M=1e9+7;
ll n, ans, tot, p[mxN], acnt[mxN], ccnt[mxN], qcnt[mxN];
string s;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s;
    p[0]=1;
    for (int i=0; i<n; ++i) {
        if (s[i]=='a')
            ++acnt[i+1];
        else if (s[i]=='c')
            ++ccnt[i+1];
        else if (s[i]=='?')
            ++qcnt[i+1], ++tot;
        acnt[i+1]+=acnt[i];
        ccnt[i+1]+=ccnt[i];
        qcnt[i+1]+=qcnt[i];
        p[i+1]=p[i]*3%M;
    }
    for (int i=2; i<n; ++i) {
        if (s[i-1]=='?') {
            ans=(ans+(acnt[i-1]*(ccnt[n]-ccnt[i])*p[max(0LL, tot-1)])%M)%M; //a?c
            ans=(ans+(acnt[i-1]*(qcnt[n]-qcnt[i])*p[max(0LL, tot-2)])%M)%M; //a??
            ans=(ans+(qcnt[i-1]*(ccnt[n]-ccnt[i])*p[max(0LL, tot-2)])%M)%M; //??c
            ans=(ans+(qcnt[i-1]*(qcnt[n]-qcnt[i])*p[max(0LL, tot-3)])%M)%M; //???
        }
        else if (s[i-1]=='b') {
            ans=(ans+(acnt[i-1]*(ccnt[n]-ccnt[i])*p[max(0LL, tot)])%M)%M; //abc
            ans=(ans+(acnt[i-1]*(qcnt[n]-qcnt[i])*p[max(0LL, tot-1)])%M)%M; //ab?
            ans=(ans+(qcnt[i-1]*(ccnt[n]-ccnt[i])*p[max(0LL, tot-1)])%M)%M; //?bc
            ans=(ans+(qcnt[i-1]*(qcnt[n]-qcnt[i])*p[max(0LL, tot-2)])%M)%M; //?b?
        }
    }
    cout << ans << '\n';
}

