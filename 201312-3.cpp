#include<bits/stdc++.h>
using namespace std;

// 两大注意点，1. 思考要不要严格小于  2. 边界是-1和n
int main() {
	int n;
	cin >> n;
	vector<int> nums(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	vector<int> left(n, 0);
	vector<int> right(n, 0);
	stack<int> stack_l;
	for (int i = 0; i < n; i++) {
		// 单调递增栈，找到左边第一个小于自己的下标（把比自己大的都弹走了，那么左边的一定是比自己小的）
		while (!stack_l.empty() && nums[stack_l.top()] >= nums[i]) {
			stack_l.pop();
		}
		left[i] = stack_l.empty() ? -1 : stack_l.top();
		stack_l.push(i);
	}
	stack<int> stack_r;
	for (int i = n - 1; i >= 0; --i) {
		while (!stack_r.empty() && nums[stack_r.top()] >= nums[i]) {
			stack_r.pop();
		}
		right[i] = stack_r.empty() ? n : stack_r.top();
		stack_r.push(i);
	}
	int maxSize = 0;
	for (int i = 0; i < n; i++) {
		int size = (right[i] - left[i] - 1) * nums[i];
		if (size > maxSize) {
			maxSize = size;
		}
	}
	cout << maxSize << endl;
	return 0;
}

