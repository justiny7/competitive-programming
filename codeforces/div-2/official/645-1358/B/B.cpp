#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int asdf = 0; asdf < t; asdf++) {
        int n;
        cin >> n;
        vector<int> grannies (n);
        for (int i = 0; i < n; i++)
        	cin >> grannies[i];

        sort(grannies.begin(), grannies.end());
        int in = 1, ind = 0;
        while (ind < n) {
        	if (grannies[ind] > in) {
        		int temp = in;
        		while (ind < n && grannies[ind] > temp) {
        			ind++;
        			temp++;
        		}
        		if (ind == n)
        			break;
        		else if (grannies[ind] <= temp)
        			in = temp;
        	}
    		while (ind < n && grannies[ind] <= in) {
    			ind++;
    			in++;
    		}
    	}

        cout << in << '\n';

    }

    return 0;
}
