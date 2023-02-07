#include<iostream>
using namespace std;
struct node{
    int val;
    node* next;
    node* prev;
    int cnt;
    node(){
        this->val=0;
        this->cnt=1;
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
        this->val=val;
        this->cnt=1;
        this->next=next;
       this->prev=prev;
    }
};
struct linked_list{
    int max;
    node* head;
    node* tail;
    linked_list(){
    this->max=0;
    this->head=NULL;
    this->tail=NULL;
    }
void addtail(int val){
    node* temp=new node(val);
    if(this->head==NULL){
        this->head=temp;
     //   this->tail=temp;
    }
    else {
        node* cur=this->head;
        while(cur!=NULL){
            if(cur->val==val){
            cur->cnt++;
            break;
            }
            else if(cur==NULL || cur->next==NULL){
                cur->next=temp;
                break;
            }
            cur=cur->next;

        }

    }
}
void maxi(){
node* cur=this->head;
while(cur!=NULL){
    if(cur->cnt>this->max){
        max=cur->cnt;
    }
    cur=cur->next;
}
}
// void sort(){
// node* first=this->head;
// node* second=NULL;
// while(first!=NULL){
//     second=first->next;
//     while(second!=NULL){
//        if(first->val < second->val) {
//              swap(first->val, second->val);
//              swap(first->cnt, second->cnt);
//                 }
//                 if(first->cnt > second->cnt){
//                     swap(first->val, second->val);
//                     swap(first->cnt, second->cnt);
//                 }
//                 second=second->next;
//     }

//     first=first->next;
// }

void print(){
    node* cur=this->head;
    while(cur!=NULL){
     //   sort();
        if(cur->cnt==max){
            cout<<cur->val<<" ";
        }
        cur=cur->next;
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
    list.addtail(x);
}

list.maxi();
list.print();
}
