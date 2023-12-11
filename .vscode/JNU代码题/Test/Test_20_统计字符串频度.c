1.写一个算法统计在输入字符串中各个不同字符出现的频度并将结果存入文件(字符串中的合法字符为A-Z这26个字母与0-9这10个数字)。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//! 定义链表节点
typedef struct Node{
    int freq; // 频度
    char data; // 字符
    struct Node* next; // 下一个节点
}Node;

//! 定义统计频度函数
Node* CountFreq(Node* L, char s){
    Node *p=L;
    //! 遍历链表
    while(p!=NULL){
        //! 如果字符已经在链表中，增加频度
        if(p->data==s){
            p->freq++;
            return L;
        }
        else{
            p=p->next;
        }
    }
    //! 如果字符不在链表中，创建新节点并添加到链表
    if(p==NULL){
        Node* temp=(Node*)malloc(sizeof(Node));
        temp->data=s;
        temp->freq=1;
        temp->next=L;
        L=temp;
    }
    return L;
}

int main(){
    char str[100];
    Node* L = NULL;
    //! 读取输入字符串
    scanf("%s", str);
    //! 遍历字符串的每个字符
    for(int i = 0; i < strlen(str); i++){
        char s = str[i];
        //! 如果字符是合法的（即A-Z或0-9），更新链表
        if((s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9')){
            L = CountFreq(L, s);
        }
    }
    //! 打开文件
    FILE *fp = fopen("output.txt", "w");
    if(fp == NULL){
        printf("Failed to open file\n");
        return -1;
    }
    //! 遍历链表，将结果写入文件
    Node* p = L;
    while(p != NULL){
        fprintf(fp, "%c: %d\n", p->data, p->freq);
        p = p->next;
    }
    //! 关闭文件
    fclose(fp);
    return 0;
}

