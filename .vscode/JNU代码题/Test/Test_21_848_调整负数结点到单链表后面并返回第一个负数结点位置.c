//TODO: 设一个带头结点的单链表L，数据元素为整数，其中大部分为正数，少数为负数，编写函数，实现将负数结点移到链表尾部，并返回调整后链表第一个负数结点的位置。要求先给出算法思想，再写出相应的算法
'''思路:
1.找到最后一个结点，用尾指针标记
2.遍历链表，把负数结点尾插到尾指针后，尾指针再右移一位
3.最后从头遍历一次链表，找到第一个负数结点返回即可。
'''
LinkNode* Change(LinkList &L){
    if(L==NULL) return NULL;
    LinkNode *p = L->next, *r = L, *s, *temp;
    // step1: 找到最后一个结点并用r标记
    while(r->next != NULL){
        r = r->next;
    }
    // step2: 遍历链表，把负数结点尾插到r后&更新r
    while(p != NULL){
        if(p->data >= 0){
            p = p->next;
        }
        else{
            temp = p->next;
            p->next = NULL;
            r->next = p;
            r = p;
            p = temp;
        }
    }
    // step3: 最后从头遍历一次链表找到第一个负数结点
    p = L->next;
    while(p != NULL && p->data >= 0){
        p = p->next;
    }
    return p;
}
