/**
 * 我本来想的是,先冒泡排序找到这组字符串里面最小长度的两个字符串,然后再比较找到这两个字符串的公共前缀。
 *
 * 简单的方法是,两层循环,
 *  外层循环,对于第一个字符串,的每一个字符进行循环
 *  内层循环,对比之后所有的字符串对应的字符,如果都和第一个相同,则将公共前缀加上,若不是,则返回。
 * 此外要考虑如果strs为空的情况,为长度为1的情况。
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if(strs.size() == 0) return prefix;
        // if(strs.size() == 1) return strs[0];

        for(int i = 0; i < strs[0].length(); i++) {
            int j =1;
            for(;j < strs.size() && i< strs[j].length();j++) {
                if(strs[0][i]!=strs[j][i]){
                    return prefix;
                }
            }
            if(j==strs.size()) prefix = prefix + strs[0][i];
        }
        return prefix;
    }
};