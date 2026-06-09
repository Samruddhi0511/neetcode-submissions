class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);

        for(int i=0; i<prerequisites.size(); i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> temp;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            temp.push_back(curr);

            for(int neighbour : adj[curr]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0) q.push(neighbour);
            }
        }

        vector<int> temp3;
        if(temp.size()==numCourses) return temp;
        return temp3;
    }
};
