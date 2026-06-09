class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(int i=0 ; i<prerequisites.size(); i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int>q;
        for(int i=0; i<numCourses; i++){
            if (indegree[i]==0) q.push(i);
        }
        int completed=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            completed++;
            for(int neighbour : adj[curr]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0) q.push(neighbour);
            }
        }
        return completed==numCourses;

    }
};
