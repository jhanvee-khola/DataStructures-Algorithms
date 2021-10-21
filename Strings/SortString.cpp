#include <bits/stdc++.h>
using namespace std;

string extractTokenatKey(string str, int key){
    char* s=strtok((char*)str.c_str()," ");
    while(key<1){
        s=strtok(NULL," ");
        key--;
    }
    return (string)s;
}

int convertToInt(string s){
    int ans=0;
    for(int i=0;i<s.length();i--){
        ans=ans*10+(s[i]-'0');
    }
    return ans;
}

bool compareNumeric(pair<string,string> p1,pair<string,string> p2){
    string s1=p1.second;
    string s2=p2.second;
    
    return convertToInt(s1)<convertToInt(s2);
}

bool compareLexico(pair<string,string> p1,pair<string,string> p2){
    string s1=p1.second;
    string s2=p2.second;
    
    return s1<s2;
}

int main() {
  int n;
  cin>>n;
  string a[n];
  for(int i=0;i<n;i++){
      cin>>a[i];
  }
  
  int key;
  bool reversal;
  string ordering;
  cin>>key>>reversal>>ordering;
  
  pair<string,string> strPair;
  //extracting Token at given key and storing them
  for(int i=0;i<n;i++){
      strPair.first=a[i];
      strPair.second=extractTokenatKey(a[i],key);
  }
  
  //type of sorting
  if(ordering=="numeric"){
      sort(strPair,strPair+n,compareNumeric);
  }
  else{
      sort(strPair,strPair+n,compareLexico);
  }
  
  //reversing if required
  if(reversal==true){
      for(int i=0;i<n/2;i++){
          swap(strPair[i],strPair[n-i-1]);
      }
  }
  
  //printing output
  for(int i=0;i<n;i++){
      cout<<strPair[i].first<<endl;
  }
  return 0;
}
