//Yay worked first try
#include <bits/stdc++.h>
using namespace std;

string s;
int n, ans, f, b;

int main() {
    ifstream cin("clumsy.in");
    ofstream cout("clumsy.out");
    cin >> s, n=s.size();
    for (int i=0; i<n; ++i) {
        if (s[i]=='(')
            ++f;
        else
            ++b;
        if (b>f)
            ++ans, ++f, --b;
    }
    if (f>b)
        ans+=(f-b)/2;
    cout << ans << '\n';
}

