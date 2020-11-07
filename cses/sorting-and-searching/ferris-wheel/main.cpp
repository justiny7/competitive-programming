#include <bits/stdc++.h>
using namespace std;

int n, x, w[200001], ans=0;

int main(void) {
    cin >> n >> x;
    for (int i=0; i<n; i++)
        cin >> w[i];
    sort(w, w+n);
    int a=0, b=n-1;
    while (a<b) {
        if (w[a]+w[b]>x)
            b--, ans++;
        else if (w[a]+w[b]<=x)
            b--, a++, ans++;
    }
    if (a==b)
        ans++;
    cout << ans << '\n';
}

