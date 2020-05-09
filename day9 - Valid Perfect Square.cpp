class Solution {
public:
    bool isPerfectSquare(int num) {
        int start = 0;
        int end = num;
        while(start <= end){
            long long mid = (end + start)/2;
            if(mid*mid == num){
                return 1;
            }
            else if(mid*mid > num){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return 0;
    }
};
