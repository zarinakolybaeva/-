#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int i)
{
    if (i <= 1)
        return false;
        
    for (int j = 2; j < i; j++)
        if (i % j == 0)
            return false;
 
    return true;
}
int main() {

  int n;
  cin>>n;
  vector<int> arr;
  vector<int> arr1;
  for (int i=1;i<=7919;i++){
      if(is_prime(i) == true){
          arr.push_back(i);
      }
  }
  for (int i=1;i<=1000;i++){
      if(is_prime(i) == true){
          arr1.push_back(arr[i-1]);
     } 
  }
  
  cout<<arr1[n-1]<<endl;

}