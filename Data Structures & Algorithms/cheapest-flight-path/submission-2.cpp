class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);

        for(const auto& flight : flights){
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        // FIX 1: Renamed vector from 'stops' to 'dist' to avoid variable name clashing
        vector<int> dist(n, INT_MAX);
        queue<pair<int, int>> pq; // Using standard queue for level-order BFS
        pq.push({src, 0});
        dist[src] = 0;
        
        int current_stops = 0; // Tracks the level/number of flights taken

        while(!pq.empty() && current_stops <= k){
            int s = pq.size();

            for(int i = 0; i < s; i++){
                // FIX 2: Changed .top() to .front() because this is a standard queue now
                auto curr = pq.front();
                pq.pop();

                int node = curr.first;
                int cost = curr.second;

                for(const auto& neighbour : graph[node]){
                    int v = neighbour.first;
                    int price = neighbour.second;
                    
                    // Update if we find a cheaper way to reach node 'v' at this level
                    if(cost + price < dist[v]){
                        pq.push({v, cost + price});
                        dist[v] = cost + price;
                    }
                }
            }
            current_stops++; // FIX 3: Added missing semicolon
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};