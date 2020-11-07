#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        string s;
        cin >> n >> k >> s;
        sort(s.begin(), s.end());
        if (s[0]<s[k-1]) {
            cout << s[k-1] << '\n';
            continue; 
        }
        cout << s[0];
        if (s[k]!=s[n-1])
            for (int i=k; i<n; ++i)
                cout << s[i];
        else
            for (int i=0; i<(n-1)/k; ++i)
                cout << s[n-1];
        cout << '\n';
    }
}
