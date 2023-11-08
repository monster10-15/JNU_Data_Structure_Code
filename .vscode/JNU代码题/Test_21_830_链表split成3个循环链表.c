#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

// 检查字符是否为字母
int isAlpha(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// 检查字符是否为数字
int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("内存分配失败。\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = newNode;  // 指向自己，创建一个循环列表
    return newNode;
}

void insertEnd(Node** start, char data) {
    Node *newNode = createNode(data);
    if(*start == NULL) {
        *start = newNode;
    } else {
        Node *last = (*start)->next;
        while(last->next != *start) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *start;
    }
}

void splitList(Node* start, Node** alphaStart, Node** digitStart, Node** otherStart) {
    Node* current = start->next;
    do {
        if(isAlpha(current->data)) {
            insertEnd(alphaStart, current->data);
        } else if(isDigit(current->data)) {
            insertEnd(digitStart, current->data);
        } else {
            insertEnd(otherStart, current->data);
        }
        current = current->next;
    } while(current != start->next);
}

void printList(Node* start) {
    Node* ptr = start->next;
    do {
        printf("%c ", ptr->data);
        ptr = ptr->next;
    } while(ptr != start->next);
    printf("\n");
}

int main() {
    Node* start = NULL;
    Node* alphaStart = NULL;
    Node* digitStart = NULL;
    Node* otherStart = NULL;

    // 向列表中添加节点
    insertEnd(&start, 'a');
    insertEnd(&start, '1');
    insertEnd(&start, 'b');
    insertEnd(&start, '2');
    insertEnd(&start, '@');

    // 分割列表
    splitList(start, &alphaStart, &digitStart, &otherStart);

    // 打印列表
    printf("字母列表: ");
    printList(alphaStart);
    printf("数字列表: ");
    printList(digitStart);
    printf("其他列表: ");
    printList(otherStart);

    return 0;
}
