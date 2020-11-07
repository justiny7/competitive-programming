#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main(void) {
    cin >> n;
    for (int i=1; pow(5, i)<=n; i++)
        ans+=n/pow(5, i);
    cout << ans << '\n';
}
