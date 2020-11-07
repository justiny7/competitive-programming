#include <bits/stdc++.h>
using namespace std;

int n, arr[200001];

int main(void) {
    cin >> n;
    long long ans=0;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        if (i>0 && arr[i]<arr[i-1]) {
            ans+=arr[i-1]-arr[i];
            arr[i]=arr[i-1];
        }
    }
    cout << ans << '\n';
}

