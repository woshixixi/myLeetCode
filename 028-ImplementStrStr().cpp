/**
 *
 * 找匹配字符串,两种解法,一种普通解法,一种KMP算法
 * 1 普通解法,如下,可以优化的一点是 可以外层循环少走一些,减去要匹配的子串长度
 * 2 KMP算法
 *   KMP算法的主要思想是找出要匹配串的自身结构优势,使得已经匹配了的长度内,下次再匹配就直接跳过不必要的匹配。因此分为两步:
 *   a> 根据匹配字符串,计算next数组,数组为最长前缀和后缀
 *   b> 根据next数组,决定当匹配k个长度后,当前滑动为s,则下次滑动为 s'=s+next[k]
 */


// 1 普通解法

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hayLength = haystack.length(), needleLength = needle.length();
        int i = 0 , j = 0;
        for(;i < hayLength - needleLength + 1 ; i++) {
            for(j = 0; j < needleLength ; j++) {
                if( haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if(j == needleLength) return i;
        }
        return -1;

    }
};

// 2 KMP
