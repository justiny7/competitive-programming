#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x, cnt=0;
        cin >> n >> x;
        for (int i=1; i<n; ++i) {
            int a, b;
            cin >> a >> b;
            if (a==x || b==x)
                cnt++;
        }
        if ((n&1)==0 || cnt==1 || n==1)
            cout << "Ayush\n";
        else
            cout << "Ashish\n";
    }
}
