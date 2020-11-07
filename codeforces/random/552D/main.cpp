#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pii=pair<int, int>;

const int mxN=2e3+1;
int n;
pii p[mxN];

int gcd(int a, int b) {
    return (b?gcd(b, a%b):a);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> p[i].x >> p[i].y;
    int cur=0;
    for (int i=0; i<n; ++i) {
        map<pair<int, int>, int> cnt;
        for (int j=i+1; j<n; ++j) {
            int dy=p[i].y-p[j].y,
                dx=p[i].x-p[j].x;
            int neg=((dy<0)^(dx<0))?-1:1;
            dy=abs(dy), dx=abs(dx);
            int GCD=gcd(dy, dx),
                num=dy*neg/GCD,
                den=dx/GCD;
            if (!num)
                den=abs(den);
            if (!den)
                num=abs(num);
            ++cnt[pii(num, den)];
        }
        for (auto p:cnt)
            cur+=1LL*p.y*(p.y-1)/2;
    }
    cout << 1LL*n*(n-1)*(n-2)/6-cur << '\n';
}

