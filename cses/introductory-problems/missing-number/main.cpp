#include <bits/stdc++.h>
using namespace std;

int n, nums[200001];

int main(void) {
    cin >> n;
    for (int i=1; i<=n-1; i++)
        cin >> nums[i];
    sort(nums+1, nums+n);
    for (int i=1; i<=n; i++)
        if (nums[i]!=i) {
            cout << i << '\n';
            return 0;
        }
}
