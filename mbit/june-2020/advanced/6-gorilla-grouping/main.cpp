#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1, M=1e9+7;
int n, k, fib[mxN];
set<int> s, vis;
vector<int> sz;

int main() {
    fib[0]=fib[1]=1;
    for (int i=2; i<mxN; ++i)
        fib[i]=(fib[i-1]+fib[i-2])%M;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        s.insert(x);
    }
    for (int i:s) {
        if (vis.count(i))
            continue;
        sz.push_back(1);
        vis.insert(i);
        while (s.count(i+k))
            i+=k, ++sz.back(), vis.insert(i);
    }
    long long ans=1;
    for (int i:sz)
        ans=(ans*(long long)fib[i+1])%M;
    cout << ans-1 << '\n';
}

