#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    int s, t;
    cin >> s >> t, --s, --t;

    if (s > t)
        swap(s, t);

    int res = 0;
    for (int i = s; i < t; ++i)
        res += a[i];

    res = min(res, accumulate(a.begin(), a.end(), 0) - res);

    cout << res << '\n';
}

