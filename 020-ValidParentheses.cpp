/**
 * 1 用栈
 * 2 但要更加深入一些,提前排除一些错误直接return false 而不是进栈。以防出现 runtime err
 * 3 这种情况 使用switch case更加方便
 *
 */

//出现runtime err的情况: 无论哪种都会出现,因此进行改进
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i < s.length(); i++) {
            // if((s[i] == ')' && st.top() == '(')||(s[i] == ']' && st.top() == '[')||(s[i] == '}' && st.top() == '{')){
            //     st.pop();
            // }else {
            //     st.push(s[i]);
            // }
            switch (s[i]) {
                case '(':
                case '[':
                case '{': st.push(s[i]); break;
                case ')': if(st.top() == '(') st.pop(); else st.push(s[i]);break;
                case ']': if(st.top() == '[') st.pop(); else st.push(s[i]);break;
                case '}': if(st.top() == '{') st.pop(); else st.push(s[i]);break;
                default: ;
            }
        }
        return st.empty();
    }
};


//改进后的算法:
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i < s.length(); i++) {
            switch (s[i]) {
                case '(':
                case '[':
                case '{': st.push(s[i]); break;
                case ')': if(st.empty()||st.top() != '(') return false; else st.pop();break;
                case ']': if(st.empty()||st.top() != '[') return false; else st.pop();break;
                case '}': if(st.empty()||st.top() != '{') return false; else st.pop();break;
                default: ;
            }
        }
        return st.empty();
    }
};