#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
bool taken[1000001];

int main(void) {
    cin >> n;
    ll targ=n*(n+1)/2;
    if (targ%2==1) {
        cout << "NO\n";
        return 0;
    }
    targ/=2;
    cout << "YES\n";
    if (!(n&1)) {
        cout << n/2 << '\n' << "1";
        for (int i=3; i<=n/2; i+=2)
            cout << " " << i;
        for (int i=n; i>n/2; i-=2)
            cout << " " << i;
        cout << '\n' << n/2 << '\n' << "2";
        for (int i=4; i<=n/2; i+=2)
            cout << " " << i;
        for (int i=n-1; i>n/2; i-=2)
            cout << " " << i;
        cout << '\n';
    }
    else {
        ll cur=0;
        vector<int> nums;
        for (int i=n; cur+i<=targ; i--) {
            nums.push_back(i);
            taken[i]=1;
            cur+=i;
        }
        taken[targ-cur]=1;
        int y=(targ==cur)?nums.size():nums.size()+1;
        cout << y << '\n' << nums[0];
        for (int i=1; i<nums.size(); ++i)
            cout << " " << nums[i];
        if (targ!=cur)
            cout << " " << targ-cur;
        cout << '\n' << n-y << '\n';
        bool f=1;
        for (int i=1; i<n; ++i)
            if (!taken[i]) {
                if (f) {
                    cout << i;
                    f=0;
                }
                else
                    cout << " " << i;
            }
        cout << '\n';
    }
}
