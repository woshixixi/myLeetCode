/**
 * 蛋疼的一题
 * 两种思路,最简单的 递归 ;其次 按部就班
 *
 * 1 按部就班来说: 【不要忘了为空的情况】
 *  a>自己的方法,不能理解为什么超时了
 *  b>别人的方法,几点巧妙:
 *      1 对待head节点上,先写死某点,然后利用tail,将其指向最开始的头
 *      2 对待链表合并上面,使用tail->next 和tail = tail->next 从而合并了。****
 * 2 递归
 *
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//自己超时的方法
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode * head = l1->val <l2->val ? l1 : l2;
        ListNode * tail;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return head;
    }
};

//巧妙的方法
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

//递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }else {
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};