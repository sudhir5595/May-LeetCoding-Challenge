class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string s;
        s.push_back('0');
        if(num.size() == k){
            return s;
        }
        if(k == 0){
            return num;
        }
        int cond = 0;
        for(int i = 0; i<k; i++){
            cond = 0;
            for(int j = 0; j<num.size() - 1; j++){
                if(num[j]  > num[j+1]){
                    num.erase(num.begin() + j);
                    cond = 1;
                    break;
                }    
            }
            if(cond == 0){
                num.erase(num.begin() + num.size()-1);
            }
        }
        while(num[0] == '0' && num.size() > 1){
            num.erase(num.begin() + 0);
        }
        return num;
    }
};
