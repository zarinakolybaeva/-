#include <bits/stdc++.h>
using namespace std;

vector<int> prefix(string s){
    vector<int> pi(s.size());
    pi[0] = 0;
    for(int i = 1;i < s.size(); i++){
        int j = pi[i-1];
        while(j > 0 && s[j] != s[i]){
            j = pi[j-1];
        }
        if(s[j] == s[i]){
            pi[i] = j + 1;
        }
        else{
            pi[i] = 0;
        }
    }
    return pi;
}

vector<int> ans(string s, string t){
    s = t + "#" + s;
    vector<int> res;
    vector<int> pi = prefix(s);
    for(int i = 0; i < s.size(); i++){
        if(pi[i] == t.size()){
            res.push_back(i - 2*t.size());
        }
    }
    return res;
}

int main(){
    string s; int k; cin >> s >> k;
    string p; cin >> p;
    if(ans(p,s).size() >= k){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}