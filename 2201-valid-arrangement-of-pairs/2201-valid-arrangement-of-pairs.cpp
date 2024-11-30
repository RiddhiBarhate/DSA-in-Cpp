class Solution {
public:
    // Adjacency list
    unordered_map<int, vector<int>> adj;

    // Vector to store the Eulerian path
    vector<int> eulerPath;

    // Recursive DFS function to find the Eulerian path
    void dfs(int node) {
        while (!adj[node].empty()) {
            int nextNode = adj[node].back();
            adj[node].pop_back();  // Remove the edge after visiting
            dfs(nextNode);         // Recursive DFS call
        }
        eulerPath.push_back(node);  // Add node to Euler path after all edges are visited
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // Step-1: Build adjacency list and calculate in-degree & out-degree
        unordered_map<int, int> indegree, outdegree;

        for (auto& edge : pairs) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);  // u --> v
            outdegree[u]++;
            indegree[v]++;
        }

        // Step-2: Find the start node of the Eulerian path
        int startNode = pairs[0][0];  // default start node
        for (auto& it : adj) {
            int node = it.first;
            if (outdegree[node] - indegree[node] == 1) {
                startNode = node;  // Node with outdegree > indegree by 1
                break;
            }
        }

        // Step-3: Perform DFS from the start node to find the Eulerian path
        dfs(startNode);

        // Step-4: Build the result from the Eulerian path
        reverse(eulerPath.begin(), eulerPath.end());
        vector<vector<int>> result;
        for (int i = 0; i < eulerPath.size() - 1; i++) {
            result.push_back({eulerPath[i], eulerPath[i + 1]});
        }

        return result;
    }
};