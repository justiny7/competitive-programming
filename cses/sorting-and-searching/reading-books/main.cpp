#include <bits/stdc++.h>
using namespace std;
using ll=long long;
//Hm...this problem is so much simpler than I had expected
int n;
ll tot, big;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i) { //Idea is to have one person start reading from the longest book, and the other from the second longest book
        ll a; cin >> a;
        tot+=a, big=max(big, a);
    }
    cout << max(tot, big*2) << '\n';
}

