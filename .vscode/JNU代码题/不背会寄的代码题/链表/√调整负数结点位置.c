//! 顺序表版【18】
// TODO: 对n个算法取实数值的记录序列进行整理，以使所有关键字为负值的记录排序在非负值的记录之前（要求尽量减少记录的交换次数）
void Sort(SqList &L){
    int last = 0; // last记录最后一个连续正整数
    for(int i = 0; i < L.length(); i++){
        if(L.data[i] < 0){
            int temp = L.data[i];
            L.data[i] = L.data[last];
            L.data[last] = temp;
        }
        last++; // 每次交换完记录后，将last自增1
    }
}

//! 链表版【21—848】
//TODO: 设一个带头结点的单链表L，数据元素为整数，其中大部分为正数，少数为负数，编写函数，实现将负数结点移到链表尾部，并返回调整后链表第一个负数结点的位置。要求先给出算法思想，再写出相应的算法
'''思路:
1.找到最后一个结点，用尾指针标记
2.遍历链表，把负数结点尾插到尾指针后【尾指针不动】
3.这样，尾指针下一位就是第一个负数结点
'''
LinkNode* Change(LinkList &L){
    if(L==NULL) return NULL;
    LinkNode *p = L->next, *r = L, *temp;
    // step1: 找到最后一个结点并用r标记
    while(r->next != NULL){
        r = r->next;
    }
    // step2: 遍历链表，把负数结点尾插到r后
    while(p != NULL){
        if(p->data >= 0){
            p = p->next;
        }
        else{
            temp = p->next;
            p->next =r->next;
            r->next = p;
            p = temp;
        }
    }
    // step3: 尾指针下一位就是第一个负数结点
    return r->next;
}
