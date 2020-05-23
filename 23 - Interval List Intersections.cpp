class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int ptr1 = 0;
        int ptr2 = 0;
        while(ptr1 < A.size() && ptr2 < B.size()){
            vector <int> a = A[ptr1];
            vector <int> b = B[ptr2];
            int l = max(a[0],b[0]);
            int r = min(a[1],b[1]);
            if(l <= r){
                res.push_back({l,r});
            }
            if(a[1] > b[1]){
                ptr2++;
            }
            else{
                ptr1++;
            }
        }
        return res;
    }
};
