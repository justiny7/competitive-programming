#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;
int ans = INT_MAX, p[N * 3];
string s[3];

string kmp(string a, string b) {
    string t = b + '#' + a;
    for (int i = 2; i <= t.size(); ++i) {
        p[i] = p[i - 1];
        while (p[i] && t[i - 1] != t[p[i]])
            p[i] = p[p[i]];

        if (t[i - 1] == t[p[i]])
            ++p[i];
        if (p[i] == b.size())
            return a;
    }

    for (int i = p[t.size()]; i < b.size(); ++i)
        a += b[i];

    return a;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 0; i < 3; ++i)
        cin >> s[i];

    int perm[] = {0, 1, 2};
    do {
        string cur = s[perm[0]];
        for (int i = 1; i < 3; ++i)
            cur = kmp(cur, s[perm[i]]);

        ans = min(ans, (int)cur.size());
    } while (next_permutation(perm, perm + 3));

    cout << ans << '\n';
}
