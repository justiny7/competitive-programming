#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string t, ans;
		cin>>t;

		int count0 = 0, count1 = 0;
		for (int j = 0; j < t.length(); j++) {
			if (t[j] == '0') count0++;
			else count1++;
		}
		if (count0 == t.length() || count1 == t.length())
			ans = t;
		else {
			for (int i = 0; i < t.length(); i++) {
				ans.append("10");
			}
		}
		cout << ans << endl;
	}
}