class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int sum = 0;
        int max_sum1 = INT_MIN;
        int max_sum2 = INT_MIN;
        int start = 0;
        int end = 0;
        int n = A.size();
        for(int i = 0; i<n; i++){
            sum += A[i];
            if(sum > max_sum1){
                max_sum1 = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        
        int sum1 = 0;
        for(int i = 0; i<n; i++){
         sum1 += A[i];   
        }
        sum = 0;
        for(int i = 0; i<n; i++){
            sum += -A[i];
            if(sum > max_sum2){
                max_sum2 = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        if(max_sum2 == -sum1){
            return max_sum1;
        }
        return max(max_sum1, sum1 + max_sum2);
    }
};
