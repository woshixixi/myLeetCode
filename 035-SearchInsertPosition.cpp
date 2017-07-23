/**
 *
 * 最初的想法:直接就是O(n)
 * 还可以用:二分法,O(nlgn)
 *
 */

//O(n)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i =0;i<nums.size();i++) {
            if(target<=nums[i]) return i;
        }
        return nums.size();
    }

};

//O(nlgn)

