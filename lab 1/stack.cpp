/*
stack FILO 
queue FIFO
*/
#include<iostream>
using namespace std;
// #include<stack>
struct stack{
int a[100];
int n;
stack(){
    n=0;
}
int size(){
    return n;
}
int push(int x){
    a[n++]=x;
}
void pop(){
    if(n==0){
        cout<<"error";
    }
   n--;
}
int top(){
    return a[n-1];
}
};
int main(){
 stack st;
 st.push(10);
 st.push(20);
 cout<<"size"<<st.size()<<endl;
 cout<<"top"<<st.top()<<endl;
 st.pop();
 cout<<"size"<<st.size()<<endl;

}