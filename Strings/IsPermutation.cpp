//Given two strings, write a method to decide if one is a permutation of the other
bool isPermutation(string s,string t){
    if(s.length()!=t.length()){
        return false;
    }
    for(int i=0;i<s.length();i++){
        if((t.find(s[i]))==string::npos){
            return false;
        }
    }
    return true;
}
