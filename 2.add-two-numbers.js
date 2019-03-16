/*
 * @lc app=leetcode id=2 lang=javascript
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (30.69%)
 * Total Accepted:    788.5K
 * Total Submissions: 2.6M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Example:
 *
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 *
 *
 */
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
  let node = new ListNode(0)
  let head = node
  let sum = 0
  while (l1 != null || l2 != null) {
    sum = node.val
    if (l1 !== null) {
      sum = l1.val + sum
      l1 = l1.next
    }
    if (l2 !== null) {
      sum = l2.val + sum
      l2 = l2.next
    }

    if (sum >= 10) {
      node.val = sum - 10
      node.next = new ListNode(1)
    } else if (l1 === null && l2 === null) {
      node.val = sum
      node.next = null
    } else {
      node.val = sum
      node.next = new ListNode(0)
    }
    node = node.next
  }

  return head
}
