#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	unsigned long long left = 0, right = 1e15, mid, cnt, sum;
	while (left <= right) {
		mid = left + (right - left) / 2;
		cnt = 1;
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (mid < sum + arr[i]) {
				sum = 0;
				cnt++;
			}
			if (mid < arr[i]) {
				cnt = k + 1;
			}
			sum += arr[i];
		}
		if (k < cnt) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	cout << left;

	return 0;
}