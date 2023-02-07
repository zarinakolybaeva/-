#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        map<int, vector<string>> v;
        while(1){
            string s; cin >> s;
            int st = s.size();
            v[st].push_back(s);
            if(cin.get()=='\n'){
                break;
            } 
        }
        for(auto i : v){
            for(auto j : i.second)
                cout << j << ' ';
        }
        cout << '\n';
    }
}