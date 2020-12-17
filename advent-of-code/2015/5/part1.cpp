#include <bits/stdc++.h>
using namespace std;

const string vowels="aeiou";
const string no[]={
    "ab",
    "cd",
    "pq",
    "xy"
};

int main() {
    freopen("test.txt", "r", stdin);
    int ans=0;
    string s;
    while (cin >> s) {
        int n=s.size(), vcnt=0, f=0, db=0;
        for (int i=0; i<n; ++i) {
            for (char c:vowels)
                if (s[i]==c)
                    ++vcnt;
            if (!i)
                continue;
            string sub=s.substr(i-1, 2);
            db|=(sub[0]==sub[1]);
            for (string st:no)
                f|=(sub==st);
        }
        if (!f && db && vcnt>=3)
            ++ans;
    }
    cout << ans << '\n';
}

