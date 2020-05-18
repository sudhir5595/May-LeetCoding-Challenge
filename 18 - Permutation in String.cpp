class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map <char, int> mp;
        int counter = s1.size();
        int left = 0;
        for(int i = 0; i<s1.size(); i++){
            mp[s1[i]]++;
        }
        for(int i = 0; i<s2.size(); i++){
            if(mp.find(s2[i]) != mp.end() && mp[s2[i]]){
                counter--;
                mp[s2[i]]--;
                if(counter == 0){
                    return 1;
                }
            }
            else{
                while(left < i){
                    if(mp.find(s2[left]) != mp.end()){
                        mp[s2[left]]++;
                        counter++;
                    }
                    left++;
                    if(mp.find(s2[i]) != mp.end() && mp[s2[i]]){
                        i--;
                        break;
                    }
                } 
            }
            if(mp.find(s2[i]) == mp.end()){
                left++;
            }
        }
        return 0;
    }
};
