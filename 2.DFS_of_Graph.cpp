class Solution {
private:
    void dfs(int node ,vector<int> adj[]  ,int vis[] , vector<int>&ds){
        vis[node] = 1;
        ds.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it , adj , vis , ds);
            }
        }
    }
public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int start = 0;
        vector<int> ds;
        dfs(start , adj , vis , ds);
        return ds;
    }
};
