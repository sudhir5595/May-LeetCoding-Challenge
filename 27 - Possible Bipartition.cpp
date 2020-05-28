class Solution {
public:    
    bool isBipertite(vector < vector <int> > &graph, int src, vector <int> &visited){
        // Create a color array to store colors  
        // assigned to all veritces. Vertex  
        // number is used as index in this array.  
        // The value '-1' of colorArr[i]  
        // is used to indicate that no color  
        // is assigned to vertex 'i'. The value 1  
        // is used to indicate first color  
        // is assigned and value 0 indicates  
        // second color is assigned. 
        
        vector <int> color(graph.size());
            
        for(int i = 0; i<color.size(); i++){
            color[i] = -1;
        }
        // Assign first color to source 
        color[src] = 1;
        
        queue <int> q;
        q.push(src);
        
        while(!q.empty()){
            
            int temp = q.front();
            visited[temp] = 1;
            q.pop();
            // Return false if there is a self-loop , not possible in this problem
            if(graph[temp][temp] == 1){
                return false;
            }
            // Find all non-colored adjacent vertices 
            for(int i = 0; i<graph.size(); i++){
                // An edge from u to v exists and destination v is not colored
                if(graph[temp][i] && color[i] == -1){
                    // Assign alternate color to this adjacent v of u
                    color[i] = 1 - color[temp];
                    q.push(i);
                }
        // An edge from u to v exists and destination v is colored with same color as u 
                else if(graph[temp][i] && color[i] == color[temp]){
                    return false;
                }        
            }
        }
        
        return true;
    }
    
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector < vector <int> > graph(N+1, vector <int> (N+1, 0));
        for(int i = 0; i < dislikes.size(); i++){
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            graph[u][v] = 1;
            graph[v][u] = 1;
        }
        int res = 0;
        int src = 0;
        vector <int> visited(N+1,0);
        visited[0] = 1;
        res = isBipertite(graph, 1, visited);
        if(res == 1){
            for(int i = 0; i<=N; i++){
                if(visited[i] == 0){
                 res = isBipertite(graph, i, visited);
                }
                if(res == 0){
                    return 0;
                }
            }
        }
        return res;
    }
};
