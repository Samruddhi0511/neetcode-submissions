class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(int i=0; i<times.size(); i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];

            adj[u].push_back({v,w});
        }

        vector<int> dist(n+1,INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto [d, node]=pq.top();
            pq.pop();

            if(d>dist[node]){continue;}
            for(auto &[nbr, wt] : adj[node]){
                if(dist[nbr]> dist[node]+wt){
                    dist[nbr]=dist[node]+wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        int ans=0;
        for(int i=1; i<dist.size(); i++){
            if(dist[i]==INT_MAX){
                ans=-1;
                break;
            }
            ans=max(ans, dist[i]);
        }
        return ans;

    }
};
