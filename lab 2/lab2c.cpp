#include<iostream>
using namespace std;
struct Node{
    int val;
    Node*next;
    Node(int val){
        this->val=val;
        next=NULL;
    }
};
class LinkedList{
    public:
    Node*head;
    LinkedList(){
        head=NULL;
    }

void push(int val){
    Node*newNode=new Node(val);
    if(head==NULL){
        head=newNode;
    }
    else {
        Node*i=head;
        while(i->next!=NULL){
            i=i->next;
        }
      i->next=newNode;   
    }
}
void print(){
    Node*i=head;
    while(i!=NULL){
        cout<<i->val<<endl;
        i=i->next;
    }
}
};
int main (){
LinkedList list;
if(list.push)
list.push(5);
list.push(3);
list.print();
}