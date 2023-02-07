#include <iostream>
#include <vector>
using namespace std;

vector<int> perfixFunction(string s){
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

int kmp(string s, string t){
    s = t + "#" + s;
    vector<int> pi = perfixFunction(s);
    for(int i = 0; i < s.size(); i++){
        if(pi[i] == t.size()){
            return i - 2*t.size();
        }
    }
    return -1;
}

int main(){
    string a, b; cin >> a >> b;
    int orS = a.size();
    if(a == b){
        cout << 1;
        return 0;
    }
    while(a.size() < 100000){
        a = a + a;
    }
    cout<<a<<endl;
    int res = kmp(a, b);
    if(res >= 0){
        cout << (res + b.size())/(orS) + 1;
    }
    else{
        cout << res;
    }

    return 0;
}