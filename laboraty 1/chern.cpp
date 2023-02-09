#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
    
    Node(){ 
        this->val=0;
        this->next=NULL;// указывает в никуда
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
 struct List{
    int size;
    // node is in above is just to write like that as under
    Node *head;// in linked list have his head and tail 
    Node *tail;

    List(){
        this->size=0;
        this->head=NULL;
        this->tail=NULL;
    }
    void addhead(int val){
        this->size++;
        Node* temp=new Node(val);
        if(this->head==NULL){
            this->head=temp;
            this->tail=temp;   
        }
        else {
            temp->next=this->head; // начинает указывает на голову
            this->head=temp; // нашой головой становится новая нода 
        }
    }
    void addtail(int val){
        this->size++;
        Node* temp=new Node(val);
        if(this->head==NULL){
            this->head=temp;
            this->tail=temp;
        }
        else {
            this->tail->next=temp;
            this->tail=temp;
        }
    }
    void addindex(int index,int val){
        if(index>this->size){
            return;
        } else if(index==0){
            this->addhead(val);
        } else if(index==this->size){
            this->addtail(val);
        } else {
            Node* temp=new Node(val);
            Node* cur=this->head;
            for(int i=1;i<index;i++){
                cur=cur->next;
            }
            temp->next=cur->next;
            cur->next=temp;
        }
        this->size++;
    }
    int get(int index){
        if(index<0 || index>=this->size){
            return -1;
        }
        Node* cur=this->head;
        for(int i=0;i<index;i++){
            cur=cur->next;
        }
        return cur->val;
    }
    void deleteindex(int index){
        if(index==0){
            this->head=this->head->next;
            this->size--;
        }
        else if(index==this->size-1){
            Node* cur=this->head;
            while(cur->next!=this->tail){
                cur=cur->next;
            }
            this->tail=cur;
            this->size--;
        }
        else if(index >0 && index<this->size-1){
         Node* cur=this->head;
         for(int i=0;i<index-1;i++){
            cur=cur->next;
         }
         cur->next=cur->next->next;
         this->size--;
        }
    }
   void less_number(int target) {
        Node* cur = head;
        int res = 1000000;
        int i=0;
        int res_i;
        while(cur!=NULL) {
            if(abs(target-cur->val)<res) {
                res=abs(target-cur->val);
                res_i = i;
            }
            cur=cur->next;
            i++;
        }
        cout<<res_i;
    }
    void print(){
        Node*  cur=this->head;
        while(cur!=NULL){
             cout<<cur->val<<" ";
             cur=cur->next;
        }
       cout<<endl;
    }
 };
int main (){
List noden;
noden.addtail(9);
noden.addhead(2);
noden.addhead(3);
noden.addtail(8);
    
}