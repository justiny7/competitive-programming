#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int asdf = 0; asdf < t; asdf++) {
		int n;
		bool no = true;
		cin >> n;
		vector<int> arr(n);
		vector<int> mods;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			mods.push_back(i + arr[i]);
		}
		mods.push_back(n + arr[0]);
		sort(mods.begin(), mods.end());
		for (int i = 0; i < mods.size() - 1; i++) {
			if (mods[i] == mods[i + 1]) {
				no = false;
				break;
			}
		}
		if (no)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}