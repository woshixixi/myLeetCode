/**
 *
 * 最初的想法:直接就是O(n)
 * 还可以用:二分法,O(logn)
 * 二分法要注意，low<=high 为截止条件，同时，每次low=mid+1，high=mid-1
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

//O(logn)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0,high = nums.size() - 1,mid;
        while(low <= high) {
            mid =(high + low)/2;
            if(nums[mid] == target) return mid;
            if(target > nums[mid]) {
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        if(nums[mid] > target)return mid;
        else return mid + 1;
            
    }
    
};

