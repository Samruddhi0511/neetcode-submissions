class Solution {
public:
    bool dfs(int node, int parent, vector<bool>&vis, vector<vector<int>> &adj){
        vis[node]=true;

        for(int neighbour : adj[node]){
            if(!vis[neighbour]){
                if(dfs(neighbour, node, vis, adj)) return true;
            }
            else if(neighbour!=parent) return true;
        }

        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);

        if(dfs(0, -1, vis, adj)) return false;
        for (bool nodeVisited : vis) {
            if (!nodeVisited) return false;}
        return true;
    }
};
