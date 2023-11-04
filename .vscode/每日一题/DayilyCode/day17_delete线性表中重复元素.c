// TODO: 在一个递增有序的线性表中，有数值相同的元素存在，若存储方式为单链表，设计算法去掉数值相同的元素，使得表中不再具有重复元素
// TODO: 如(7, 10, 10, 21, 30, 43, 45, 45, 51, 68)将变成(7, 10, 21, 30, 43, 45, 51, 68)
// 算法思想：（双指针法）两个指针p和q，分别指向当前节点和下一个节点。遍历链表，如果当前节点和下一个节点的值相同则删除下一个节点；否则继续后移指针。
// 最终，重复的节点都会被删除，得到的链表中不再具有重复元素。
void RemoveDuplicates_1(LinkList &L) {
    if (L == NULL || L->next == NULL) {
        return; // 空链表或只有一个节点，无需处理
    }
    LNode *p = L->next; // 当前节点指针
    LNode *q = p->next; // 下一个节点指针
    while (q != NULL) {
        if (p->data == q->data) {
            // 删除重复节点
            p->next = q->next;
            free(q);
            q = p->next;
        } else {
            // 不重复，继续后移
            p = p->next;
            q = q->next;
        }
    }
}
// 1007 review: 90/100
void RemoveDuplicates_2(LinkList &L) {
    LNode *pre=L, *p=L->next, *r=p->next;
    while(r!=null){
        if(p->data==r->data){
            pre->next=r;
            free(p);
            p=r;
            r=p->next;
        }
        else{
            pre=p;
            p=r;
            r=p->next;
        }
    }
}