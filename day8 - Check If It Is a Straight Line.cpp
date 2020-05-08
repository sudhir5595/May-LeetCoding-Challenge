class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int res = 0;
        int n = coordinates.size();
        float slope = 0;
        int x = coordinates[1][0] - coordinates[0][0];
        int y = coordinates[1][1] - coordinates[0][1];
        if(x == 0){
            for(int i = 0; i<n-1; i++){
                if((coordinates[i+1][0] - coordinates[i][0]) != 0){
                    return 0;
                }
            }
            return 1;
        }
        slope = (float(y)/float(x));
        for(int i = 0; i<n-1; i++){
            x = coordinates[i+1][0] - coordinates[i][0];
            y = coordinates[i+1][1] - coordinates[i][1];
            float temp = float(float(y)/float(x));
            if(slope != temp){
                return 0;
            }
        }
        return 1;
    }
};
