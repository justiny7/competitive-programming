#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll k;
ll t[10];
string s="codeforces";

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> k;
    fill(t, t+10, 1);
    ll a=1;
    for (int i=0; a<k; ++i)
        for (int j=0; j<10; ++j) {
            a*=t[j]+1;
            a/=t[j]++;
            if (a>=k)
                break;
        }
    for (int i=0; i<10; ++i)
        for (int j=0; j<t[i]; ++j)
            cout << s[i];
    cout << '\n';
}
