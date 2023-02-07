#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
int main(){
    int n;
    cin>>n;
    Node* node=new Node(n);
    Node* node1=new Node(n);
    cout<<node->data;
    return 0;
}