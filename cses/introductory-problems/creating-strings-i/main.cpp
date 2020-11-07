#include <bits/stdc++.h>
using namespace std;

string s;
map<char, int> c;

int fact(int x) {
    int ans=1;
    for (int i=2; i<=x; ++i)
        ans*=i;
    return ans;
}

int main(void) {
    cin >> s;
    sort(s.begin(), s.end());
    for (int i=0; i<s.length(); ++i)
        c[s[i]]++;
    int n=fact(s.length());
    for (auto p : c)
        n/=fact(p.second);
    cout << n << '\n';
    do {
        cout << s << '\n';
    } while (next_permutation(s.begin(), s.end()));
}
