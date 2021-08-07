#include <bits/stdc++.h>
using namespace std;

int n, x;
long long ans;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> x >> n;

    while (n--) {
        int k; cin >> k;
        pq.push(k);
    }

    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();

        ans += a + b;
        pq.push(a + b);
    }

    cout << ans << '\n';
}

