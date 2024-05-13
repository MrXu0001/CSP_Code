#include<bits/stdc++.h>
using namespace std;

int main() {
	string isbn;
	cin >> isbn;
	int sum = 0;
	int multiplier = 1;
	for (char c : isbn) {
		if (c != '-' && multiplier != 10) {
			sum += (c - '0') * multiplier;
			multiplier++;
		}
	}
	int remainer = sum % 11;
	char correntCheckSum;
	if (remainer == 10) {
		correntCheckSum = 'X';
	}
	else correntCheckSum = remainer + '0';
	if (isbn[isbn.size() - 1] == correntCheckSum) {
		cout << "Right" << endl;
	} else {
		isbn[isbn.size() - 1] = correntCheckSum;
		cout << isbn << endl;
	}
	return 0;
}
