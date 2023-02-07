#include<iostream>
using namespace std;
struct node{
 int val;
 node* next;
 node* prev;
 node(){
    data=0;
 }
 node(int data){
    data=data;
 }
 node(int data,node *_nxt){
    data=data;
    nxt=_nxt;
 }
};
struct list{
    node*head=0;
    node* get_tail(){
        if(head==0)
        return 0;
        node* cur=head;
        while(cur->nxt!=0)
        cur=cur->nxt;
        return cur;
    }
    node* get(int i){
        for(int j=0;j<i;j++){
            if(cur==0)
            return 0;
            cur=cur->nxt;
        }
        return cur;
    }
    void addhead(int data){
        node *newo=new node(data,head);
        head=newo;
    }
    void addtail(int data){
     node* tail=get_tail();
     node* newo=new node(data,0);
     tail->nxt=newo;
    }
    void addind(int i,int data){
        if(i==0){
            addhead(data);
            return;
        }
        node* A=get(i-1);
        if(A==0){
        insert tail(data);
        return;
        }
        node* B=A->nxt;
        node* newo=new node(data,B);
        A->nxt=newo;
    }
   void less_number(int target) {
        Node* cur = head;
        int res = 1000000;
        int i=0;
        int res_i;
        while(cur!=nullptr) {
            if(abs(target-cur->val)<res) {
                res=abs(target-cur->val);
                res_i = i;
            }
            cur=cur->next;
            i++;
        }
        cout<<res_i;
    }
   void  print(){
    cout<<"[";
    node* cur=head;
    while(cur!=0){
        cout<<cur->data;
        cur=cur->nxt;
        if(cur==0)
         cout<<"]";
         else
         cout<<",";
         
    }
    }
};
int main (){
list l;
l.addhead(0,10);
l.addhead(1,20);
l.print();

}