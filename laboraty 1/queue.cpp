#include<iostream>
using namespace std;
struct queue{
    int a[100];
    int st,en;
    queue(){
        st=en=0;
    }
    int size(){
        return en-st;
    }
    bool empty(){
        return st==en;
    }
    int front(){
          if(empty()){
            cout<<"queue error"<<endl;
    
        }
       return a[st];
    }
    void push(int x){
        a[en++]=x;
    }
    void pop(){
        if(empty()){
            cout<<"queue error"<<endl;

        }
        st++;
    }

};
int main (){
queue q;
q.push(20);
q.push(30);
cout<<"front"<<q.front()<<endl;
q.pop();
cout<<"size"<<q.size()<<endl;
cout<<q.empty()<<endl;
q.pop();
cout<<q.empty()<<endl;
}