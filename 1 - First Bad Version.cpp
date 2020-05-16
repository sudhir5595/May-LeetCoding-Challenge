// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long first = 1;
        long long last = n;
        if(isBadVersion(1) == true){
            return 1;
        }
        while(first <= last){
            long long mid = (first + last)/2;
            if(isBadVersion(mid) == false && isBadVersion(mid + 1) == true){
                return mid + 1;
            }
            else if(isBadVersion(mid) == true){
                last = mid - 1;
            }
            else{
                first = mid + 1;
            }
        }
        return last;
    }
};
