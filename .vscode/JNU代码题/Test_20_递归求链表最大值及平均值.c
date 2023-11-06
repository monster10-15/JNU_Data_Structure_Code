已知f为单链表的表头指针，链表中存储的都是整型数据，请写出实现下列运算的递归算法，求(1)链表中最大整数;(2)所有整数的平均值。
// 定义链表节点
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data; // 数据
    struct Node* next; // 下一个节点
}Node;

// 定义求最大值的函数
int Max(Node* f){
    if(f == NULL){
        return -1; // 空链表，返回-1
    }
    else{
        int max_next = Max(f->next); // 递归求解子链表的最大值
        return f->data > max_next ? f->data : max_next; // 返回当前节点和子链表最大值中的较大者
    }
}

// 定义求总和的函数
int Sum(Node* f){
    if(f == NULL){
        return 0; // 空链表，返回0
    }
    else{
        return f->data + Sum(f->next); // 返回当前节点的数据和子链表的总和
    }
}

// 定义求长度的函数
int Length(Node* f){
    if(f == NULL){
        return 0; // 空链表，返回0
    }
    else{
        return 1 + Length(f->next); // 返回1加上子链表的长度
    }
}
int main(){
    // 创建链表并初始化
    Node* L = (Node*)malloc(sizeof(Node));
    L->data = 1;
    L->next = (Node*)malloc(sizeof(Node));
    L->next->data = 2;
    L->next->next = (Node*)malloc(sizeof(Node));
    L->next->next->data = 3;
    L->next->next->next = NULL;

    // 计算最大值、总和和长度
    int max = Max(L);
    int sum = Sum(L);
    int len = Length(L);

    // 计算平均值
    double average = len > 0 ? (double)sum / len : 0;

    // 打印结果
    printf("Max: %d\n", max);
    printf("Average: %.2f\n", average);

    return 0;
}