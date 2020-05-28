//
// Created by hwddhome on 2020/5/27.
//

#ifndef CLEETCODE_LINKEDLIST_H
#define CLEETCODE_LINKEDLIST_H

#include <stdio.h>
#include <stdio.h>

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

void printLinkedList(Node head) {
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
