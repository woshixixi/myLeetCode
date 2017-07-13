/**
 * 罗马数字规则:
 * 1 I(1) V(5) X(10) L(50) C(100) D(500) M(1000)
 * 2 相同的数字连写，所表示的数等于这些数字相加得到的数
 * 3 小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数
 * 4 小的数字（限于 Ⅰ、X 和 C）在大的数字的左边，所表示的数等于大数减小数得到的数
 */
class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        unordered_map<char, int>hash = { {'I', 1},
                                         {'V',5},
                                         {'X',10},
                                         {'L',50},
                                         {'C',100},
                                         {'D',500},
                                         {'M',1000} };
        for(int i = 0; i <= s.length() - 1; i++){
            if(hash[s[i]] < hash[s[i+1]]){
                sum = sum - hash[s[i]];
            }else{
                sum = sum + hash[s[i]];
            }
        }
        return sum;
    }
};