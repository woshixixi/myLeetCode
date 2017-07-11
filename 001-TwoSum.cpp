//my solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int first = 0,second = 1;
        vector<int> result;
        for(;first<nums.size();first++) {
            for(second = first + 1;second < nums.size();second++){
                if(nums[first] + nums[second] == target) {
                    result.push_back(first);
                    result.push_back(second);
                    return result;
                }
            }
        }
		return result;
    }
};

//O(n) Solution
//思路：增加空间复杂度，使用unordered_map其中key值为每个元素的补数，value为对应的第几个元素。将遍历的每个元素的值先查找map中存在不，不存在就将补数放入，存在就找到了
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hash;
		vector<int> result;
		for(int i = 0;i < nums.size();i++) {
			int numberToFind = target - nums[i];
			//如果找到了
			if(hash.find(numberToFind) != hash.end()) {
				result.push_back(hash[numberToFind] + 1);
				result.push_back(i + 1);
				return result;
			}
			//如果找不到，将补数放入hash中
			hash[nums[i]] = i;
			
		}
		return result;
	}
};



