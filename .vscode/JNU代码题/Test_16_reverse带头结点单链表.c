// TODO: 编写算法将带头结点的单链表就地逆置（空间复杂度为O(1)）
// 算法思想: 
// 法①: 头插法实现逆置，需定义遍历指针p和r(记录p的后续防止断链)。把p提出来，插足到L和L->next之间，循环往复这个过程
LinkList Reverse_1_1(LinkList &L){
    LNode *p=L->next, *r;
    L->next = null; //把L头结点置空相当于把头结点提取出来，然后再对L进行逆置...
    while(p!=null){
        r=p->next;
        p->next = L->next;
        L->next= p;
        p = r;
    }
    return L;
}
// 法②: 后继变前驱（后面的人一直插p的队）:把pre（队长）提出来，p后面的人一直插到p前面，然后再整体后退一位
LinkList Reverse_1_2(LinkList &L){
    LNode *pre = L->next, *p = pre->next; *r = p->next;
    pre->next = NULL;
    while(r!=NULL){
        p->next = pre;
        pre = p;
        p = r;
        r = r->next;
    }
    p->next = pre;
    L->next = p;
    return L;
}
// 0930 review:0/0
LinkList Reverse_2_1(LinkList &L){
    LNode *p=L->next, *r;
    L->next = NULL;
    while(p!= NULL){
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
    return L;
}
LinkList Reverse_2_2(LinkList &L){
    LNode *pre = L->next, *p = pre->next, *r = p->next;
    pre->next = null;
    while(r!= NULL){
        p->next = pre;
        pre = p;
        p = r;
        r = r->next;
    }
    p->next = pre;
    L->next = p;
    return L;
}
// 1001 review:0/0
LinkList Reverse_3_1(LinkList &L){
    LNode *p=L->next, *r;
    L->next = null;
    // 把p提出来，插足到L和L->next之间，循环往复这个过程
    while(p!= null){
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
    return L;
}
LinkList Reverse_3_2(LinkList &L){
    LNode *pre=L, *p=L->next, *r=p->next;
    //原本指向后继的，现在指向前驱，然后再整体平移一位
    while(p!= null){
        p->next=pre;
        pre=pre->next;
        p=r;
        r=p->next;
    }
}
// 1002 review:70/100
LinkList Reverse_4_1(LinkList &L){
    LNode*p=L->next, *r;
    L->next=null;
    while(p!=null){
        r=p->next;
        p->next = L->next;
        L->next = p;
        p=r;
    }
    return L;
}
LinkList Reverse_4_2(LinkList &L){
    LNode *pre=L->next, *p=pre->next, *r=p->next;
    pre->next=null;
    while(r!=null){
        p->next=pre;
        pre=p;
        p=r;
        r=r->next;
    }
    return L;
}
// 1003 review: 60/100
LinkList Reverse_5_1(LinkList &L){
    LNode*p=L->next, *r;
    L->next=null;
    while(p!=NULL){
        r=p->next;
        p->next=null;
        p->next=L->next;
        L->next=p->next;
        p=r;
    }
    retur L;
}
LinkList Reverse_5_2(LinkList &L){
    LNode*pre=L, *p=pre->next, *r=p->next;
    pre->next=null;
    while(r!=NULL){
        p->next=pre;
        pre=p;
        p=r;
        r=p->next;
    }
    return L;
}
// 1004 review: 80/100
LinkList Reverse_6_1(LinkList &L){
    LNode*p=L->next, *r;
    L->next=null;
    while(p!=null){
        r=p->next;
        p->next=L->next;
        L->next=p;
        p=r;
    }
    return L;
}
LinkList Reverse_6_2(LinkList &L){
    LNode*pre=L, *p=pre->next, *r=p->next;
    while(r!=null){ 
        p->next=pre;
        pre=p;
        p=r;
        r=p->next; 
    }
    return L;
}
// 1005 review: 90/100
LinkList Reverse_7_1(LinkList &L){
    LNode*p=L->next, *r;
    L->next=null;
    while(p!=null){
        r=p->next;
        p->next=L->next;
        L->next=p;
        p=r;
    }
    return L;
}
LinkList Reverse_7_2(LinkList &L){
    LNode *pre=L, *p=pre->next, *r=p->next;
    pre->next=null;
    while(r!=null){
        p->next=pre;
        pre=p;
        p=r;
        r=p->next;
    }
    return L;
}