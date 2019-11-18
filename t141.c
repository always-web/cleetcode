//给定一个链表，判断链表中是否有环。
//
// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
//
//
//
// 示例 1：
//
// 输入：head = [3,2,0,-4], pos = 1
//输出：true
//解释：链表中有一个环，其尾部连接到第二个节点。
//
//
//
//
// 示例 2：
//
// 输入：head = [1,2], pos = 0
//输出：true
//解释：链表中有一个环，其尾部连接到第一个节点。
//
//
//
//
// 示例 3：
//
// 输入：head = [1], pos = -1
//输出：false
//解释：链表中没有环。
//
//
//
//
// //
// Created by hwddr on 2019/11/18.
//


//
// 进阶：
//
// 你能用 O(1)（即，常量）内存解决此问题吗？
// Related Topics 链表 双指针

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 typedef struct ListNode *Node;
bool hasCycle(struct ListNode *head) {
    if (head == NULL) {
        return false;
    }
    if (head->next == NULL) {
        return false;
    }
    Node f = head;
    Node s = head->next;
    if (s == f) {
        return true;
    }
    //排除 a->a
    if (s->next == NULL) {
        return false;
    }
    s = s->next;
    if (s == f) {
        return true;
    }
    //排除 a->b->a
    s = s->next;
    while (s != NULL) {
        f = f->next;
        if (f == s) {
            return true;
        }
        if (s->next != NULL && s->next == f) {
            return true;
        }
        s = s->next;
    }
    return false;
}
//leetcode submit region end(Prohibit modification and deletion)
int main(void){
    int *a = (int *) malloc(sizeof(int));
    int *b = a;
    printf("%d", a == b);
    return 0;
}

