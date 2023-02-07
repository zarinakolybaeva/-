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

int getPeriod(int nd, vector<int> pi){
    int len = nd - pi[nd - 1];
    if(pi[nd - 1] == 0) return 0; 
    if((nd / len)%2 == 0 && nd%len == 0){
        return len;
    }
    return 0;
}

int count(string s){
    vector<int> pi = perfixFunction(s);
    int cnt = 0;
    for(int i = 1; i < s.size(); i++){
        int len = i - pi[i - 1];
        if(pi[i - 1] == 0) continue;
        if((i / len)%2 == 0 && i%len == 0){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    string s; cin >> s;
    cout << count(s);

    return 0;
}