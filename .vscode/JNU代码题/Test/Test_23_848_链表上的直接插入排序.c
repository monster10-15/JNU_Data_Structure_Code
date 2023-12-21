void straightforwardSort(LinkList L){
    LinkList *p, *pre, *q; // 定义三个指针，p用于遍历链表，pre用于找到插入位置的前一个节点，q用于保存p的下一个节点
    p=L->next->next; // 从第二个节点开始排序，因为单个节点可以看作已排序
    L->next->next = NULL; // 将第一个节点独立出来，作为已排序部分
    while(p!=NULL){ // 遍历未排序部分
        q=p->next; // 保存p的下一个节点
        pre=L; // 从头开始找插入位置
        while(pre->next!=NULL && pre->next->data < p->data){ // 找到第一个大于p的节点
            pre=pre->next; // 更新pre
        }
        p->next = pre->next; // 插入p
        pre->next = p;
        p=q; // p指向下一个待排序节点
    }
}
