#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* next;
    node* prev;
    node(){
    this->val=0;
    this->next=NULL;
    this->next=NULL
    }
    node(int val){
    this->val=val;
    this->next=NULL;
    this->next=NULL;
    }
    node(int val,node* next){
    this->val=val;
    this->next=next;
    }
};
struct linked_list{
    node* head;
    node* tail;
linked_list(){
    this->head=NULL;
    this->tail=NULL;
}

void addend(int val){
node* cur=new node(val);
if(this->head==NULL){
    this->head=cur;
    this->tail=cur;
}
else {
    this->tail->next=cur;
    this->tail=cur;
}
}
void print(){
  node* cur=head;
  while(cur!=NULL && cur->next!=NULL){
    node* temp=cur->next;
    cur->next=cur->next->next;
    cur->next->prev=cur;
    delete temp;
    cur=cur->next;
  }
}
};
int main (){
linked_list list;
int n;
cin>>n;
int a[n];
for(int i=1;i<=n;i++){
    cin>>a[i];
    if(i%2==0){
        continue;
    }
    else {
        list.addend(a[i]);
    }
}
 list.print();

}