#include<iostream>
#include<queue>
using namespace std;

queue<string> q[12];

int main(){
    int n;
    string s;
    while(cin >> n >> s && n != 0){
        q[n].push(s);
    }
    for(int i = 9; i <= 11; i++){
        while(q[i].empty() == 0){
            cout << i << ' ' << q[i].front() << endl;
            q[i].pop();
        }
    }
}

// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     setlocale(LC_ALL, "rus");
//     vector<pair<int, string> > v;
//     int n, m;
//     string s;
//     while (cin >> n >> s) {
//         v.push_back(make_pair(n, s));
//     }
//     stable_sort(v.begin(), v.end(), [](pair<int, string> n, pair<int, string> s){
//         return n.first < s.first;});
//     m = v.size();
//     for(int i = 0; i < m; i++){
//         cout << v[i].first << " " << v[i].second << endl;
//     }
// }