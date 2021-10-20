#include<bits/stdc++.h>
using namespace std;

char* token(char* str, char delim){
  static char* input=NULL;
  
  if(str!=NULL){
    input=str;
  }
  
  if(input==NULL){
    return NULL;
  }
  char* output= new char[strlen(input)+1]
  int i=0;
  for(;input[i]!='\0';i++){
    if(input[i]!=delim){
      output[i]=input[i];
    }
    else{
      output[i]='\0';
      input=input+i+1;
      return output;
    }
  }
  output[i]='\0';
  input=NULL:
  return output;
}

int main(){
  char s[];
  cin.getline(s,100);
  
  char* ptr=token(s,' ');
  cout<<ptr<<endl;
  while(ptr!=NULL){
    ptr=token(NULL,' ');
    cout<<ptr<<endl;
  }
  return 0;
}
