//TODO: 设一个带头结点的单链表中所有元素的结点的数据值无序，试着编写一个函数，删除表中所有介于给定的两个值（作为函数参数给出）之间的元素（若存在）
算法思想: 遍历链表，删除在最小值和最大值之间的元素
LinkList Delete_F_T_1(LinkList &L, int min, int max){
    LNode *pre=L, *p=L->next;
    while(p!=NULL){
        if(p->data>min&&p->data<max){
            p->next=pre->next;
            free(p);
            p=pre->next;
        }
        else{
            pre=p;
            p=p->next;
        }
    }
    return L;
}
// 1003 review:100/100
LinkList Delete_F_T_2(LinkList &L, int min, int max){
    LNode*pre=L, *p=L->next;
    while(p!=null){
        if(p->data>min&&p->data<max){
            pre->next=p->next;
            free(p);
        }
        else{
            pre=p;
            p=p->next;
        }
    }
    return L;
}