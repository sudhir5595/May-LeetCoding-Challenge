class Solution {
public:
    int count_one(int n){
        int res = 0;
        if(n == 0){
            return 0;
        }
        while(n > 0){
            if(n%2 == 1){
                res++;
            }
            n = n/2;
        }
        return res;
    }
    
    
    vector<int> countBits(int num) {
        vector<int> result;
        for(int i = 0; i<=num; i++){
            result.push_back(count_one(i));
        }
        return result;
    }
};
