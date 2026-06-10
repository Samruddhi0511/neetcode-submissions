class Solution {
    class DSU {
        vector<int> parent;
        vector<int> rank;

    public:
        DSU(int n) {
            parent.resize(n + 1);
            rank.resize(n + 1);

            for (int i = 1; i <= n; i++) {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        int findParent(int node) {
            if (parent[node] != node) {
                parent[node] = findParent(parent[node]);
            }
            return parent[node];
        }

        bool Union(int node1, int node2) {
            int root1 = findParent(node1);
            int root2 = findParent(node2);

            if (root1 == root2)
                return false;

            if (rank[root1] > rank[root2]) {
                parent[root2] = root1;
            }
            else if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            }
            else {
                parent[root2] = root1;
                rank[root1]++;
            }

            return true;
        }
    };

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DSU dsu(n);

        for (auto& edge : edges) {
            if (!dsu.Union(edge[0], edge[1]))
                return edge;
        }

        return {};
    }
};