#include <iostream>
#include <vector>
using namespace std;

vector<int> countNext(string &needle) {
    int len = needle.length();
    vector<int>next(len,0);
    for(int i = 1,half = 0;i < len;) {
        if(needle[i] == needle[half]) {
//            next[i++] = ++half;
            next[i] = half+1;
            half =half+1;
            i++;
        }else if(half) {
            half = next[half-1];
        }else {
            next[i++] = 0;
        }
    }
    return next;
}
//private:
//vector<int> kmpProcess(string& needle) {
//    int n = needle.length();
//    vector<int> lps(n, 0);
//    for (int i = 1, len = 0; i < n; ) {
//        if (needle[i] == needle[len])
//            lps[i++] = ++len;
//        else if (len) len = lps[len - 1];
//        else lps[i++] = 0;
//    }
//    return lps;
//}
//};

int strStr(string haystack, string needle) {
    int hayLen = haystack.length(), needLen = needle.length();
    vector<int> next =countNext(needle);
    int i = 0,j = 0;
    for(;i < haystack.length();) {
        for(;j < needLen;j++) {
            if(haystack[i] != needle[j]) {
                break;
            }
        }
        if(j == needLen) return i;
        i = i + j - next[j];
        j = next[j];
    }
    return -1;
}

int main() {
    string a = "abcdabcabkabcabc";
    string b = "issip";
    vector<int> next = countNext(b);
    for(int i = 0;i<next.size();i++) {
        cout<<next[i]<<"*"<<endl;
    }
    strStr(a,b);
    return 0;
}