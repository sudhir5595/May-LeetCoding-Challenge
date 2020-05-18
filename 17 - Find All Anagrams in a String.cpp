class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map <char , int> mp;
        for(int i = 0; i<p.size(); i++){
            mp[p[i]]++;
        }
        int counter = p.size();
        int left = 0;
        for(int i = 0; i<s.size(); i++){
            if(mp.find(s[i]) != mp.end() && mp[s[i]]){
                    mp[s[i]]--;
                    counter--;
                if(counter == 0){
                    res.push_back(left);
                }
            }
            else{
                while(left < i){
                    if(mp.find(s[left]) != mp.end()){
                        counter++;
                        mp[s[left]]++;
                    }
                    left++;
                    if(mp.find(s[i]) != mp.end() && mp[s[i]]){
                            i--;
                            break;
                    }
                }
                if(mp.find(s[left]) == mp.end()){
                    left = i + 1;
                }
            }
        }
        
        return res;
    }
};
