#include<iostream>
using namespace std;
struct st{
int a[100];
int topIndex;
st(){
    topIndex=-1;
}
int top(){
    if(top==-1)  
    return -1;
    return a[topIndex];
}
void push(int x){
topIndex++;
a[topIndex]=x;
}
void pop(){
    if(topIndex!=-1){
        top--;
    }
}
};
int main (){


st s;
int d[]={1,10,2,3,5,4};
int n=sizeof(d)/sizeof(int);

for(int i=0;i<n;i++){
    s.push(d[i]);
}
cout<<s.top()<<endl;
    return 0;
}