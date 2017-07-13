/**
 * 空间复杂度O(1),时间复杂度为O(lgn)的解题思路:
 * 1 可以直接根据007题的来进行转化,即为将原数倒置,看是否和原数相同
 * 2 但要注意几点:
 *      a> 可直接排除负数,和最后为0的数
 *      b> 不需要考虑中间过程中的因为如果是回文整数,那么中间就不应该出现溢出的情况
 */

class Solution {
public:
    bool isPalindrome(int x) {
        int temp = 0;
        if(x == 0)return true;
        else if(x < 0 || x % 10 == 0) return false;
        else {
            int xr = x;
            while(x) {
                temp = x % 10 + temp * 10;
                x = x / 10;
            }
            if(temp == xr) return true;
            else return false;
        }
    }
};