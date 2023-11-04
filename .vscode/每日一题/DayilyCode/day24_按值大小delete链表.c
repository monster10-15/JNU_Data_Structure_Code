//TODO:设有一个带头结点的循环单链表，其结点值均为正整数，设计一个算法，反复找出单链表中的结点值最小的结点并输出。
// 然后将该结点删除。直到单链表为空为止，再删除表头结点。
// 算法思想: 反复寻找当前的最小值结点并删除，直到L为空，释放头结点
void Delete_all_1(LinkList &L){
    LNode *p, *pre, *minp, *minpre;
    while(L->next != L){
        p = L->next, pre = L, minp = p, minpre = pre;
        while(p != L){
            if(p->data < minp->data){
                minp = p;
                minpre = pre;
            }
            pre = p;
            p = p->next;
        }
        printf("The min_value is: %d", minp->data);
        minpre->next = minp->next;
        free(minp);
    }
    free(L);
}
// 1010 reveiw: 50/100
void Delete_all_2(LinkList &L){
    while(L->next!=L){
        LNode *p=L->next, pre=L, *min=L->next, *minpre=L;
        while(p!=L){
            if(p->data < min->data){
                minpre = pre;
                min = p;
            }
            pre=pre->next;
            p = p->next;
        }
        printf("the min_value is %d\n", min->data);
        minpre->next=min->next;
        free(min);
    }
}
// 1011 review: 100/100
void Delete_all_3(LinkList &L){
    while(L!->next=L){
        LNode *pre=L,*p=L->next, *minpre=pre, *min=p;
        while(p!=L){
            if(p->data<min->data){
                min=p;
                minpre=pre;
            }
            else{
                pre=p;
                p=p->next;
            }
            printf("min=%d", min->data;)
            LNode *temp = min;
            minpre->next=min->next;
            min=temp->next;
            free(temp);
        }
    }
    free(L);

}