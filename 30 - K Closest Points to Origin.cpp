class Solution {
public:
    
  
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        vector<vector<int>> res;
        vector < pair <long long, long long> > buffer;
        
        for(int i = 0; i<points.size(); i++){
            buffer.push_back({points[i][0]*points[i][0] + points[i][1]*points[i][1], i});
        }
        
        sort(buffer.begin(), buffer.end());
        
        for(int i = 0; i<K; i++){
            pair <long long, long long> temp;
            temp = buffer[i];
            res.push_back(points[temp.second]);
        }
            
        return res;
    }
};
