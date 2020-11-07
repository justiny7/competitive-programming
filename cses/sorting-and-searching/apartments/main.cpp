#include <bits/stdc++.h>
using namespace std;

int n, m, k, open[200001], want[200001];

int main(void) {
    cin >> n >> m >> k;
    for (int i=0; i<n; i++)
        cin >> open[i];
    for (int i=0; i<m; i++)
        cin >> want[i];
    sort(open, open+n);
    sort(want, want+m);
    int a=0, b=0, ans=0;
    while (a<n && b<m) {
        if (k>=abs(open[a]-want[b]))
            a++, b++, ans++;
        else if (open[a]<want[b])
            a++;
        else
            b++;
    }
    cout << ans << '\n';
}

