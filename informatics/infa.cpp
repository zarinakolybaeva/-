#include<iostream>
#include<deque>
using namespace std;
int main (){
    string s="";
    deque<int>deq;
    while(s!="exit"){
     int n;
     cin>>s;
     if(s=="push_front"){
        cin>>n;
        deq.push_front(n);
        cout<<"ok"<<endl;
     }
        if(s=="push_back"){
        cin>>n;
        deq.push_front(n);
        cout<<"ok"<<endl;
     }
     if(s=="clear"){
        while(!deq.empty()){
            deq.pop_front();
        }
        cout<<"ok"<<endl;
     }
     if(s=="pop_front"){
        if(deq.empty()){
            cout<<"error"<<endl;
        }
        else {
        cout<<deq.front()<<endl;
          deq.pop_front();
     }
     }
        if(s=="pop_back"){
        if(deq.empty()){
            cout<<"error"<<endl;
        }
        else {
        cout<<deq.back()<<endl;
          deq.pop_back();
     }
     }
     if(s=="size"){
        cout<<deq.size()<<endl;
     }
      if(s=="front"){
        if(deq.empty()){
            cout<<"error"<<endl;
        }
        cout<<deq.front()<<endl;
      }
      if(s=="back"){
        if(deq.empty()){
            cout<<"error"<<endl;
        }
        cout<<deq.back()<<endl;
      }
  
}
  cout<<"bye"<<endl;
}