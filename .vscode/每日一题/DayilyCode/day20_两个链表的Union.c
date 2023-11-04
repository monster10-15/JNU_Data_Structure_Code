// TODO: 已知两个链表AB，分别表示两个集合，其元素递增有序排列。编写函数求AB交集，并存放于A链表之中。
// 算法思想: AB一一比较，相同的A保留，B删除；不相同的，删去。当其中一条链走到尽头，比较结束。只需把未比较的结点删除即可
LinkList Union_1(LinkList& A, LinkList& B){
    LNode *pa=A->next, *pb=B->next, *temp;
    LNode *prev = A; // 用于记录A链表中当前节点的前一个节点
    while(pa!=NULL && pb!=NULL){
        if(pa->data==pb->data){
            prev->next = pa;
            prev = pa;
            pa = pa->next;
            temp = pb;
            pb = pb->next;
            free(temp);
        }
        else if(pa->data > pb->data){
            temp = pb;
            pb = pb->next;
            free(temp);
        }
        else{
            temp = pa;
            pa = pa->next;
            free(temp);
        }
    }
    while(pa!=NULL){
        temp = pa;
        pa = pa->next;
        free(temp);
    }
    while(pb!=NULL){
        temp = pb;
        pb = pb->next;
        free(temp);
    }
    prev->next = NULL; // 将A链表中未比较的节点删除
    return A;
}
// 1007 review: 60/100
LinkList Union_2(LinkList& A, LinkList& B){
    LNode *pa=A->next, *pb=B->next, *temp;
    LNode *prev = A; // 用于记录A链表中当前节点的前一个节点
    while(pa!=NULL && pb!=NULL){
        if(pa->data==pb->data){
            prev->next = pa;
            prev = pa;
            pa = pa->next;
            temp = pb;
            pb = pb->next;
            free(temp);
        }
        else if(pa->data > pb->data){
            temp = pb;
            pb = pb->next;
            free(temp);
        }
        else{
            temp = pa;
            pa = pa->next;
            free(temp);
        }
    }
    while(pa!=NULL){
        temp = pa;
        pa = pa->next;
        free(temp);
    }
    while(pb!=NULL){
        temp = pb;
        pb = pb->next;
        free(temp);
    }
    prev->next = NULL; // 将A链表中未比较的节点删除
    return A;
}
// 1009 review: 70/100
LinkList Union_3(LinkList& A, LinkList& B){
    LNode *pa=A->next, *pb=B->next, *pre=A;
    LNode *temp=(*LinkLNode)malloc(sizeof(LNode));
    while(pa!=null && pb!=null){
        if(pa->data>pb->data){
            temp=pb;
            pb=pb->next;
            free(temp);
        }
        else if(pb->data>pa->data){
            temp=pa;
            pa=pa->next;
            pre=pre->next;
            free(temp);
        }
        else if(pb->data==pa->data){
            pre->next=pa;
            pre=pa;
            pa=pa->next;
            temp=pb;
            pb=pb->next;
            free(temp);
        }
    }
    while(pa!=NULL){
        temp=pa;
        pre->next=pa->next;
        pa=pa->next;
        free(temp);
    }
    while(pb!=NULL){
        temp=pb;
        pb=pb->next;
        free(temp);
    }
    pre->next=NULL;
    return A;
}