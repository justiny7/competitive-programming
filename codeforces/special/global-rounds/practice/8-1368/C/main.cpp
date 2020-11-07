#include <bits/stdc++.h>
using namespace std;

int n;

void make(int x) {
    cout << x-1 << " " << x << '\n';
    cout << x << " " << x-1 << '\n';
    cout << x << " " << x << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    cout << 3*(n+1)+1 << '\n';
    cout << "1 1\n";
    for (int i=2; i<=n+2; ++i)
        make(i);
}
