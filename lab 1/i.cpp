#include<iostream>
#include<deque>
using namespace std;
int main (){
    deque<char>d1;
    deque<char>d2;
    int n;
    int j;
    string s;
    cin>>n>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='S'){
            d1.push_back(i);
        }
        else {
            d2.push_back(i);
        }
        while(!d1.empty() && !d2.empty()){
            i=d1.front();
            j=d2.front();
            if(i<j){
                d2.pop_front();
                d1.push_back(i+s.size());
                d1.pop_front();
            }
            else if(j<i){
                d1.pop_front();
                d2.push_back(j+s.size());
                d2.pop_front();
            }
        }
    }
    if(d1.empty()){
        cout<<"KATSURAGI";
    }
    else{
        cout<<"SAKAYANAGI";
    }
    
}