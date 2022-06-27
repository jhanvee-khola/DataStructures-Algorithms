//Write a method to replace all spaces in a string with '%20' in place. 
//You may assume that the string has sufficient space at the end to hold the additional characters and that you are given the "true" length of the string
void urlify(string s,int n){
  int i=n-1,j=s.length()-1;
  while(i>=0){
    if(s[i]!=' '){
      s[j]=s[i];
      j--;
    }
    else{
      s[j--]='0';
      s[j--]='2';
      s[j--]='%';
    }
    i--;
  }
}
