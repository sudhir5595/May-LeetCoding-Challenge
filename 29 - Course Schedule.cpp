class Solution {
public:
    
    bool cycle_find(vector < vector <int> > &graph, int numCourses){
        
        // Create a vector to store indegrees of all 
    // vertices. Initialize all indegrees as 0.
        
        vector <int> in_degree(numCourses,0);
        
        for(int i = 0; i<numCourses; i++){
            for(int j = 0; j<graph[i].size(); j++){
                in_degree[graph[i][j]]++;
            }
        }
        
        // Create an queue and enqueue all vertices with indegree 0
        queue <int> q;
        for(int i = 0; i<numCourses; i++){
            if(in_degree[i] == 0){
                q.push(i);
            }
        }
        
        // Initialize count of visited vertices 
        int cnt = 0; 
        
        // Create a vector to store result (A topological ordering of the vertices) 
        vector<int> top_order; 
        
        while(!q.empty()){
            int temp = q.front();
            top_order.push_back(temp);
            q.pop();
            
            for(int i = 0; i<graph[temp].size(); i++){
                in_degree[graph[temp][i]]--;
                if(in_degree[graph[temp][i]] == 0){
                    q.push(graph[temp][i]);
                }
            }
            cnt++;
        }
        
        if(cnt != numCourses){
            return 0;
        }
        return 1;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector < vector <int> > graph(numCourses);
        int n = prerequisites.size();
        
        for(int i = 0; i<n; i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        return cycle_find(graph,numCourses);
    }
};
