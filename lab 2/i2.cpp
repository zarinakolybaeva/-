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
    void push_back(int val){
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
    void push_front(int val){
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
void erase_front(){
    this->head=this->head->next;
    this->head->prev=NULL;
}
void erase_back(){
    this->tail=this->tail->prev;
    this->tail->next=NULL;
}
void front(){
    cout<<head->val<<endl;
}
void back(){
    cout<<tail->val<<endl;
}
void clear(){
    head=tail=NULL;

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
string s;
cin>>s;
if(s=='add_front'){
    string k;
    cin>>k;
    list.push_front();
    cout<<ok;
}
else if(s=='add_back'){
    string k;

}
   
}