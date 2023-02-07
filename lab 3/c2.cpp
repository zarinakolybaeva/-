#include<iostream> 
#include<set> 
#define ll long long
using namespace std; 
 
int main() 
{ 
  ll n ,q;
  cin>>n>>q; 
  int a[n]; 
  for(ll i=0;i<n;i++) 
  { 
    cin>>a[i]; 
  } 
  for(ll i=0;i<q;i++) 
  { 
    set<int> s; 
    int  l1,r1,l2,r2; 
    cin>>l1 >>r1 >>l2>>r2; 
    for(int i=0;i<n;i++) 
    { 
      if((a[i]>=l1 && a[i]<=r1) || (a[i]>=l2 && a[i] <=r2)) 
      { 
        s.insert(a[i]); 
      } 
    } 
    cout<<s.size()<<endl; 
  } 
   
   
  return 0;   
}