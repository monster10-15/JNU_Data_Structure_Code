// TODO: 有两个循环单链表，链表头指针分别为h1和h2,编写一个函数将链表h2链接到链表h1后，要求链接后的链表仍然保持着循环链表的形式
// 找到h1的表尾p，h2的表尾q，将p指向h2，q指向h1，重成一条循环单链表
LinkList connect_1(LinkList& h1, LinkList& h2){
    LNode *p = h1, *q = h2;
    while(p->next != h1){
        p = p->next;
    }
    while(q->next != h2){
        q = q->next;
    }
    p->next = h2;
    q->next = h1;
    return h1;
}
// 1010 review: 60/100
LinkList connect_2(LinkList& A, LinkList& B){
    LNode *pa=A, *pb=B;
    while(pa->next!=A){
        pa=pa->next;
    }
    while(pb->next!=B){
        pb=pb->next;
    }
    pa->next = B;
    pb->next = A;
    return A;
}
// 1011 review: 100/100
LinkList connect_3(LinkList& A, LinkList& B){
    LNode *pa=A, *pb=B;
    while(pa->next!=A){
        pa=pa->next;
    }
    while(pb->next!=B){
        pb=pb->next;
    }
    pa->next =B;
    pb->next =A;
    return A;
}