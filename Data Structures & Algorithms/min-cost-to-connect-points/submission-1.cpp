class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size(); //number of edges
        vector<bool> mst(n, false);
        vector<int> dist(n, INT_MAX);

        int ans=0;
        int edges=0;
        dist[0]=0;
        while(edges<n){
            int curr_node=-1;
            int curr_dist=INT_MAX;

            for(int i=0; i<n ; i++){
                if(!mst[i] && dist[i]<curr_dist){
                    curr_node=i;
                    curr_dist=dist[i];
                }
            }
            ans=ans+curr_dist;
            mst[curr_node]=true;
            edges++;

            for(int i=0; i<n; i++){
                if(!mst[i]) dist[i]= min(dist[i], abs(points[curr_node][0]-points[i][0]) + abs(points[curr_node][1]-points[i][1]));

            }

        }
        return ans;
    }
};
