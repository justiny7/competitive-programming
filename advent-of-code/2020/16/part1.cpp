#include <bits/stdc++.h>
using namespace std;

bool ok[1001];
int ans=0;

int main() {
    freopen("test.txt", "r", stdin);
    string s;
    {
        while (1) {
            getline(cin, s);
            if (s.empty())
                break;
            stringstream ss(s);
            string nums;
            int a=0, b=0, i=0;
            while (ss >> nums)
                if (nums[0]>='0' && nums[0]<='9')
                    break;
            for (; nums[i]^'-'; ++i)
                a=a*10+(nums[i]-'0');
            for (++i; i<nums.size(); ++i)
                b=b*10+(nums[i]-'0');
            for (int t=a; t<=b; ++t)
                ok[t]=1;
            ss >> nums >> nums;
            for (a=b=i=0; nums[i]^'-'; ++i)
                a=a*10+(nums[i]-'0');
            for (++i; i<nums.size(); ++i)
                b=b*10+(nums[i]-'0');
            for (int t=a; t<=b; ++t)
                ok[t]=1;
        }
    }
    {
        while (1) {
            getline(cin, s);
            if (s.empty())
                break;
        }
    }
    {
        while (1) {
            getline(cin, s);
            if (s.empty())
                break;
            if (s=="nearby tickets:")
                continue;
            int cur=0;
            for (int i=0; i<s.size(); ++i) {
                if (s[i]==',') {
                    if (!ok[cur])
                        ans+=cur;
                    cur=0;
                }
                else
                    cur=cur*10+(s[i]-'0');
            }
            if (!ok[cur])
                ans+=cur;
        }
    }
    cout << ans << '\n';
}

