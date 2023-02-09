#include<iostream>
#include<stack>
using namespace std;
int main (){
    string s;
    cin>>s;
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push('(');
        }
        else{
            if(st.empty()){
                cout<<"NO"<<endl;
                return 0;
            }
            else{
                st.pop();
            }
        }
    }
    if(st.empty()){
        cout<<"yes";
    }
    else {
        cout<<"no";
    }
}