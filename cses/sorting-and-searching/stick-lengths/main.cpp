#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, s[200001], med, ans;

int main(void) {
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> s[i];
    sort(s, s+n);
    if (n&1)
        med=s[n/2];
    else
        med=(s[n/2]+s[n/2-1])/2;
    for (int i=0; i<n; i++)
        ans+=abs(s[i]-med);
    cout << ans << '\n';
}

