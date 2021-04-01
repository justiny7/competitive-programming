#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int x; cin >> x;
    cout << (x % 9 == 0 ? 9 : x % 9) << '\n';
}
