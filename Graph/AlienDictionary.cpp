#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string findOrder(string words[], int N, int K) {
        vector<vector<int>> adj(26);
        vector<int> inDegree(26,-1);
        for(int i=0;i<N;i++){
            string s=words[i];
            int n=s.length();
            for(int j=0;j<n;j++){
                inDegree[s[j]-'a']=0;
            }
        }
        for(int i=0;i<N-1;i++){
            string s=words[i],t=words[i+1];
            int n=s.length(),m=t.length();
            int p1=0,p2=0;
            while(p1<n && p2<m){
                if(s[p1]!=t[p2]){
                    adj[s[p1]-'a'].push_back(t[p2]-'a');
                    inDegree[t[p2]-'a']++;
                    break;
                }
                p1++;
                p2++;
            }
            if(p2==m && p1<n){
                return "";
            }
        }
        queue<int> q;
        for(int i=0;i<26;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        string ans="";
        while(!q.empty()){
            int node=q.front();
            char c='a'+node;
            ans+=c;
            q.pop();
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
