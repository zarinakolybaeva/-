#include<bits/stdc++.h>
// wrong
using namespace std;
int main (){
       int k;
       cin>>k;
       deque<int>d;
       while (k--){
       int n;
       cin>>n;
    
        for(int i = n;i>=1;i--)
        {
            d.push_front(i);
            for(int j = 0;j<i;j++)
            {
                int t = d.back();
                d.pop_back();
                d.push_front(t);
            }
        }
       }
       // vector<int> ans;
        while(!d.empty())
        {
            cout<<d.front()<<" ";
            d.pop_front();
        }
      //  return ans;
    
}