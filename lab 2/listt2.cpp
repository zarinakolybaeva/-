#include<iostream>
using namespace std;
class Solution{
    public:
    ListNode* removeelements(ListNode* head,int val){
        while(head!=NULL && head->val==val){
            head=head->next;
        }
        ListNode* cur=head;
        while(cur!=NULL && cur->next!=NULL){
            if(cur->next->val==val){
                cur->next=cur->next->next;
            }else{
                cur=cur->next;
            }
        }
      return head;
    } 

}
int main (){
    
}