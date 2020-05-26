class Solution {
public:
    
    int solve(vector <int> &A, vector <int> &B, int a, int b, vector <  vector <int> > &dp){
        if(a >= A.size() || b >= B.size()){
            return 0;
        }
        
        if(dp[a][b] != INT_MIN){
            return dp[a][b];
        }
        
        int max_res = 0;
        int b1 = b;
        int temp = 0;
        
        while(b1 < B.size() && A[a] != B[b1]){
            b1++;
        }
        
        if(b1 < B.size()){
            temp = 1;
        }
        
        max_res = solve(A, B, a + 1, b, dp);
        max_res = max(max_res, solve(A, B, a + 1, b1 + 1, dp) + temp);
        
        return dp[a][b] = max_res;
    }
    
    
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        
        int max_ans = 0;
        vector <  vector <int> > dp(A.size(), vector <int> (B.size(), INT_MIN));
        max_ans = solve(A, B, 0, 0, dp);
        
        return max_ans;
    }
};
