#include<iostream>
using namepsace std;
class Node{
    public:
    Node* middleNode(Node* head){
    int size=0;
    Node* cur=head;
    while(cur!=NULL){
        size++;
        cur=cur->next;
    }
    cur=head;
    for(int i=0;i<size/2;i++){
        cur=cur->next;
    }
    return cur;
}
};
// void printList(Node*head){
//   while(head!=0){
//     cout<<head->Value<<endl;
//     head=head->Next;
//   }
// }
// int main (){
//     Node* head=new Node();
//     // 1 2 3 4 5  сколько шагов до 3 : 2 шага 
//     // --> 5/2=2 
//     // 1 2 3 4 5 6  ---> 6/2=3  --> 3 шага
//     Node
// }