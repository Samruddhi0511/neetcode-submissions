class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int total_cost=0;
        int edges_connected=0;

        vector<bool> mst(n, false);
        vector<int> dist(n, INT_MAX);

        dist[0]=0;

        while(edges_connected<n){
            int curr_node=-1;
            int curr_min=INT_MAX;

            for(int i=0; i<n; i++){
                if(!mst[i] && dist[i]<curr_min){
                    curr_min=dist[i];
                    curr_node=i;
                }
            }
            total_cost=total_cost+curr_min;
            mst[curr_node]=true;
            edges_connected++;

            for(int next_node=0; next_node<n; next_node++){
                if(!mst[next_node]){
                    int distance= abs(points[curr_node][0] - points[next_node][0]) + abs(points[curr_node][1]-points[next_node][1]);

                    if(distance< dist[next_node]) dist[next_node]=distance;
                }
            }
        }

        return total_cost;
    }
};
