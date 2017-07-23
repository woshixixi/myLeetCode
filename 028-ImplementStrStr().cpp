/**
 *
 * 找匹配字符串,两种解法,一种普通解法,一种KMP算法
 * 1 普通解法,如下,可以优化的一点是 可以外层循环少走一些,减去要匹配的子串长度
 * 2 KMP算法【O(m+n)】
 * 		可参看博客 http://www.cnblogs.com/tangzhengyue/p/4315393.html
 *   KMP算法的主要思想是找出要匹配串的自身结构优势,使得已经匹配了的长度内,下次再匹配就直接跳过不必要的匹配。因此分为两步:
 *   a> 根据匹配字符串,计算next数组,数组为最长前缀和后缀
 *      对于每一个循环i:
 *      如果needle[i]和needle[half]相同,则表示前后缀可延长,所以half变成half+1;i++求取下一个i
 *      如果needle[i]和needle[half]不同,则先看half是否为0,若为0,则说明为next数组为0;
 *                                                      若不为0,则循环取其最小的half的half,即为next[hlaf-1]
 *   b> 根据next数组,决定当匹配k个长度后,当前滑动为s,则下次滑动为 s'=s+q-next[k]
 *      对于每一个haystack[i]和needle【j】:
 *      如果相同,则继续取下一个i++,j++,直到j取到最后为止(如果j等于长度,则可返回了)
 *      如果不同,则看j是否为0,若为0,则应该看下一个i;
 *                          若不为0,则取一半,即为j=next[j-1];
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
class Solution {
public:
    int strStr(string haystack, string needle) {
        int hayLen = haystack.length(), needLen = needle.length();
        if(!needLen)return 0;
        vector<int> next =countNext(needle);
        for(int i = 0,j = 0; i < hayLen;) {
            if(haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if(j == needLen) return i-j;
            if(i < hayLen && haystack[i] != needle[j]) {
                if(j) j = next[j-1];
                else i++;
            }
        }
        return -1;

    }
private:
    vector<int> countNext(string needle) {
        int len = needle.length();
        vector<int>next(len,0);
        for(int i = 1,half = 0;i < needle.length();) {
            if(needle[i] == needle[half]) {
                next[i++] = ++half;
            }else if(half) {
                half = next[half-1];
            }else {
                next[i++] = 0;
            }
        }
        return next;
    }
};