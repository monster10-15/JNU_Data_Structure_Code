// TODO: 假设有两个按元素递增次序排列的线性表，均以单链表的形式存储，请将这俩单链表归并为一个按元素递减次序排列的单链表。
// TODO: 并要求利用原本两个单链表的结点存放归并后的单链表。
// 算法思想: AB分别设置遍历指针pa,pb,依次比较pa的值和pb的值，将较小的头插进合并链表中，【A为合并链表】
// 直到其中一条为空，就把剩下的链表结点依次头插即可

LinkList Merge(LinkList& A, LinkList& B) {
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