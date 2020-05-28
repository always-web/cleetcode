//
// Created by hwddhome on 2020/5/27.
//

#ifndef CLEETCODE_LINKEDLIST_H
#define CLEETCODE_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode *Node;


Node generateListNode(const int pInt[], int n) {
    Node result = (Node) malloc(sizeof(Node));
    Node temp = result;
    temp->val = pInt[0];
    for (int i = 1; i < n; ++i) {
        Node next = (Node) malloc(sizeof(Node));
        next->val = pInt[i];
        temp->next = next;
        temp = next;
    }
    return result;
}


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

void toString(Node head) {
    Node temp = head;
    if (temp == NULL) {
        printf("%s\n", "NULL");
        return;
    }
    while (temp != NULL) {
        printf("%d", temp->val);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
}

#endif //CLEETCODE_LINKEDLIST_H
