class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        unordered_set <char> st;
        
        for(int i = 0; i<J.size(); i++){
            st.insert(J[i]);
        }
        for(int i = 0; i<S.size(); i++){
            if(st.find(S[i]) != st.end()){
               res++; 
            }
        }
        return res;
    }
};
