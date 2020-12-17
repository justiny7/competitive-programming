#include <bits/stdc++.h>
using namespace std;

string f(string &s) {
    int n=s.size();
    string ret;
    for (int i=0; i<n; ++i) {
        int j=i;
        for (; j<n && s[j]==s[i]; ++j);
        ret+=to_string(j-i);
        ret.push_back(s[i]);
        i=j-1;
    }
    return ret;
}

int main() {
    string s="1113122113";
    int t=50; //40; // part 1
    while (t--)
        s=f(s);
    cout << s.size() << '\n';
}

