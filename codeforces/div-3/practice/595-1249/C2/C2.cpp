#include <bits/stdc++.h>
using namespace std;
using ll=long long;

string b3(ll x, string s="") {
    while (x>0) {
        s+=(x%3)+48;
        x/=3;
    }
    reverse(s.begin(), s.end());
    return s;
}

ll dec(string s) {
    ll ans=0, p=1;
    for (int i=s.length()-1; i>=0; --i) {
        ans+=(s[i]-'0')*p;
        p*=3;
    }
    return ans;
}

int main(void) { //convert to base3, find first number >=n w/ no 2's
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s=b3(n), ans="";
        //cout << s << '\n';
        if (s[0]=='2') {
            ans+='1';
            for (int i=0; i<s.length(); ++i)
                ans+='0';
        }
        else {
            int i=0, j;
            bool f=0;
            for (; i<s.length(); ++i)
                if (s[i]=='2') {
                    f=1;
                    break;
                }
            if (f) {
                for (j=s.length()-1; (j>=i || s[j]!='0') && j>=0; --j)
                    ans+='0';
                ans+='1', --j;
                for (; j>=0; --j)
                    ans+=s[j];
                reverse(ans.begin(), ans.end());
                //cout << ans << '\n';
            }
            else
                ans=s;
        }
        cout << dec(ans) << '\n';
    }
}
