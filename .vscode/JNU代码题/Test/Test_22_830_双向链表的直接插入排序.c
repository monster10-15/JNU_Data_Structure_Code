void sort(DiLNode *&L){
    DiLNode *p, *pre, *q;  // 定义三个指针，p用于遍历链表，pre用于保存p的前驱，q用于保存p的后继
    p = L->next->next;  // p指向链表的第二个节点
    L->next->next = NULL;  // 将链表的第一个节点与其他节点断开，作为已排序的部分
    // 遍历链表的每一个节点
    while (p != NULL){
        q = p->next;  // 保存p的后继节点
        pre = L;  // pre指向头节点
        // 寻找p应该插入的位置
        while (pre->next != NULL && pre->next->data < p->data)
            pre = pre->next;
        // 将p插入到pre和pre的后继节点之间
        p->next = pre->next;
        if (pre->next != NULL)
            pre->next->prior = p;
        pre->next = p;
        p->prior = pre;
        p = q;  // p指向下一个待排序的节点
    }
}
