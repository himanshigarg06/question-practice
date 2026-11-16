class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        return dfs(source, destination, adj, visited);
    }

    bool dfs(int node, int destination, vector<vector<int>>& adj, vector<bool>& visited)
    {
        if(node == destination)
            return true;

        visited[node] = true;

        for(int i = 0; i < adj[node].size(); i++)
        {
            int neighbour = adj[node][i];

            if(!visited[neighbour])
            {
                if(dfs(neighbour, destination, adj, visited))
                    return true;
            }
        }

        return false;
    }
};