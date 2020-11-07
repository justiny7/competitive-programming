#include <bits/stdc++.h>
using namespace std;

int n;
set<int> s;

int main(void) {
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }
    cout << s.size() << '\n';
}

