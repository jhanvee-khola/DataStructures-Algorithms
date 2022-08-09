//Given two strings A and B, the task is to convert A to B if possible. The only operation allowed is to put any character from A and insert it at front. 
//Find if it’s possible to convert the string. If yes, then output minimum no. of operations required for transformation.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int transfigure (string a, string b){
    	if(a.length()!=b.length()){
    	    return -1;
    	}
    	//check if all same characters
    	unordered_map<char,int> mp;
    	for(int i=0;i<a.length();i++){
    	    mp[a[i]]++;
    	    mp[b[i]]--;
    	}
    	for(auto i:mp){
    	    if(i.second!=0){
    	        return -1;
    	    }
    	}
    	int i=a.length()-1,j=b.length()-1;
    	int ans=0;
    	while(i>=0){
    	    if(a[i]==b[j]){
    	        j--;
    	    }
    	    else{
    	        ans++;
    	    }
    	    i--;
    	}
    	return ans;
    }
};
