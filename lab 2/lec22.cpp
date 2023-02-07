#include<iostream>
using namespace std;
class Node {
public:
  int Value;
  Node* Next;
};
void printList(Node*n){
  while(n!=0){
    cout<<n->Value<<endl;
    n=n->Next;
  }
}
void insertAtTheFront(Node**head,int newValue){
  //1.prepare a newNode
  Node* newNode=new Node();
  newNode->Value=newValue;
  //2.Put it in front of current head
  newNode->Next=*head;
  //3.Move head of the list to point to the newNode
  *head=newNode;
}
void insertAtTheEnd(Node** head,int newValue ){
  //1.Prepare a newNode
  Node*newNode=new Node();
  newNode->Value=newValue;
  newNode->Next=NULL;
  //2.If linked list is empty,newNode will be a head node
  if(*head==NULL){
     *head=newNode;
     return;
  }
  //3.Find the last node
  Node* last=*head;
  while(last->Next!=NULL){
    last=last->Next;
  }


  //4.Insert newNode after last node(at the end)
  last->Next=newNode;
}
void insertAfter(Node*previous,int newValue){
  //1 check if previous mode is NULL
  if(previous==NULL){
    cout<<"previous can not be NULL";
    return;
  }
  //2 prepare a newNode
  Node* newNode=new Node();
  newNode->Value=newValue;
  //3 insert newNode after previous 
  

}
int main (){
    // linked list each of them store next addres and 
    // and last one stores 0
    // ad:arrays- fixed size ,link-dynamic size
    // disad:randomly positioned elements in link
    // where second element know first element ,where second element know third element
    // disad:list need more memory because each element stores 2 things
    // stores value and pointer 
    
    
    // insertAtTheFront(&head,-1);
    // insertAtTheEnd(&head,4);

    printList(head);
}