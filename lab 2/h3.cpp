#include<iostream>
using namespace std;
struct node{
    int val;
    int cnt;
    node* next;
    node* prev;
    node(){
        this->cnt=0;
        this->val=' ';
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
    int size;
    node* head;
    node* tail;
    linked_list(){
      this->size=0;
      this->head=NULL;
      this->tail=NULL;
    }
    void addtail(int val){
        this->size++;
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
    void addhead(int val){
        this->size++;
          node* temp=new node(val);
        if(this->head==NULL){
            this->head=temp;
            this->tail=temp;
        }
        else {
            temp->next=this->head;
            this->head->prev=temp;
            this->head=temp;
        }
    }
    void addindex(int val,int index){
        if(index<0 || index>this->size){
            return ;
        }
        else if(index==0){
            this->addhead(val);
        }
        else if(index==this->size){
            this->addtail(val);
        }
        else {
            node* temp=new node(val);
            node* cur=this->head;
            for(int i=0;i<index;i++){
                cur=cur->next;
            }
            temp->next=cur->next;
            cur->next=temp;
            this->size++;
        }
    }
void remove(int index){
    this->size--;
if(index==0){
    this->head=this->head->next;
    this->head->prev=NULL;
}
else if(index==this->size)
{
  this->tail=this->tail->prev;
  this->tail->next=NULL;


}
else {
  node* cur=this->head;
  for(int i=0;i<index-1;i++){
    cur=cur->next;
  }
  node* prevv=cur->prev;
  node* nextt=cur->next;
  prevv->next=nextt;
  nextt->prev=prevv;
}
}
void reverse(){
    node* cur=this->tail;
    while(cur!=NULL){
        cout<<cur->val<<" ";
        cur=cur->prev;
    }
}
void cyclic_left(int k){
    node* cur=this->head;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    while(k--){
        node* newn=new node(this->head->val);
        cur->next=newn;
        newn->prev=cur;
        cur=newn;
        node* temp=this->head;
        this->head=temp->next;
        this->head->prev=NULL;
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
   list.addhead(3);
   list.addtail(0);
   list.addindex(1,2);
   list.addtail(2);
   list.print();
   cout<<endl;
 //  list.remove(2);
   list.cyclic_left(1);
   list.print();
  //  cout<<endl;
  //  list.reverse();
}
// int n;
// cin>>n;
// if(n==0){
//     return 0;
// }
// else if(n==1){
//     list.addindex(x,p);
// }
