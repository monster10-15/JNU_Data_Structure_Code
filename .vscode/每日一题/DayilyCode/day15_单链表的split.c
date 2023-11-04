//TODO: 将一个带头结点的单链表A分解为两个带头结点的单链表A和B，使得A表中含有原表中序号为奇数的元素，而表B中含有原表中序号为偶数的元素，且保持其相对顺序不变
// 算法思想: 不断使用尾插法依次生成链表AB
LinkList Split_1(LinkList &A){
    int i = 0;
    LinkList B = (LinkList)malloc(sizeof(LNode));
    LNode *p = A->next, *ra = A, *rb = B;
    B->next = null;
    while(p != null){
        if(i % 2 == 0){
            rb->next = p;
            rb = p;
        }
        else{
            ra->next = p;
            ra = p;
        }
        p = p->next;
        i++;
    }
    ra->next = null;
    rb->next = null;
    return B;
}
// 1006 review: 50/100
LinkList Split_1(LinkList &A){
    int i=1;
    LinkList B=(LinkList)malloc(sizeof(LinkLNode));
    LNode *p=A->next,*ra=A; *rb=B;
    B->next=null;
    while(p->next != null){
        if(i%2!=0){
            ra->next=p;
            ra=p;
        }
        else{
            rb->next=p;
            rb=p;
        }
        p=p->next;
        i++;
    }
    ra->next=null;
    rb->next=null;
    return B;
}