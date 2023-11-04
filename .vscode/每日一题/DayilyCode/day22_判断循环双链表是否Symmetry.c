// TODO: 设计一个算法判断带头结点的循环双链表是否对称
// 算法思想: 让p从左往右扫描,让q从右往左扫描,直到他们指向同一结点(偶)或相邻(奇),否则返回0
int Symmetry_1(DLink L){
    DNode *p = L->next, *q = L->prior;
    while(p != q && q->next != p){
        if(p->data != q->data){
            return 0;
        }
        p = p->next;
        q = q->prior;
    }
    return 1;
}
// 1009 review 70/100
int Symmetry_2(DLink L){
    LNode*p=L->next, *q=L->prior;
    while(p!=q  && q->next != p){
        if(p->data!=q->data){
            return 0;
        }
        p=p->next;
        q=q->prior;
    }
    return 1;
}
// 1010 review 80/100
int Symmetry_3(DLink L){
    DNode *p = L->next, *q = L->prior;
    while(p != q && q->next != p){
        if(p->data != q->data){
            return 0;
        }
        p=p->next;
        q=q->prior;
    }
    return 1;
}