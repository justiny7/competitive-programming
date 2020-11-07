//Yay worked first try
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, ans;
struct cow {
    int t, len, sen;
    bool operator<(const cow& c) const {
        return sen>c.sen;
    }
} a[mxN];
priority_queue<cow> pq;

bool cmp(cow x, cow y) {
    if (x.t^y.t)
        return x.t<y.t;
    return x.sen<y.sen;
}

int main() {
    ifstream cin("convention2.in");
    ofstream cout("convention2.out");
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i].t >> a[i].len, a[i].sen=i;
    sort(a, a+n, cmp);
    int cnt=0, ct=-1, i=0;
    for (int r=0; r<n; ++r) {
        if (!pq.empty()) {
            cow c=pq.top(); pq.pop();
            if (ct<0)
                ct=c.t;
            ans=max(ans, ct-c.t);
            while (i<n && a[i].t<=ct+c.len)
                pq.push(a[i++]);
            ct+=c.len;
            continue;
        }
        int j=i;
        while (i<n && a[i].t==a[j].t)
            pq.push(a[i++]);
        --r, ct=-1;
    }
    cout << ans << '\n';
}

