class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int first=0,second=1;
        vector<int> result;
        for(;first<nums.size();first++){
            for(second=first+1;second<nums.size();second++){
                if(nums[first]+nums[second]==target){
                    result.push_back(first);
                    result.push_back(second);
                    return result;
                }
            }
        }

    }
};