#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) {
    cin >> n;
    if (n==2 || n==3) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    if (n==1) {
        cout << "1\n";
        return 0;
    }
    for (int i=2; i<=n; i+=2) {
        if (i==2)
            cout << i;
        else
            cout << " " << i;
    }
    for (int i=1; i<=n; i+=2)
        cout << " " << i;
    cout << '\n';
}

