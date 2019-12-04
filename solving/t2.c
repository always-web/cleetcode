//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
//
// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//
// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//
// 示例：
//
// 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807
//
// Related Topics 链表 数学


#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
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

Node initQueue(int val){
    Node head = (Node) calloc(1,sizeof(struct ListNode));
    head->val = val;
    head->next = NULL;
    return head;
}

void addQueue(Node head,int val){
    Node node = (Node) malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    Node temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

void handle(bool shouldAddOne, Node node, struct ListNode *result) {
    while (node != NULL) {
        int total = node->val;
        if (shouldAddOne) {
            total = node->val + 1;
            if (total >= 10) {
                total = 0;
            }else{
                shouldAddOne = false;
            }
        }
        addQueue(result, total);
        node = node->next;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    bool shouldAddOne = false;
    Node a = l1;
    Node b = l2;
    Node result = NULL;
    while (a != NULL && b != NULL) {
        int total = a->val + b->val;
        if (shouldAddOne) {
            total += 1;
            shouldAddOne = false;
        }
        if (total >= 10) {
            shouldAddOne = true;
            total = total % 10;
        }
        if (!result) {
            result = initQueue(total);
        } else {
            addQueue(result, total);
        }

        a = a->next;
        b = b->next;
    }
    if (a == NULL && b == NULL) {
        if (shouldAddOne) {
            addQueue(result, 1);
        }
        return result;
    }
    if (a == NULL) {
        handle(shouldAddOne, b, result);
        return result;
    }
    handle(shouldAddOne, a, result);
    return result;
}


Node ggg(const int pInt[], int i) {
    Node node = (Node) malloc(sizeof(Node));
    node->val = pInt[0];
    node->next = NULL;
    Node temp = node;
    for (int j = 1; j < i; ++j) {
        Node next = (Node) malloc(sizeof(Node));
        next->val = pInt[j];
        temp->next = next;
        temp = next;
    }
    return node;
}

void show(Node pNode) {
    Node head = pNode;
    while (head) {
        printf("%d ->", head->val);
        head = head->next;
    }
}

int main(void){
    int a[3] = {2,4,3};
    int b[3] = {5, 6, 4};
    Node pa = ggg(a, 3);
    Node pb = ggg(b, 3);
    Node pc = addTwoNumbers(pa, pb);
    show(pc);
    return 0;
}




//leetcode submit region end(Prohibit modification and deletion)
