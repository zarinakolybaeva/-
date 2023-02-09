#include <iostream>
#include<stack>
using namespace std;
int main (){
  string s1,s2;
  cin>>s1>>s2;
  stack<char>st1;
  for(int i=0;i<s1.size();i++){
    if(s1[i]=='#' && !st1.empty()){

        st1.pop();
    }
    else if(s1[i]!='#') {
        st1.push(s1[i]);
    }
  }
  stack<char>st2;
  for(int i=0;i<s2.size();i++){
    if(s2[i]=='#' && !st2.empty()){
        st2.pop();
    }
    else if(s2[i]!='#'){
        st2.push(s2[i]);
    }
  }
 

  if(st1==st2){
    cout<<"Yes";
  }
  else {
    cout<<"No";
  }
  //  while(!st1.empty()){
  //   cout<<st1.top()<<" ";
  //   st1.pop();
  // }

  //  while(!st2.empty()){
  //   cout<<st2.top()<<" ";
  //   st2.pop();
  // }
    }
