#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* next;
    node(){
        this->val=0;
        this->next=NULL;
    }
    node(int val){
        this->val=val;
        this->next=NULL;
    }
    node(int val,node* next){
        this->val=val;
        this->next=next;
    }
};
struct linked_list{
    int size;
    node* tail;
    node* head;
    linked_list(){
    this->size=0;
    this->tail=NULL;
    this->head=NULL;
    }
    void addhead(int val){
        node* cur=new node(val);
        if(this->head=NULL){
            this->head=cur;
            this->tail=cur;
        }
        else {
            cur->next=this->head;
            this->head->prev=cur;
            this->head=cur;
        }
        this->size++;
    }
    void addtail(int val){
        node* cur=new node(val);
        if(this->head=NULL){
            this->head=cur;
            this->tail=cur;
        }
        else{
            this->tail->next=cur;
            cur->prev=this->tail;
            this->tail=cur;
        }
    }
    void addindex(int index,int val){
        node* cur=new node(val);
        node* temp=this->head;
        if(index>this->size){
            return ;
        }
        else if(index==0){
            this->addhead(val);
        }
        else if(index==this->size){
            this->addtail(val);
        }
        else {
            for(int i=0;i<index;i++){
                cur=cur->next;
            }
          temp->next=cur->next;
         cur->next->prev=temp;
          cur->next=temp;
         temp->prev=cur;
        }
    }
   void replace(int p1,int p2){
    node* cur=head;
    int i=1;
    while(cur!=NULL){
      int v1,v2;
      if(i==p1){
        v1=cur->val;
      }
      if(i==p2){
        v2=cur->val;
      }
      if(i==p2){
        cur->val=v1;
      }
      if(i==p1){
        cur->val=v2;
      }
      i++;
      cur=cur->next;
    }
   }
    void deleteind(int index){
        this->size--;
    if(index==0){
        this->head=this->head->next;
         this->head->prev=NULL;
    }
    else if(index==this->size-1){
       
        this->tail=this->tail->pev;
        this->tail->next=NULL;
        
    }
    else {
        node* cur=this->head;
        for(int i=0;i<index;i++){
            cur=cur->next;
        }
        
        node* prevv=cur->prev;
        node* nextt=cur->next;
        prevv->next=nextt;
        nextt->prev=prevv;
        
    }
    }
    void reverse(){
      node* cur=this->head;
      while(cur!=NULL){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
      }
     this-> head=prev;
    }
    void cyclic_left(int x){
      node* cur=this->head;
      while(cur->next!=NULL){
        cur=cur->next;
       while(x--){
        node* temp=new node(this->head->val);
        cur->next=temp;
        temp->prev=cur;
        cur=temp;
        node* temp2=head;
        head=temp->next;
        heaed->prev=NULL;
       }  
    }
void print(){
    node* cur=this->head;
    while(cur!=NULL){
        cout<<cur->val<<" ";
        cur=cur->next;
    }
}

};

int main (){
linked_list list;

}
