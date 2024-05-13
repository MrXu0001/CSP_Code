#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	map<int, int> frequency;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		frequency[num]++;
	}
	int maxFrequency = 0;
	int minNumber = 10001;
	for (const auto &pair: frequency) {
		if (pair.second > maxFrequency || pair.second == maxFrequency && pair.first < minNumber) {
			minNumber = pair.first;
			maxFrequency = pair.second;
		}
	}
	cout << minNumber << endl;
	return 0;
}
