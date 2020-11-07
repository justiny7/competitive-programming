#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int asdf = 0; asdf < t; asdf++) {
        int n, k;
        cin >> n >> k;
        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            a.push_back(temp);
        }
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            b.push_back(temp);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());

        int cnt = 0;
        while (cnt < k && a[cnt] < b[cnt]) {
            a[cnt] = b[cnt];
            //cout << "a[cnt: " << a[cnt] << endl;
            cnt++;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            //cout << a[i] << " ";
            ans += a[i];
        }
        cout << ans << endl;
    }

    return 0;
}