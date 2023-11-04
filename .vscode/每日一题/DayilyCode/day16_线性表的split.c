// TODO: 设C={a1,b1,a2,b2,...,an,bn}为线性表，采用带头结点的hc单链表存放，设计一个就地算法，
// TODO: 将其拆分为两个线性表，使得A={a1,a2,...an},B={bn,bn-1,...b1}
// 算法思想: 遍历C链表，将一个头结点尾插在A，第二个结点头插在B，下一个结点尾插A，再下一个结点头插B，如此循环往复直至将C完全分解
LinkList Split(LinkList &C) {
    LinkList A = (LinkList)malloc(sizeof(LNode)); // 创建A链表的头结点
    LinkList B = (LinkList)malloc(sizeof(LNode)); // 创建B链表的头结点
    A->next = NULL, B->next = NULL;
    LNode *ra = A; // A链表的尾指针
    LNode *rb = B; // B链表的尾指针
    LNode *p = C->next; // 遍历指针
    int count = 0; // 记录当前遍历到的位置
    while (p != NULL) {
        if (count % 2 == 0) { // 偶数位置，尾插入A链表，防断链
            ra->next = p;
            ra = p;
        } else { // 奇数位置，头插入B链表，留尾针
            LNode *temp = p->next; // 保存下一个节点
            p->next = rb->next;
            rb->next = p;
            p = temp;
        }
        count++;
        p = p->next;
    }
    ra->next = NULL; // A链表的尾节点指向NULL
    return A, B;
}