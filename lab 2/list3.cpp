#include<iostream>
using namespace std;
class Node{
public:
  int value;
  Node* next;
};
void print(Node*n){
while(n!=NULL){
    cout<<n->value<<endl;
    n=n->next;
}
}
void insertatfront(Node** head,int nvalue ){
// 1 prepare a new node
Node* nnode=new Node();
nnode->value=nvalue;
// 2 put it in front of current head
nnode->next=*head;
// 3 move head of the list to point to new node 
*head=nnode;
}
void insertatend(Node** head,int nvalue){
// 1. prepare a new node
Node*nnode=new Node();
nnode->value=nvalue;
nnode->next=NULL;
// 2. if linked list is empty,new node will be a head node
if(*head==NULL){
    *head=nnode;
    return;
}
// 3.find the last node
Node*last=*head;
while(last->next!=NULL){
    last=last->next;

}
// 4.insert new node after last node (at the end)
last->next=nnode;
}
void insertafter(Node*prev,int nvalue){
//1.check if previous node is NULL
if(prev==NULL){
    cout<<"Previous can not be NULL";
    return  ;
}
//2.prepare a new node
Node*  nnode=new Node();
nnode->value=nvalue;
//3.insert new node after previous  
nnode->next=prev->next;
prev->next=nnode;
}
int main (){
 Node* head=new Node();
 Node* second=new Node();
 Node* third=new Node();
 head->value=1;
 head->next=second;
 second->value=2;
 second->next=third;
 third->value=3;
 third->next=NULL;
 insertafter(head,-1);
 insertafter(second,-2);
//  insertatfront(&head,-1);
//  insertatend(&head,5);
 print(head);
}