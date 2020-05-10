class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector <bool> check(N);
        vector <int> count(N,0);
        for(int i = 0;i<trust.size(); i++){
            int temp = trust[i][0] - 1;
            int temp1 = trust[i][1] - 1;
            check[temp] = true;
            count[temp1] += 1;
        }
        for(int i = 0; i<N; i++){
            if(check[i] == false && count[i] == N-1){
                return i+1;
            }
        }
        return -1;
    }
};
