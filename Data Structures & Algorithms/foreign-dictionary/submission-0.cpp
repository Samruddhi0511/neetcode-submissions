class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        for(const string &s : words){
            for (char c : s){
                indegree[c]=0;
            }
        }

        for(int i=0; i<words.size()-1; i++){
            string w1=words[i];
            string w2=words[i+1];

            if(w1.size()>w2.size() && w1.compare(0, w2.size(), w2)==0) return "";

            int len=min(w1.size(), w2.size());
            for(int j=0; j<len; j++){
                if(w1[j]!=w2[j]){
                    char u=w1[j];
                    char v=w2[j];
                    if(!adj[u].count(v)){
                        adj[u].insert(v);
                        indegree[v]++;

                    }

                    break;
                }
            }
        }

            queue<char> q;
            for(auto const& [ch, degree] : indegree){
                if(degree==0) q.push(ch);
            }

            string result="";

            while(!q.empty()){
                char curr=q.front();
                q.pop();
                result+=curr;

                for(char neighbour : adj[curr]){
                    indegree[neighbour]--;
                    if(indegree[neighbour]==0) q.push(neighbour);
                }
            }

            if (result.size() < indegree.size()) {
            return "";
        }
        return result;
    }
};
