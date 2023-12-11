// TODO: 试编写带头结点的单链表L中删除一个最小值结点的高效算法（假设最小值唯一）
// 算法思想：指针p遍历链表，min_p用于标记最小值。p_pre指向p的前驱，min_pre指向min_p的前驱。
// 扫描过程中，若p->data < min_p->data, 则将p和pre分别赋值给min_p和min_pre。
// 扫描完毕之后，此时minp指向最小值结点，min_pre指向最小值结点的前驱。然后将min_p删除即可。
LinkList Delete_min_1(LinkList &L){
    LNode *pre=L, *p=pre->next, *min_pre=pre, *min_p=p;
    while(p!=NULL){
        if (p->data < min_p->data){
            min_p = p;
            min_pre = pre;
        }
        pre = p;
        p = p->next;
    }
    min_pre->next = min_p->next;
    free(min_p);
    return L;
}
//0926review 100/100
LinkList Delete_min_2(LinkList &L){
    LNode *pre=L, *p=pre->next, *min_pre=L, *min_p = min_pre->next;
    while(p!=null){
        if(p->data < min_p->data){
            min_p=p;
            min_pre = pre;
            p ++;
            pre ++;
        }
        min_pre = min_p->next;
        free(min_p);
    }
    return L;
}