/**
 *
 * 根据上一题的思路,这题目更加简单
 * 每次遇到相同的,进行计数,不同的则为当前遍历的减去相同的个数
 *
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        int i = 0;
        for(;i < nums.size(); i++) {
            if(nums[i] == val) {
                count ++;
            }else {
                nums[i - count] = nums[i];
            }
        }
        return i - count;
    }
};