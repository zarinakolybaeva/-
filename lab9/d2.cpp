#include <bits/stdc++.h>
using namespace std;

vector<int> prefix(string s) {
	vector<int> pi(s.size());
	for (int i = 1; i < s.size(); i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

int main() {
	string s;
	int n;
	cin >> s >> n;
	s[0] += 32;
	vector<string> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		vec[i][0] += 32;
	}
	int maxi = -1;
	vector<string> res;
	for (int i = 0; i < vec.size(); i++) {
		string ke = vec[i] + s;
		vector<int> pi = prefix(ke);
		int longest = pi.back();
		if (maxi < longest) {
			maxi = longest;
			res.clear();
			res.push_back(vec[i]);
		} else if (maxi == longest) {
			res.push_back(vec[i]);
		}
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		res[i][0] -= 32;
		cout << res[i] <<endl;
	}
	return 0;
}