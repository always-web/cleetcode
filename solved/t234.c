//
// Created by hwddr on 2019/10/29.
//
//请判断一个链表是否为回文链表。
//
// 示例 1:
//
// 输入: 1->2
//输出: false
//
// 示例 2:
//
// 输入: 1->2->2->1
//输出: true
//
//
// 进阶：
//你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
// Related Topics 链表 双指针


#include "../common/LinkedList.h"

//leetcode submit region begin(Prohibit modification and deletion)
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


bool isPalindrome(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return true;
    }
    if (head->next->next == NULL) {
        //此时链表只有2个元素
        return head->val == head->next->val;
    }
    //快指针
    Node fast = head;
    //慢指针
    Node slow = head;
    //临时指针,用于慢指针倒转指针
    Node temp = head;
    //用于记录慢指针的下一个指针
    Node sn = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        if (sn == head) {
            slow = slow->next;
            head->next = NULL;
        }else{
            slow = sn;
        }
        sn = slow->next;
        slow->next = temp;
        temp = slow;
    }
    /*
     *此时,如果 fast 指针后还有一个元素,那么 slow 指针处于中间两个元素的前面一个;
     * 如果 fast 指针后没有元素,那么 slow 指针处于正中间的指针
     */
    //队列长度是否奇数
    bool oddNumber = true;
    if (fast->next != NULL) {
        oddNumber = false;
        bool b = slow->val == slow->next->val;
        if (!b) {
            //中间两个元素不相等,那肯定不是回文
            return false;
        }
        fast = slow->next;
    }else{
        fast = sn;
    }
    if (oddNumber) {
        slow = slow->next;
        bool b = slow->val == fast->val;
        if (!b) {
            return false;
        }
    }
    while (fast->next != NULL) {
        bool b = fast->next->val == slow->next->val;
        if (!b) {
            return false;
        }
        fast = fast->next;
        slow = slow->next;
    }
    return true;
}

bool isPalindrome1(struct ListNode* head){
    if (!head) {
        return true;
    }
    int count = 0;
    Node cur = head;
    while (cur) {
        count++;
        cur = cur->next;
    }
    bool evil = count % 2 == 0;
    int middle = count / 2;
    int arr[count];
    cur = head;
    count = 0;
    while (cur) {
        arr[count++] = cur->val;
        cur = cur->next;
    }
    for (int i = 0; i <= (evil ? (middle - 1) : middle); ++i) {
        if (arr[i] != arr[count - 1 - i]) {
            return false;
        }
    }
    return true;
}

//leetcode submit region end(Prohibit modification and deletion)



int main(void){
    Node node = createLinkedList();
    show(node);
    bool result = isPalindrome(node);
    printf("链表是否回文: %d\n", result);
    return 0;
}