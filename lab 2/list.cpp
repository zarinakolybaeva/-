#include<iostream>
using namespace std;
struct Node{
    int val;
    Node* next;
    
    Node(){ 
        this->val=0;
        this->next=NULL;
    }
    Node(int val){
        this->val=val;
        this->next=NULL;

    }
    Node(int val,Node *next){
       this->val=val;
       this->next=next;
    }
 };
//  struct List{
//     int size;
//     Node *head;
//     Node *tail;

//     List(){
//         this->size=0;
//         this->head=NULL;
//         this->tail=NULL;

//     }
//  };
int main (){
  
  Node* node1=new Node(10);
  Node* node2=new Node(20,node1);
  Node* node3=new Node(30,node2);
  cout<<node1->val<<" "<<node1->next<<endl;
  cout<<node2->val<<" "<<node2->next->val<<endl;
  cout<<node3->val<<" "<<node3->next->val<<endl;
  return 0;
}