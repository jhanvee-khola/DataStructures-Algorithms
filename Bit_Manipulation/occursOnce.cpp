#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int ones=0,twos=0;
  for(int i=0;i<n;i++){
    twos=twos|(ones&arr[i]);
    ones=ones^arr[i];
    int mask=~(ones&twos);
    ones&=mask;
    twos&=mask;
  }
  //result=ones;
  return 0;
}
