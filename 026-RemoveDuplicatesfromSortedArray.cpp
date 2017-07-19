/**
 *
 * 不需要考虑太多,只要遇到不同的计数,同时将前面数第几个改为该数就行了。
 *
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 1)return 0;
        int count = 1;
        for(int i = 1;i < nums.size(); i++ ) {
            if(nums[i] != nums[i - 1]) {
                count++;
                nums[count - 1] = nums [i];
            }
        }
        return count;
    }
};
