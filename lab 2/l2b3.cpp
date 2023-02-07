#include<iostream>
using namespace std;
bool check(int a[],int mx,int k){
    int cnt=1;
    int cur=0;
    for(int i=0;i<a.size();i++){
    if(a[i]>mx){
        return false;
    }
    else if(cur+a[i]>mx){
        cnt++;
        cur=a[i];
    }
    else{
        cur+=a[i];
    }

    }
    return cnt<=k;
}
int main (){
    int ans;
int l=0,r=n-1;
while(l<=r){
    int mid=l+r/2;
    if(check(a,mid,k)){
      r=mid-1;
      ans=mid;
    }
    else{
        l=mid+1;
    }
    return ans;
}

}