#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int gcd(int a, int b) {
    return (b?gcd(b, a%b):a);
}

int n, ans;
vector<int> v, difs;

int main() {
    cin >> n;
    int lo=0, hi=1e9, cnt=0;
    while (lo<hi) {
        ++cnt;
        int m=lo+hi>>1;
        cout << "> " << m << endl;
        cin >> ans;
        if (ans)
            lo=m+1;
        else
            hi=m;
    }
    for (int i=1; i<=n; ++i)
        v.push_back(i);
    shuffle(v.begin(), v.end(), rng);
    int cur=-1;
    for (int i=0; cnt<60 && i<n; ++cnt, ++i) {
        cout << "? " << v[i] << endl;
        cin >> ans;
        if (lo^ans)
            cur=(~cur?gcd(cur, lo-ans):lo-ans);
        difs.push_back(ans);
    }
    for (int i=0; i<difs.size(); ++i)
        for (int j=i+1; j<difs.size(); ++j)
            cur=gcd(cur, abs(difs[i]-difs[j]));
    cout << "! " << lo-(n*cur)+cur << " " << cur << endl;
}

