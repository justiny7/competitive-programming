#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        string ans;
        cin >> a >> b >> c;
        if (a>0)
            for (int i=0; i<a+1; ++i)
                ans+='0';
        if (c>0)
            for (int i=0; i<c+1; ++i)
                ans+='1';
        if (b>0 && ans!="") {
            if (a>0 && c>0)
                b--;
            for (int i=0; i<b; ++i) {
                if (ans[ans.length()-1]=='1')
                    ans+='0';
                else
                    ans+='1';
            }
        }
        else if (a==c && a==0 && b>0) {
            ans+='1';
            for (int i=0; i<b; ++i)
                ans+=(i&1)?'1':'0';
        }
        cout << ans << '\n';
    }
}
