class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char, int> mp;
        for(int i = 0; i<s.size(); i++){
            mp[s[i]]++;
        }
        vector < pair <int, char> > char_count;
        for(auto it = mp.begin(); it != mp.end(); it++){
            char_count.push_back({it->second, it->first});
        }
        sort(char_count.begin(), char_count.end());
        reverse(char_count.begin(), char_count.end());
        string res;
        for(int i = 0; i<char_count.size(); i++){
            for(int j = 0; j<char_count[i].first; j++){
                res += char_count[i].second;
            }
        }
        return res;
    }
};
