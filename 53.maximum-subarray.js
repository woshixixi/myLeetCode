/*
 * @lc app=leetcode id=53 lang=javascript
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (42.92%)
 * Total Accepted:    475.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * Example:
 *
 *
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 *
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 *
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
  let maxSum = Number.MIN_SAFE_INTEGER
  let currentMax = 0
  for (let i = 0; i < nums.length; i++) {
    // if sum<0 use new one, else add to it
    if (currentMax <= 0) {
      currentMax = nums[i]
    } else {
      currentMax = currentMax + nums[i]
    }

    if (maxSum < currentMax) {
      maxSum = currentMax
    }
  }

  return maxSum
}
