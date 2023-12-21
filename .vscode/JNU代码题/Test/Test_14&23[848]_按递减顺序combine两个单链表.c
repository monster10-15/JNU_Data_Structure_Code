// TODO: 假设有两个按元素递增次序排列的线性表，均以单链表的形式存储，请将这俩单链表归并为一个按元素递减次序排列的单链表。
// TODO: 并要求利用原本两个单链表的结点存放归并后的单链表。
// 算法思想: AB分别设置指针p,q,依次比较p的值和q的值，将较小的头插进合并链表中，直到其中一条为空，就把剩下的链表结点依次头插即可
// 删除重复节点
LinkList Merge_1(LinkList& A, LinkList& B) {
    LNode* p = A->next, * q = B->next, * r;
    A->next = NULL;
    LNode* head = A;
    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            r = p->next;
            p->next = head->next;
            head->next = p;
            p = r;
        } else {
            r = q->next;
            q->next = head->next;
            head->next = q;
            q = r;
        }
    }
    while (p != NULL) {
        r = p->next;
        p->next = head->next;
        head->next = p;
        p = r;
    }
    while (q != NULL) {
        r = q->next;
        q->next = head->next;
        head->next = q;
        q = r;
    }
    return A;
}
// 1007 review 80/100
LinkList Merge_2(LinkList& A, LinkList& B) {
    LNode *pa = A->next, *pb = B->next;
    LNode *temp;
    while (pa != NULL && pb != NULL) {
        if (pa->data < pb->data) {
            // 头插法插入pa节点
            temp = pa->next;
            pa->next = A->next;
            A->next = pa;
            pa = temp;
        } else {
            // 头插法插入pb节点
            temp = pb->next;
            pb->next = A->next;
            A->next = pb;
            pb = temp;
        }
    }
    // 将剩余的节点插入到A链表中
    while (pa != NULL) {
        temp = pa->next;
        pa->next = A->next;
        A->next = pa;
        pa = temp;
    }
    while (pb != NULL) {
        temp = pb->next;
        pb->next = A->next;
        A->next = pb;
        pb = temp;
    }
    // 返回合并后的链表A
    return A;
}