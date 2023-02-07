#include<iostream>
using namespace std;
struct node{
    int val;
    int cnt;
    node* next;
    node* prev;
    node(){
        this->cnt=0;
        this->val=0;
        this->next=NULL;
        this->prev=NULL;
    }
    node(int val){
        this->cnt=1;
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
      node(int val,node* next,node* prev){
        this->cnt=1;
        this->val=val;
        this->next=next;
        this->prev=prev;
    }
};
struct linked_list{

    node* head;
    node* tail;
    linked_list(){
        this->head=NULL;
      this->tail=NULL;
    }
    void push(int val){
        node* temp=new node(val);
        if(this->head==NULL){
            this->head=temp;
            this->tail=temp;
        }
        else{
            this->tail->next=temp;
            temp->prev=this->tail;
            this->tail=temp;
          
        }
        }
void orint(){
    node* cur=this->head;
    while(cur->next!=NULL){
        cout<<cur->val<<" ";
        cur=cur->next;
    }
}

 void print(){
    node* cur=this->head;
    
    while(cur!=NULL){
            node* delt=cur->next;
            cur->next=cur->next->next;
            cur->next->prev=cur;
            delete delt;
            cur=cur->next;
           cout<<cur->val<<" ";
    }

 
 }
};
int main (){
    linked_list list;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        list.push(x);
    }

    list.print();
}