class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        int start = 0;
        int end = nums.size()-1;
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums[0] != nums[1]){
            return nums[0];
        }
        if(nums[nums.size()-1] != nums[nums.size()-2]){
            return nums[nums.size()-1];
        }
        int mid = 0;
        while(start <= end){
            mid = start + (end - start)/2;
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]){
                return nums[mid];
            }
            else if(nums[mid] == nums[mid - 1] && (mid-start)%2 == 0){
                end = mid;
            }
            else if(nums[mid] == nums[mid - 1] && (mid-start)%2 == 1){
                start = mid+1;
            }
            else if(nums[mid] != nums[mid - 1] && (mid-start)%2 == 0){
                start = mid;
            }
            else if(nums[mid] != nums[mid - 1] && (mid-start)%2 == 1){
                end = mid-1;
            }
        }
        return -1;
    }
};
