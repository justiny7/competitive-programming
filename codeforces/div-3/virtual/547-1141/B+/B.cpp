#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    int pref = 0, suff = 0;
    for (; a[pref]; ++pref);
    for (; a[n - 1 - suff]; ++suff);

    for (int i = 1; i < n; ++i)
        if (a[i])
            a[i] += a[i - 1];

    cout << max(pref + suff, *max_element(a.begin(), a.end())) << '\n';
}

