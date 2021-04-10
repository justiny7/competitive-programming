#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    long long a, b, c;
    cin >> a >> b >> c;
    if (c == 1)
        cout << a * b << '\n';
    else
        cout << (((a - 1) / c) + 1) * (((b - 1) / c) + 1) << '\n';
}
