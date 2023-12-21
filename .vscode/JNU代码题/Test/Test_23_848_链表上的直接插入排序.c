void straightforwardSort(LinkList L){
    LinkList *p, *pre, *q; // 定义三个指针，p用于遍历链表，pre用于找到插入位置的前一个节点，q用于保存p的下一个节点
    p=L->next->next; // 从第二个节点开始排序，因为单个节点可以看作已排序
    L->next->next = NULL; // 将第一个节点独立出来，作为已排序部分
    while(p!=NULL){ // 遍历未排序部分
        q=p->next; // 保存p的下一个节点
        pre=L; // 从头开始找插入位置
        while(pre->next!=NULL && pre->next->data < p->data){ // 如果后面的结点都大于p
            pre=pre->next; // 就继续遍历【因为要找到比p小的结点和p对换】
        }
        // 找到了！！！接着把这俩互换，这样就能维持前面的小后面的大【顺序递增】了
        p->next = pre->next; 
        pre->next = p;
        p=q; // p从q点继续出发（￣︶￣）↗　
    }
}