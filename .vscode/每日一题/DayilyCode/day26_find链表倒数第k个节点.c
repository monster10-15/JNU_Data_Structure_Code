// TODO: 已知一个带有头结点的单链表，假设该单链表只给出头指针list,在不改变链表的前提下，查找链表中倒数第k个位置的结点并输出data域的值
// 算法思想: 定义两个指针指向头结点的下一结点，p先后移k个位置，然后pq一起后移，这样pq之间一直都是间隔k个元素。直到p后移到链表的尾结点。
// TODO: 间隔一定，同步后移
int Search_K_1(LinkList list, int K){
    LNode *p = List->next, *q=List->next;
    int count = 0;
    while(p!=null){
        if(count<K) count++;
        else  q=q->next;
        p=p->next;
        if(count<K) return 0;
        else{             
            printf(“%d”,q->data);
        }
    }
}
// 1012 review: 90/100
int Search_K_2(LinkList L, int K){
    LNode *p = L->next, *q = L->next;
    int count = K;
    while (q != nullptr && count > 0) {
        q = q->next;
        count--;
    }
    while (p != nullptr && q != nullptr) {
        p = p->next;
        q = q->next;
    }
    if (p == nullptr) {
        // 链表长度小于K
        return -1;
    }
    return p->data;
}