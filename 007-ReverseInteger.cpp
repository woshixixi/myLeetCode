/*
 * 要考虑以下几点
 * 1、在使用反转方法上,不要每一位都写出来,可以边算边加结果 即为:
 *    result = x % 10 + result * 10
 * 2、因此可能会在中间的计算过程中,超过了int类型的最大值和最小值,最后还要转换成int类型,因此有两种思路
 *    a>使用long long 类型保存结果,最后要转换为int类型的时候判断大小
 *    b>中间结果每次都判断是否还为int,如果不是,则就直接return为0
 * 3、有此避免了比如1534236469这样的数最后结果变成1056389759的错误。
 */

//a>使用long long 类型保存结果,最后要转换为int类型的时候判断大小
class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        while(x) {
            result = x % 10 + result * 10;
            x = x / 10;
        }
        if(result < INT_MIN || result > INT_MAX){
            return 0;
        }else {
            return result;
        }
    }
};

//b>中间结果每次都判断是否还为int,如果不是,则就直接return为0
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while(x) {
            int temp = x % 10 + result *10;
            if(temp / 10 != result){
                return 0;
            }
            result = temp;
            x = x / 10;
        }
        return result;
    }
};