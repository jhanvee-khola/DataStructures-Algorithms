//Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  
//Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index. 

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string smallestWindow (string s, string p){
        if(s.length()<p.length()){
            return "-1";
        }
        unordered_map<char,int> pmp;
        for(int i=0;i<p.length();i++){
            pmp[p[i]]++;
        }
        unordered_map<char,int> smp;
        int start=0,match=0,ans=INT_MAX,ind;
        for(int end=0;end<s.length();end++){
            smp[s[end]]++;
            if(pmp[s[end]]>=smp[s[end]]){
                match++;
            }
            if(match==p.length()){
                while(match==p.length()){
                    if(end-start+1<ans){
                        ans=end-start+1;
                        ind=start;
                    }
                    smp[s[start]]--;
                    if(pmp[s[start]]>smp[s[start]]){
                        match--;
                    }
                    start++;
                }
            }
        }
        if(ans==INT_MAX){
            return "-1";
        }
        return s.substr(ind,ans);
        
    }
};
