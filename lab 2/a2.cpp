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
      void addend(int val){
        this->size++;
        Node* cur=new Node(val);
        if(this->head==NULL){
            this->head=cur;
            this->tail=cur;
        }
        else {
            this->tail->next=cur;
            this->tail=cur;
        }
    }
    void solve(int target){
        Node* cur=this->head;
        int res=100000;
        int i=0;
        int res_i;
        while(cur!=NULL){
            if(abs(target-cur->val)<res){
                res=abs(target-cur->val);
                res_i=i;
            }
            cur=cur->next;
            i++;
        }
        cout<<res_i;
    }
    
  
 
 };
int main (){
    List list;
    int n;
    cin>>n;
    for(int  i=0;i<n;i++) {
        int x;
        cin>>x;
        list.addend(x);

    }
   
    int t;
    cin>>t;
    list.solve(t);

}