class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i<m; i++){
            if(matrix[i][0] == 1){
                res += 1;
            }
        }
        for(int i = 0; i<n; i++){
            if(matrix[0][i] == 1){
                res += 1;
            }
        }
        res -= matrix[0][0];
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                if(matrix[i][j] == 1){
                    matrix[i][j] = 1 + min(matrix[i][j-1],min(matrix[i-1][j],matrix[i-1][j-1]));
                }
                res += matrix[i][j];
            }
        }
        return res;
    }
};
