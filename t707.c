//设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next
// 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是
// 0-index 的。
//
// 在链表类中实现这些功能：
//
//
// get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
// addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
// addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
// addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val 的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
// deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
//
//
//
//
// 示例：
//
// MyLinkedList linkedList = new MyLinkedList();
//linkedList.addAtHead(1);
//linkedList.addAtTail(3);
//linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
//linkedList.get(1);            //返回2
//linkedList.deleteAtIndex(1);  //现在链表是1-> 3
//linkedList.get(1);            //返回3
//
//
//
//
// 提示：
//
//
// 所有val值都在 [1, 1000] 之内。
// 操作次数将在 [1, 1000] 之内。
// 请不要使用内置的 LinkedList 库。
//
// Related Topics 设计 链表



//leetcode submit region begin(Prohibit modification and deletion)
#include <stdlib.h>
#include <stdio.h>

struct node;
typedef struct node *Node;
struct node {
    int val;
    Node next;
};

typedef struct {
    Node head;
    int total;
} MyLinkedList;

/** Initialize your data structure here. */

void outOfSpaceError(const struct node *newNode) {
    if (newNode == NULL) {
        printf("out of space!!!");
        exit(1);
    }
}

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *list = (MyLinkedList *) calloc(1,sizeof(MyLinkedList));
    Node head = (Node)malloc(sizeof(struct node));
    head->next = NULL;
    list->head = head;
    list->total = 0;
    return list;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList *obj, int index) {
    if(index < 0){
        return -1;
    }
    if (index == obj->total && obj->total == 0) {
        return 0;
    }
    if (index == 0) {
        return obj->head->next->val;
    }
    if (index >= obj->total) {
        return -1;
    }
    Node tmpHead = obj->head;
    int step = 0;
    obj->head = obj->head->next;
    while (obj->head){
        if (step == index) {
            int res = obj->head->val;
            obj->head = tmpHead;
            return res;
        }
        step++;
        obj->head = obj->head->next;
    }
    return -1;
}

/** Add a node of value val before the first element of the linked list.
 * After the insertion, the new node will be the first node of the linked list.
 * */
void myLinkedListAddAtHead(MyLinkedList *obj, int val) {
    Node newNode = (Node)malloc(sizeof(struct node));
    outOfSpaceError(newNode);
    newNode->val = val;
    newNode->next = obj->head->next;
    obj->head->next = newNode;
    obj->total++;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node newNode = (Node)malloc(sizeof(struct node));
    outOfSpaceError(newNode);
    newNode->val = val;
    newNode->next = NULL;
    Node tmpHead = obj->head;
    while (obj->head->next != NULL) {
        obj->head = obj->head->next;
    }
    obj->head->next = newNode;
    obj->head = tmpHead;
    obj->total++;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list,
 * the node will be appended to the end of linked list. If index is greater than the length, the node will
 * not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->total) {
        return;
    }
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    if (index == obj->total) {
        myLinkedListAddAtTail(obj, val);
        return;
    }
    int step = 0;
    Node tmpHead = obj->head;
    obj->head = obj->head->next;
    while (step != index - 1) {
        obj->head = obj->head->next;
        step++;
    }
    Node newNode = (Node)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = obj->head->next;
    obj->head->next = newNode;
    obj->head = tmpHead;
    obj->total++;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->total) {
        return;
    }
    if (obj->head->next == NULL) {
        return;
    }
    if (index == 0) {
        Node target = obj->head->next;
        obj->head->next = target->next;
        free(target);
        obj->total--;
        return;
    }
    Node tmpHead = obj->head;
    int step = 0;
    obj->head = obj->head->next;
    while (step != index - 1) {
        obj->head = obj->head->next;
        step++;
    }
    if (index == obj->total - 1) {
        free(obj->head->next);
        obj->head->next = NULL;
        obj->head = tmpHead;
        obj->total--;
        return;
    }
    Node target = obj->head->next;
    obj->head->next = obj->head->next->next;
    free(target);
    obj->head = tmpHead;
    obj->total--;
}

void myLinkedListFree(MyLinkedList* obj) {
    while (obj->head->next != NULL) {
        Node target = obj->head->next;
        obj->head->next = target->next;
        free(target);
        obj->total--;
    }
}

int main(void){
    MyLinkedList *obj = myLinkedListCreate();
    // printf("the value in the index 0 is:   %d\n", myLinkedListGet(obj, 0));
    myLinkedListAddAtHead(obj, 1);
    myLinkedListAddAtIndex(obj, 1, 2);
    printf("the value in the index 1 is:   %d\n", myLinkedListGet(obj, 1));
    printf("the value in the index 0 is:   %d\n", myLinkedListGet(obj, 0));
    printf("the value in the index 2 is:   %d\n", myLinkedListGet(obj, 2));
    myLinkedListFree(obj);
    free(obj);
    return 0;
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/
//leetcode submit region end(Prohibit modification and deletion)
