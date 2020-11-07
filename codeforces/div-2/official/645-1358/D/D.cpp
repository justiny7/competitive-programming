#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, x, x1;
    cin >> n >> x;
    x1 = x;
    vector<ll> days (n);

    ll largmo, largmo2, largmo1, daysinmo = -1;

    for (ll i = 0; i < n; i++) {
    	cin >> days[i];
    	if (days[i] > daysinmo) {
    		daysinmo = days[i];
    		largmo = i;
    	}
    }

    largmo1 = largmo;


	ll sum = 0, p = daysinmo-x, totsum = -1;
	if (x <= daysinmo) {
		totsum = (daysinmo*(daysinmo+1))/2 - (p*(p+1))/2;
	}
	else {
		ll count = 0;
		while (count < n) {
			while (x > days[largmo]) {
				sum += (days[largmo]*(days[largmo]+1))/2;
				x -= days[largmo];
				largmo--;
				if (largmo < 0)
					largmo = n-1;
			}
			p = days[largmo] - x;
			sum += (days[largmo]*(days[largmo]+1))/2 - (p*(p+1))/2;
			//cout << sum << '\n';

			totsum = max(totsum, sum);
			sum = 0;
			count++;
			x = x1;
			largmo = (largmo1+count)%n;
		}
	}

	cout << totsum << '\n';

    return 0;
}
