class Solution {
public:
    
    int inside(int sr, int sc, vector<vector<int>>& image){
        if(sr >= 0 && sc >= 0 && sr <= image.size()-1 && sc <= image[0].size()){
            return true;
        }
        return false;
    }
    
    void BFS(int sr, int sc, vector<vector<int>>& image, int original_color, int newColor){
        queue < pair <int , int> > q;
        q.push(make_pair(sr,sc));
        image[sr][sc] = newColor;
        
        while(!q.empty()){
            pair <int, int> temp;
            temp = q.front();
            q.pop();
            if(inside(temp.first+1, temp.second, image) && image[temp.first+1][temp.second] == original_color){
                q.push({temp.first + 1,temp.second});
                image[temp.first+1][temp.second] = newColor;
            }
            
            if(inside(temp.first-1, temp.second, image) && image[temp.first-1][temp.second] == original_color){
                q.push({temp.first - 1,temp.second});
                image[temp.first-1][temp.second] = newColor;
            }
            
            if(inside(temp.first, temp.second+1, image) && image[temp.first][temp.second+1] == original_color){
                q.push({temp.first,temp.second+1});
                image[temp.first][temp.second+1] = newColor;
            }
            
            if(inside(temp.first, temp.second-1, image) && image[temp.first][temp.second-1] == original_color){
                q.push({temp.first,temp.second-1});
                image[temp.first][temp.second-1] = newColor;
            }
        }
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int original_color = image[sr][sc];
        if(original_color == newColor){
            return image;
        }
        BFS(sr, sc, image, original_color, newColor);
        return image;
    }
};
