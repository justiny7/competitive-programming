#include <bits/stdc++.h>
using namespace std;

void srt(int& a, int& b, int& c) {
    vector<int> v{a, b, c};
    sort(v.begin(), v.end());
    a=v[0], b=v[1], c=v[2];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans=7;
        (!a)?--ans:--a;
        (!b)?--ans:--b;
        (!c)?--ans:--c;
        srt(a, b, c);
        (b && c)?--b,--c:--ans;
        (a && c)?--a,--c:--ans;
        (a && b)?--a,--b:--ans;
        if (!a || !b || !c)
            --ans;
        cout << ans << '\n';
    }
}


