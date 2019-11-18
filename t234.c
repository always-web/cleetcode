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


struct ListNode {
    int val;
    struct ListNode *next;
};

//leetcode submit region begin(Prohibit modification and deletion)
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode *Node;

bool isPalindrome(struct ListNode* head){
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

Node createLinkedList() {
    int n;
    puts("请输入列表的长度");
    scanf("%d", &n);
    Node head = (Node) malloc(sizeof(Node));
    Node tail = (Node) malloc(sizeof(Node));
    for (int i = 0; i < n; ++i) {
        int data;
        printf("请输入列表第%d项值\n", i);
        scanf("%d", &data);
        Node node = (Node) malloc(sizeof(Node));
        node->val = data;
        if (i == 0) {
            head = node;
            tail = node;
            continue;
        }
        tail->next = node;
        tail = node;
    }
    return head;
}

void show(Node pNode) {
    if (pNode == NULL) {
        return;
    }
    Node head = pNode;
    while (head) {
        if (head->next) {
            printf("%d->", head->val);
        }else{
            printf("%d\n", head->val);
        }
        head = head->next;
    }
}

int main(void){
    Node node = createLinkedList();
    show(node);
    bool result = isPalindrome(node);
    printf("链表是否回文: %d\n", result);
    return 0;
}