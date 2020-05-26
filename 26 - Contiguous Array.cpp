class Solution {
public:
    int findMaxLength(vector<int>& input) {
        unordered_map<int, int> hash;
        int zeroCount = 0;
        int maxWindow = 0;
	for(int i=0; i<input.size(); i++){
		if(input[i]==0){
			zeroCount++;
        }
		if(zeroCount-(i-zeroCount+1)==0){
			maxWindow = max(maxWindow, i+1);
        }
        // cout<<"diff "<<zeroCount-(i-zeroCount+1)<<endl;
		if(hash.find(zeroCount-(i-zeroCount+1))!=hash.end()){
			// cout<<"present "<<input[i]<<endl;
			maxWindow = max(maxWindow, i-hash[zeroCount-(i-zeroCount+1)]);
        }
        else{
        // cout<<"absent "<<input[i]<<endl;
            hash[zeroCount-(i-zeroCount+1)] = i;
        }
    }
        
    return maxWindow;
}

};
