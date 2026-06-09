class Solution {
public:
    void dfs(int i, vector<bool>&vis, vector<vector<int>>& adj){
        vis[i]=true;
        for(int neighbour : adj[i]){
            if(!vis[neighbour]) dfs(neighbour, vis, adj);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);
        int count=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, adj);
                count++;
            }
        }
        return count;
    }
};
