#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isBeautiful(vector<int> a, int len) {
	int sum = 0;
	int nexSum = 0;
	if (len == a.size())
		return false;
	for (int i = 0; i <= a.size() - len; i++) {
		for (int j = i; j < i+len; j++)
			sum += a[j];
		if (i == 0)
			nexSum = sum;
		else {
			if (sum != nexSum)
				return false;
		}
		//cout << "Sum " << sum <<endl;
		sum = 0;
		//cout << "nexSum " << nexSum << endl;
	}
	return true;
}

int main(void) {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n, k;
		cin >> n >> k;
		vector<int> array;
		vector<int> numbers;
		vector<int> answer;

		int repeats = 1;

		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			array.push_back(a);
			sort(numbers.begin(), numbers.end());
			if (!binary_search(numbers.begin(), numbers.end(), a))
				numbers.push_back(a);
			else
				repeats++;
		}

		if (isBeautiful(array, k)) {
			cout << array.size() << endl;
			//cout << "Already\n";
			for (int j = 0; j < array.size(); j++) {
				if (j != 0)
					cout << " ";
				cout << array[j];
			}
			cout << endl;
		}
		else if (numbers.size() > k) {
			//cout << "size " << numbers.size() << endl;
			cout << "-1\n";
		}
		else {
			//cout << "size " << numbers.size() << endl;
			sort(numbers.begin(), numbers.end());
			int lowest = 0;
			while (numbers.size() % k != 0) {
				if (!binary_search(numbers.begin(), numbers.end(), lowest+1))
					numbers.push_back(lowest+1);
				lowest++;
				if (lowest == k)
					break;
			}

			auto it = std::unique( numbers.begin(), numbers.end() );
			bool wasUnique = (it == numbers.end() );

			if (wasUnique) {		
				while (answer.size() + numbers.size() <= 10000)
					answer.insert(answer.end(), numbers.begin(), numbers.end());
				cout << answer.size() << endl;
				for (int j = 0; j < answer.size(); j++) {
					if (j != 0)
						cout << " ";
					cout << answer[j];
				}
			}
			else {
				cout << "-1";
			}
			//cout << isBeautiful(answer, k);
			cout << endl;
		}



	}

	return 0;
}