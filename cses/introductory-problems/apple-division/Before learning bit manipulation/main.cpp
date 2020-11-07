#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[20], ans=1e18, cur, sum;
vector<string> str;

void gen(string s, int c) {
    if (c==n) {
        str.push_back(s);
        return;
    }
    gen(s+'0', c+1);
    gen(s+'1', c+1);
}

int main(void) {
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        sum+=a[i];
    }
    gen("", 0);
    for (string s : str) {
        //cout << s << '\n';
        for (int i=0; i<n; i++)
            if (s[i]=='1')
                cur+=a[i];
        ans=min(ans, abs(2*cur-sum));
        cur=0;
    }
    cout << ans << '\n';
}
