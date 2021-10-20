// Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures? 
bool isUnique(string s){
    for(int i=0;i<s.length();i++){
        if((s.find(s[i],i+1))!=string::npos){
            return false;
        }
    }
    return true;
}
