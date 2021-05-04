#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 69;
int n, ans[N];

int query(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int ret; cin >> ret;
    return ret;
}

int main() {
    cin >> n;
    int cur = 1;
    for (int i = 2; i <= n; ++i) {
        int a = query(i, cur),
            b = query(cur, i);
        if (a < b) { //i > cur
            ans[cur] = b;
            cur = i;
        }
        else
            ans[i] = a;
    }
    ans[cur] = n;
    cout << "!";
    for (int i = 1; i <= n; ++i)
        cout << " " << ans[i];
    cout << endl;
}
