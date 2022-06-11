#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'getBatonTransition' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY transitions
 *  2. STRING_ARRAY queries
 */
vector<string> split(string s){
    vector<string> ans;
    string temp="";
    for(int i=0;i<s.length();i++){
        if(s[i]!='-'){
            temp+=s[i];
        }
        else{
            ans.push_back(temp);
            temp="";
        }
    }
    ans.push_back(temp);
    return ans;
}
int findVert(vector<pair<string,vector<string>>> adj,string s){
    for(int i=0;i<adj.size();i++){
        if(adj[i].first==s){
            return i;
        }
    }
    return -1;
}
vector<string> getBatonTransition(vector<string> transitions, vector<string> queries) {
    vector<pair<string,vector<string>>> adjList;
    for(int i=0;i<transitions.size();i++){
        vector<string> tran=split(transitions[i]);
        string from=tran[0],to=tran[1];
        int idx1=findVert(adjList,to),idx2=findVert(adjList,from);
        if(idx1==-1){
            vector<string> temp;
            adjList.push_back({to,temp});
        }
        else{
            adjList[idx1].second.push_back(from);
        }
        if(idx2==-1){
            vector<string> temp;
            adjList.push_back({from,temp});
        }
        else{
            adjList[idx1].second.push_back(to);
        }
    }
    
    vector<string> ans;
    int v=adjList.size();
    for(int i=0;i<queries.size();i++){
        vector<string> q=split(queries[i]);
        string source=q[0],dest=q[1];
        priority_queue<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int dist[v];
        bool sptSet[v];
        
        for(int i=0;i<v;i++){
            dist[i]=INT_MAX;
            sptSet[i]=false;
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string transitions_count_temp;
    getline(cin, transitions_count_temp);

    int transitions_count = stoi(ltrim(rtrim(transitions_count_temp)));

    vector<string> transitions(transitions_count);

    for (int i = 0; i < transitions_count; i++) {
        string transitions_item;
        getline(cin, transitions_item);

        transitions[i] = transitions_item;
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    vector<string> result = getBatonTransition(transitions, queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
